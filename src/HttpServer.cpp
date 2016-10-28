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

//template class   HttpServer::get_http_request<HttpRequest>;
//template  HttpServer::get_http_request<HttpResponse>;
//template std::shared_ptr<HttpMessage>  HttpServer::get_http_request<HttpResponse>;


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
}


void HttpServer::setup_handler(std::shared_ptr<RequestHandler> handler, HttpRequest& req)
{
    handler->initialize();


    req.remote_ip = sock->get_remote_ip();
    req.remote_port = sock->get_remote_port();

    handler->request = req;



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

    auto handler = handler_it->second;

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
	while(1)
	{
        Logger log;
        Socket client = sock->accept();

        int pid = fork();
        if(pid == 0)
        {

            log<<"Established connection with "<<sock->get_remote_ip()<<" on port "<<sock->get_remote_port()<<"\n";
            log.flush();
            sock->close();
            auto req = Utils::get_http_message<HttpRequest>(client);
            std::shared_ptr<HttpRequest> pt = std::dynamic_pointer_cast<HttpRequest>(req);
            log<<Utils::HttpMethods.at(pt->get_method())<<" "<<pt->get_uri()<<"\n";

            auto response = process_request(*pt);

            client.send(response.__to_string());
            client.close();
            log<<"Connection closed\n";
            log.flush();
            exit(0);
        }
        else
            client.close();
	}
}


HttpServer::~HttpServer()
{
	this->sock->close();
}
