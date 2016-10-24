#include "HttpResponse.h"
#include <string>
#include <iostream>
#include "HttpRequest.h"
#include "HttpServer.h"
#include <cassert>


HttpResponse::HttpResponse(){}

HttpResponse::HttpResponse(int http_status): http_status(http_status)
{}

HttpResponse::HttpResponse(int http_status, std::string content):
              HttpResponse(http_status)
{
    this->content = content;
    content_length = content.length();
    Headers.insert({"Content-Length", std::to_string(content_length) });

}

HttpResponse::HttpResponse(std::string raw) : HttpMessage(raw)
{

    if(status != 0)
        return;

    //response line
    auto response_line = split(first_line," ");
    if(response_line.size() < 3)
    {
        status = 2;
        return;
    }

    version = response_line.front();
    http_status = std::stoi(response_line.at(1));
    std::string result("");
    for(size_t i = 2; i<response_line.size(); i++)
        result += response_line.at(i);

    if(HttpServer::StatusCodes.find(http_status) == HttpServer::StatusCodes.end())
    {
        status = 3;
        return;
    }
}

void HttpResponse::print() const
{
    std::string status_str = HttpServer::StatusCodes.find(status)->second;
	std::cout<<"Status:\t\t"<<status<<' '<<status_str<<'\n';
	std::cout<<"Version:\t"<<version<<std::endl;
    std::cout<<"Body:\t\t"<<content<<std::endl;
}

std::string HttpResponse::__to_string() const
{
    std::string out("");
    std::string status_str = HttpServer::StatusCodes.find(http_status)->second;
    out += version+" "+std::to_string(http_status)+" "+status_str+"\r\n";
	for(auto &header: Headers)
		out += header.first+": "+header.second+"\r\n";
    out += "\r\n";
    out += content;
	return out;
}

int HttpResponse::get_http_status() const { return http_status; }





