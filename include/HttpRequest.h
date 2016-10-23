#ifndef HTTPREQUEST_H_
#define HTTPREQUEST_H_ 

#include <string>
#include <vector>
#include "HttpResponse.h"
#include "HttpMessage.h"

class HttpClient;

class HttpRequest : public HttpMessage {

friend class HttpClient;

public:
        HttpRequest(http_methods, std::string);
        HttpRequest(std::string);

        // Misc
        void print() const;
        std::string __to_string() const;

        //Getters
        http_methods get_method() const;
        std::string get_uri() const;
        std::string get_host() const;

        //Setters
        void set_host(std::string);

private:
        std::vector<std::string> Methods {"GET", "POST"};
        http_methods method {GET};
        std::string URI{""};
        std::string host{""};

};

#endif
