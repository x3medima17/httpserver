#include "HttpRequest.h"
#include "HttpResponse.h"
#include <string>
#include <iostream>
 
 
#include <sstream>
#include <exception>
#include <iterator>
#include <memory>
#include <algorithm>    // std::copy
#include <fstream>
#include <cassert>
#include <sstream>

HttpRequest::HttpRequest(http_methods method, std::string uri):
            method(method),
            URI(uri)
{}

HttpRequest::HttpRequest(std::string raw): HttpMessage(raw)
{
    if(status != 0)
        return;
    //first line
    auto request_line = split(first_line," ");
    if(request_line.size() != 3)
    {
        status = 2;
        return;
    }

    //Method
    std::string str_method = request_line.front();

    if(str_method == "GET")
            method = GET;
    else if(str_method == "POST")
            method = POST;
    else
    {
        status = 3;
        return;
    }
    URI = request_line.at(1);
    version = request_line.back();

    if(Headers.find("Host") == Headers.end())
    {
        status = 5;
        return;
    }

}

void HttpRequest::set_host(std::string host)
{
    Headers["Host"] = host;
}

void HttpRequest::print() const
{
	std::cout<<"Status:\t\t"<<status<<'\n';
	std::cout<<"Method:\t\t"<<Methods.at(method)<<'\n';
	std::cout<<"URI:\t\t"<<URI<<'\n';
	std::cout<<"Version:\t"<<version<<std::endl;
}


std::string HttpRequest::__to_string() const
{
    std::stringstream out;
    out<<Methods.at(method)<<' '<<URI<<' '<<version<<"\r\n";
    for(auto &header : Headers)
        out<<header.first<<": "<<header.second<<"\r\n";
    out<<"\r\n";
    if(Headers.find("Content-Length") != Headers.end())
        out<<content;
    return out.str();

}

HttpMessage::http_methods HttpRequest::get_method() const { return method; }
std::string HttpRequest::get_uri() const { return URI; }
