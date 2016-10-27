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
    Socket sock(host,port);
    HttpRequest req(method, URI);
    req.set_host(host);
    sock.connect();
    sock.send(req.__to_string());
    auto tmp = Utils::get_http_message<HttpResponse>(sock);
    std::shared_ptr<HttpResponse> pt = std::dynamic_pointer_cast<HttpResponse>(tmp);
    response = *pt;
    sock.close();
}

int HttpClient::get_status() const { return status; }
int HttpClient::get_port() const { return port; }
std::string HttpClient::get_uri() const { return URI; }
std::string HttpClient::get_host() const { return (port == 80 ) ? host : host+":"+std::to_string(port) ; }
Utils::http_methods HttpClient::get_method() const { return method; }

