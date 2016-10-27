#pragma once
#include <string>

#include "utils.h"
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
    Utils::http_methods get_method() const;

    void fetch();

    HttpResponse response;

private:
    HttpClient(std::string, std::string, int, int, Utils::http_methods);


    std::string host,URI;
    int port,status;
    Utils::http_methods method;


};
