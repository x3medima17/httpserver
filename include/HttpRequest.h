#ifndef HTTPREQUEST_H_
#define HTTPREQUEST_H_ 

#include <string>
#include <vector>
#include "HttpResponse.h"

class HttpRequest {
public:
	enum http_methods {GET, POST};	

        HttpRequest(http_methods, std::string,std::string);
        HttpRequest(std::string);

        http_methods get_method() const;
	std::string get_version() const;
	std::string get_uri() const;
        void print() const;
        int get_status() const;
        int get_content_length() const;
        HttpResponse::VecHeaders get_headers() const;

private:
        int status, content_length;
	http_methods method;
        std::string URI, version, data;
	std::vector<std::string> Methods;
        HttpResponse::VecHeaders Headers;

        HttpRequest();
        std::vector<std::string> split(std::string, std::string) const;

};

#endif
