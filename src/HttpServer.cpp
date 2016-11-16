#include "HttpApplication.h"
#include "HttpServer.h"
#include "HttpResponse.h"
#include "socket.h"
#include "HttpMessage.h"
#include "utils.h"
#include "Logger.h"
#include <string>
#include <map>
#include <iostream>
#include <sys/time.h> //FD_SETSET, FD_ZERO macros
#include <cassert>

#include<pthread.h>


#include <thread>
#include <chrono>

pthread_mutex_t lock;

struct Context{
    HttpServer* server;
    std::shared_ptr<Socket> client;
};

HttpServer::HttpCodesMap HttpServer::StatusCodes = {
    {200, "OK"},
    {404, "Not Found"},
    {405, "Method not allowed"},
    {400, "Bad Request"},
    {500, "Internal Server Error"}
};

HttpServer::HttpServer(HttpApplication app):
		app(app), 
		sock(nullptr)
{}

HttpServer::HttpServer():sock(nullptr)
{}

void HttpServer::bind(int port)
{
	sock = std::unique_ptr<Socket>(new Socket(port));
	sock->bind();

}

void HttpServer::listen(int n)
{
	sock->listen(n);
    max_clients = n+1;
}


void HttpServer::setup_handler(std::shared_ptr<RequestHandler> handler, HttpRequest& req)
{
    handler->initialize();

    req.remote_ip = sock->get_remote_ip();
    req.remote_port = sock->get_remote_port();

    handler->request = req;
}

void* HttpServer::thread_func(void* data)
{
    pthread_detach(pthread_self());
    Context* args= static_cast<Context*>(data);

    HttpServer* server = args->server;
    std::shared_ptr<Socket> client = args->client;

    auto req = Utils::get_http_message<HttpRequest>(*client);
    std::shared_ptr<HttpRequest> pt = std::dynamic_pointer_cast<HttpRequest>(req);
    //log<<Utils::HttpMethods.at(pt->get_method())<<" "<<pt->get_uri()<<"\n";
    auto response = server->process_request(*pt);
    client->send(response.__to_string());


    delete args;
    pthread_exit(NULL);
    return 0;
}

HttpResponse HttpServer::process_request(HttpRequest& req)
{
    if(req.get_status() != 0)
        return HttpResponse(400);

    auto host_it  = req.get_headers().find("Host");

    if(host_it == req.get_headers().end())
        return HttpResponse(400, "No host specified");

    auto handler_it = app.handlers.find(req.get_uri());

    if(handler_it == app.handlers.end())
        handler_it = app.handlers.find("/*");

    if(handler_it == app.handlers.end())
        return  HttpResponse(404, "Not found");

    auto handler = handler_it->second->make();

    //Setup handler
    setup_handler(handler, req);

    int e405 = 0;
    switch(req.get_method())
    {
        case Utils::GET:
            handler->get();
            break;
        default:
            e405 = 1;
            break;
    }
    auto content = handler->get_content();

    if(e405 == 1)
        return HttpResponse (405);
    else
        return HttpResponse (200, content);

}


void HttpServer::start()
{
    fd_set readfds;
    std::vector<std::shared_ptr<Socket>> clients(max_clients);
    std::vector<pthread_t> threads(max_clients);

    Logger log;
    while(1)
    {
        FD_ZERO(&readfds);
        FD_SET(sock->get_fd(), &readfds);
        int max_sd = sock->get_fd();


        for(const auto& item : clients)
        {

            if(item == nullptr)
                continue;

            int fd = item->get_fd();
            if(fd > 0)
                FD_SET(fd, &readfds);

            if(item->get_fd() > max_sd)
                max_sd = item->get_fd();
        }

        int activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
        if(activity < 0)
            perror("select");
            //throw std::runtime_error("ERROR select error");

        //Listen socket bit is set, new connection
        if(FD_ISSET(sock->get_fd(), &readfds))
        {
            auto ptr = sock->accept();
            bool found = false;
            for(auto& item : clients)
            {

                pthread_mutex_lock(&lock);
                if(item == nullptr)
                {
                    found = true;
                    item = ptr;
                    pthread_mutex_unlock(&lock);
                    break;
                }
                else
                    pthread_mutex_unlock(&lock);
            }
//            if(!found)
//                throw std::runtime_error("ERROR No space left");

            log<<"Established connection with "<<sock->get_remote_ip()<<" on port "<<sock->get_remote_port()<<"\n";
            log.flush();

        }

        //Check clients for new events
        int i = -1;
        for(auto& client : clients)
        {
            i++;

            if(client == nullptr)
                continue;


            if(FD_ISSET(client->get_fd(), &readfds))
            {
                Context* args = new Context;
                args->server = this;
                args->client = client;

                client = nullptr;

                int rc = pthread_create(&threads[i], NULL, thread_func, (void*)args);

                assert(rc == 0);
            }
        }

	}
}


HttpServer::~HttpServer()
{
	this->sock->close();
}
