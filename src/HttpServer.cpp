#include "HttpApplication.h"
#include "HttpServer.h"
#include "HttpResponse.h"
#include "socket.h"
#include "message.h"

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

void HttpServer::start()
{
	while(1)
	{
		Socket client = this->sock->accept();
		std::cout<<"Got client"<<std::endl;
		auto req = get_http_request(client);
		std::cout<<'*'<<req.get_uri()<<'*'<<std::endl;
		auto handler_it = app.handlers.find(req.get_uri());
		if(handler_it == app.handlers.end())
		{
			auto response = HttpResponse(404);
			client.send(response.__to_string());
			client.close();
			continue;
		}
		auto handler = handler_it->second;
		handler->initialize();
		
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
	} while(data.substr(data.size()-2,2) != "\r\n" );
	data = data.substr(0,data.size()-2);
	return HttpRequest(data);
}

HttpServer::~HttpServer()
{
	this->sock->close();
}
