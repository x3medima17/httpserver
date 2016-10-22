#include "HttpApplication.h"
#include "HttpServer.h"
#include "HttpResponse.h"
#include "socket.h"

#include <string>
#include <map>
#include <iostream>


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


void HttpServer::setup_handler(std::shared_ptr<RequestHandler> handler)
{
    handler->initialize();
    handler->request = {
        {"remote_ip" , sock->get_remote_ip()},
        {"remote_port",  std::to_string(sock->get_remote_port())}
    };

}

HttpResponse HttpServer::process_request(const HttpRequest &req)
{
    if(req.get_status() != 0)
        return HttpResponse(400);

    auto handler_it = app.handlers.find(req.get_uri());

    if(handler_it == app.handlers.end())
        return  HttpResponse(404);

    auto handler = handler_it->second;

    //Setup handler
    setup_handler(handler);

    int e405 = 0;
    switch(req.get_method())
    {
        case HttpRequest::GET:
            handler->get();
            break;
        default:
            e405 = 1;
            break;
    }
    auto response_body = handler->get_response_body();
    HttpResponse response;
    if(e405 == 1)
        response = HttpResponse (405);
    else
        response = HttpResponse (200, response_body);
    return response;
}

void HttpServer::start()
{
	while(1)
	{
		Socket client = this->sock->accept();
        //std::cout<<"Got client"<<std::endl;
		auto req = get_http_request(client);
        auto response = process_request(req);
		client.send(response.__to_string());
		client.close();
	}
}

HttpRequest HttpServer::get_http_request(Socket &client)
{
	std::string data("");
	std::pair<int,std::string> tmp;
	do
	{
		tmp = client.recv(128);
        data += tmp.second;
        if(tmp.first < 2)
            break;
    } while(data.substr(data.size()-4,4) != "\r\n\r\n" && tmp.first == 128 );

    // Check for content
    int clen = 0;
    if(data.find("Content-Length: ") != std::string::npos)
    {
            int p = data.find("Content-Length:");
            int l = data.find(" ",p);
            int r = data.find("\r\n",p);
            clen = std::stoi( data.substr(l+1, r-l) );
    }
    if(clen > 0)
       data += client.recv(clen).second;
    std::cout<<data<<std::endl;
	return HttpRequest(data);
}

HttpServer::~HttpServer()
{
	this->sock->close();
}
