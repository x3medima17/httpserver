#include "HttpResponse.h"
#include <string>
#include <iostream>


HttpResponse::HttpResponse(std::string version, int status,
			HttpResponse::VecHeaders Headers,
			std::string body):
	version(version),
	status(status),
	Headers(Headers), 
	body(body),
	content_length(body.length())
{
	StatusCodes = std::map<int, std::string>{
		{200, "OK"},
		{404, "Not Found"},
		{405, "Method not allowed"}
	};
	std::string s_content_length = std::to_string(content_length);
    this->Headers.insert({"Content-Length", s_content_length});
}

HttpResponse::HttpResponse():
	HttpResponse(500)
{}

HttpResponse::HttpResponse(int status):
	HttpResponse("HTTP/1.1", status)
{}

HttpResponse::HttpResponse(int status, std::string body):
	HttpResponse("HTTP/1.1", status, body)
{}

HttpResponse::HttpResponse(std::string version, int status):
	HttpResponse(version, status, HttpResponse::VecHeaders(), "")
{}

HttpResponse::HttpResponse(std::string version, int status,
			HttpResponse::VecHeaders Headers):
	HttpResponse(version, status, Headers, "")
{}

HttpResponse::HttpResponse(std::string version, int status,
		 std::string body):
	HttpResponse(version, status,HttpResponse::VecHeaders(), body)
{} 

void HttpResponse::print() const
{
	std::string status_str = StatusCodes.find(status)->second;
	std::cout<<"Status:\t\t"<<status<<' '<<status_str<<'\n';
	std::cout<<"Version:\t"<<version<<std::endl;
	std::cout<<"Body:\t\t"<<body<<std::endl;
}

std::string HttpResponse::__to_string() const
{
    std::string out("");
	std::string status_str = StatusCodes.find(status)->second;
	out += version+" "+std::to_string(status)+" "+status_str+"\r\n";
	for(auto &header: Headers)
		out += header.first+": "+header.second+"\r\n";
	if(!body.empty())
	{
		out += "\r\n";
		out += body;
	}
	return out;
}



