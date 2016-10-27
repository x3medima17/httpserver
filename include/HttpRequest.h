#pragma once

#include <string>
#include <vector>


#include "HttpResponse.h"
#include "HttpMessage.h"
#include "utils.h"


class HttpRequest : public HttpMessage {

friend class HttpClient;
friend class HttpServer;

public:
        HttpRequest(Utils::http_methods, std::string);
        HttpRequest(const std::string&, const std::string& = "", int ip = 80);
        HttpRequest();

        // Misc
        void print() const;
        std::string __to_string() const;

        //Getters
        Utils::http_methods get_method() const;
        std::string get_uri() const;
        std::string get_host() const;

        //Setters
        void set_host(std::string);

private:
        Utils::http_methods method {Utils::GET};
        std::string URI{""};
        std::string host{""};

};


