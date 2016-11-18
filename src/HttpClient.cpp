#include "HttpClient.h"
#include "socket.h"
#include <string>
#include <iostream>
#include "HttpServer.h"
#include "utils.h"

HttpClient::HttpClient(std::string host = "", std::string URI = "", int port = 80,
                       int status = 0, Utils::http_methods method = Utils::GET):
            host(host),
            URI(URI),
            port(port),
            status(status),
            method(method)
{}

void HttpClient::add_header(const std::string& header, const std::string& value)
{
    Headers.insert({header, value});
}

HttpClient::HttpClient(std::string raw) : HttpClient()
{
    auto pos = raw.find("http://");
    if(pos == std::string::npos || pos != 0 || raw.length() <= 7)
    {
        status = 1;
        return;
    }
    raw = raw.substr(7);
    auto colon = raw.find(":");
    auto slash = raw.find("/");
    if(slash == std::string::npos)
    {
        status = 2;
        return;
    }

    if(colon != std::string::npos && colon < slash)
    {
        host = raw.substr(0,colon);
        port = std::stoi(raw.substr(colon+1, slash-colon));
    }
    else
        host = raw.substr(0,slash);

    URI = raw.substr(slash);

}

void HttpClient::fetch()
{
    int Q = 0;
    std::cout<<++Q<<std::endl;

    Socket sock(host,port);
    HttpRequest req(method, URI);
    req.set_host(host);

    for(auto& header: Headers)
        req.add_header(header.first, header.second);

    std::cout<<++Q<<std::endl;

    sock.connect();
    sock.send(req.__to_string());

    std::cout<<++Q<<std::endl;

    auto tmp = Utils::get_http_message<HttpResponse>(sock);
    std::shared_ptr<HttpResponse> pt = std::dynamic_pointer_cast<HttpResponse>(tmp);
    response = *pt;

    std::cout<<++Q<<std::endl;

    sock.close();

    std::cout<<++Q<<std::endl;

}

int HttpClient::get_status() const { return status; }
int HttpClient::get_port() const { return port; }
std::string HttpClient::get_uri() const { return URI; }
std::string HttpClient::get_host() const { return (port == 80 ) ? host : host+":"+std::to_string(port) ; }
Utils::http_methods HttpClient::get_method() const { return method; }

