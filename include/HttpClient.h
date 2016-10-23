#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <string>
#include "HttpRequest.h"
#include "HttpResponse.h"

class HttpClient
{
public:
    HttpClient(std::string);
    HttpClient(std::string, std::string, int);

    int get_port() const;
    int get_status() const;
    std::string get_host() const;
    std::string get_uri() const;
    HttpRequest::http_methods get_method() const;

    void fetch();

    HttpResponse response;

private:
    HttpClient(std::string, std::string, int, int, HttpRequest::http_methods);


    std::string host,URI;
    int port,status;
    HttpRequest::http_methods method;


};

#endif // HTTPCLIENT_H
