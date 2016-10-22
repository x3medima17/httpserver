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
    return V;
}

HttpRequest::HttpRequest(std::string raw): HttpRequest()
{

    auto rows = split(raw,"\r\n");
    if(rows.size() <= 2)
    {
        status = 1;
        return;
    }
    if(!(rows.back().size() == 0 && rows.at(rows.size()-2).size() == 0))
    {
        status = 2;
        return;
    }
    rows.pop_back();
    rows.pop_back();
    //request line
    auto request_line = split(rows.front()," ");
    if(request_line.size() != 3)
    {
        status = 3;
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
        status = 4;
		return;
	} 

    URI = request_line.at(1);
    version = request_line.back();

    //Headers

    for(size_t i=1; i<rows.size();i++)
    {
        auto row = rows.at(i);
        auto curr = split(row, ": ");
        if(curr.size() != 2)
        {
            status = 5;
            return;
        }
        Headers.insert({curr.front(), curr.back()});
    }
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


