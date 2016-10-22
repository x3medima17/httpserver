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

HttpRequest::HttpRequest(http_methods method, std::string URI, 
			std::string version):
    status(0),
    content_length(0),
	method(method), 
	URI(URI), 
	version(version), 
    Methods{"GET", "POST"}
{}


HttpRequest::HttpRequest():
    status(0),
    content_length(0),
    data(""),
    Methods{"GET","POST"}
{}



std::vector<std::string> HttpRequest::split(std::string target, std::string splitter) const
{
    std::vector<std::string> V;
    auto i = 0;
    auto delim_len = splitter.length();
    auto pos = target.find(splitter);
    while (pos != std::string::npos) {
      V.push_back(target.substr(i, pos-i));
      pos += delim_len;
      i = pos;
      pos = target.find(splitter, pos);

      if (pos == std::string::npos)
         V.push_back(target.substr(i, target.length()));
    }
    if(V.size() == 0)
        V.push_back(target);
    return V;
}

HttpRequest::HttpRequest(std::string raw): HttpRequest()
{

    auto tmp = split(raw,"\r\n\r\n");

    if(tmp.size() < 2)
    {
        status = 1;
        return;
    }
    auto header = split(tmp.front(),"\r\n");

    //merge content
    std::string content("");
    for(size_t i=1;i <tmp.size();i++)
        content += tmp.at(i);

    //request line

    auto request_line = split(header.front()," ");
    if(request_line.size() != 3)
    {
        status = 1;
        return;
    }

	//Method
    std::string str_method = request_line.front();
    if(str_method == "GET")
		this->method = GET;
	else if(str_method == "POST")
		this->method = POST;
	else 
	{
        status = 1;
		return;
	} 

    URI = request_line.at(1);
    version = request_line.back();

    //Headers

    for(size_t i=1; i<header.size();i++)
    {
        auto row = header.at(i);
        auto curr = split(row, ": ");
        if(curr.size() != 2)
        {
            status = 5;
            return;
        }
        Headers.insert({curr.front(), curr.back()});
    }
    if(Headers.find("Content-Length") != Headers.end())
        assert(Headers["Content-Length"] == std::to_string(content.length()));
    content_length = content.length();
    this->content = content;
}

void HttpRequest::print() const
{
	std::cout<<"Status:\t\t"<<status<<'\n';
	std::cout<<"Method:\t\t"<<Methods.at(method)<<'\n';
	std::cout<<"URI:\t\t"<<URI<<'\n';
	std::cout<<"Version:\t"<<version<<std::endl;
}

HttpRequest::http_methods HttpRequest::get_method() const 
{ 
	return method; 
}

int HttpRequest::get_status() const { return status; }
std::string HttpRequest::get_version() const { return version; }
std::string HttpRequest::get_uri() const { return URI; }
HttpResponse::VecHeaders HttpRequest::get_headers() const { return Headers; }
int HttpRequest::get_content_length() const { return content_length; }
std::string HttpRequest::get_content() const { return content; }

