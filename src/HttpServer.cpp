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

#include <pthread.h>


#include <thread>
#include <chrono>


pthread_mutex_t glock;
const size_t N_threads = 4;
std::vector<pthread_mutex_t> LOCKS;

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
{
    pthread_mutex_init(&lock, NULL);
}

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
    clients.resize(max_clients);
    LOCKS.resize(max_clients);
}


void HttpServer::setup_handler(std::shared_ptr<RequestHandler> handler, HttpRequest& req)
{
    handler->initialize();

    req.remote_ip = sock->get_remote_ip();
    req.remote_port = sock->get_remote_port();

    handler->request = req;
}

void* logger_daemon(void* data)
{
    pthread_detach(pthread_self());
    HttpServer* server = static_cast<HttpServer*>(data);

    while(1)
    {
        int qq = 0;
        for(auto client : server->clients)
            if(client == nullptr)
                qq++;
        std::cout<<"Working "<<server->clients.size()-qq<<" out of "<<server->clients.size()<<std::endl;

    }

    long long counter = 0;
    while(1)
    {
        if(counter++ < 1000000L)
        {
            pthread_yield();
            continue;
        }
        std::cout<<counter<<std::endl;
        counter = 0;
        pthread_mutex_lock(&(server->lock));
        std::cout<<"Flush"<<std::endl;
        server->log.flush();
        pthread_mutex_unlock(&(server->lock));
    }
    pthread_exit(NULL);
    return 0;
}

void* HttpServer::thread_func(void* data)
{

    pthread_detach(pthread_self());


    Context* args = static_cast<Context*>(data);


    size_t tid = args->tid;


    while(1)
    {
//        bool yiled = true;
        for(size_t i = 0; i<args->server->max_clients; i++)
        {
            if(i%N_threads != tid)
                continue;
            //std::cout<<i<<std::endl;
            pthread_mutex_lock(&LOCKS.at(i));

            auto& client = args->server->clients.at(i);
            if(client != nullptr)
            {
//                FD_CLR(client->get_fd(), args->readfds);
//                client = nullptr;
//                pthread_mutex_unlock(&LOCKS.at(i));
//                continue;

                auto req = Utils::get_http_message<HttpRequest>(*client);
                std::shared_ptr<HttpRequest> pt = std::dynamic_pointer_cast<HttpRequest>(req);
                auto response = args->server->process_request(*pt);
                client->send(response.__to_string());

//                pthread_mutex_lock(&LOCKS.at(i));
                FD_CLR(client->get_fd(), args->readfds);
                client = nullptr;
//                pthread_mutex_unlock(&LOCKS.at(i));

            }
//            else
                pthread_mutex_unlock(&LOCKS.at(i));
        }
    }



    //std::cout<<"Critical region ends"<<std::endl;
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
    std::cout<<req.get_uri()<<std::endl;
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
    pthread_t daemon;
    for(size_t i = 0; i < LOCKS.size(); i++)
        pthread_mutex_init(&LOCKS.at(i), NULL);

    pthread_mutex_init(&glock, NULL);


    //assert(pthread_create(&daemon, NULL, logger_daemon, (void*)this) == 0);
//    int rc = pthread_create(&threads[i], NULL, thread_func, (void*)args);

    fd_set readfds;
    std::vector<pthread_t> threads(max_clients);

    std::vector<Context> C;


    for(size_t i = 0; i<N_threads; i++)
        C.push_back(Context(this, i, &readfds));

    for(size_t i = 0; i<N_threads; i++)
    {
        int rc = pthread_create(&threads[i], NULL, thread_func, (void*)&(C.at(i)));
        //assert(rc == 0);
    }
    std::cout<<C.size()<<std::endl;
    /////////////////////////////////////
    Logger log;
    while(1)
    {
        FD_ZERO(&readfds);
        FD_SET(sock->get_fd(), &readfds);
        int max_sd = sock->get_fd();

        size_t i = -1;
        for(const auto& item : clients)
        {
            i++;

            pthread_mutex_lock(&LOCKS.at(i));
            if(item != nullptr)
            {
                int fd = item->get_fd();
                if(fd > 0)
                    FD_SET(fd, &readfds);

                if(fd > max_sd)
                    max_sd = fd;
            }
            pthread_mutex_unlock(&LOCKS.at(i));

        }

        int activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
        if(activity < 0)
            perror("select");

        //Listen socket bit is set, new connection
        if(FD_ISSET(sock->get_fd(), &readfds))
        {
            auto ptr = sock->accept();
            size_t i = -1;
            for(auto& item : clients)
            {
                i++;
                pthread_mutex_lock(&LOCKS.at(i));
                if(item == nullptr)
                {
                    item = ptr;
                    pthread_mutex_unlock(&LOCKS.at(i));
                    break;
                }                
                pthread_mutex_unlock(&LOCKS.at(i));

            }

            log<<"Established connection with "<<sock->get_remote_ip()<<" on port "<<sock->get_remote_port()<<"\n";
            log.flush();

        }

	}
}


HttpServer::~HttpServer()
{
	this->sock->close();
}
