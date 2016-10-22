#include "HttpRequest.h"
#include <string>
#include <iostream>
 
 
 
#include <exception>


HttpRequest::HttpRequest(http_methods method, std::string URI, 
			std::string version):
	method(method), 
	URI(URI), 
	version(version), 
	Methods{"GET", "POST"},
	status(0) 
{}


HttpRequest::HttpRequest():
	Methods{"GET","POST"},
	status(0)
{}

HttpRequest::HttpRequest(std::string raw): HttpRequest()
{
	//First space
	std::size_t pos = raw.find(" ");
	if(pos == std::string::npos)
	{
		status = 1;
		return;
	}
	
	//Method
	std::string str_method;
	try
	{
		str_method = raw.substr(0, pos);
	}
	catch(std::exception &e)
	{
		std::cout<<"Exception: "<<e.what()<<std::endl;
		throw 1;
	}	
	//std::cout<<raw<<" "<<str_method<<std::endl;
	if(str_method == "GET")
		this->method = GET;
	else if(str_method == "POST")
		this->method = POST;
	else 
	{
		status = 2;
		return;
	} 

	//Second space
	std::size_t pos2 = raw.find(" ",pos+1);
	if(pos == std::string::npos)
	{
		status = 3;
		return;
	}
	try
	{
		URI = raw.substr(pos+1, pos2-pos-1);
		version = raw.substr(pos2+1);
	} catch(std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
		throw 2;
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




