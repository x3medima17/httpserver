#ifndef HTTPRESPONSE_H_
#define HTTPRESPONSE_H_ 

#include <string>
#include <vector>
#include <map>
#include "HttpMessage.h"

class HttpResponse : public HttpMessage {
public:
        typedef std::map<std::string, std::string> VecHeaders;


        HttpResponse();
        HttpResponse(int);
        HttpResponse(int, std::string);

        //for accepting responses
        HttpResponse(const std::string&, const std::string&, int port);

        void print() const;
        std::string __to_string() const;

        //Getters
        int get_http_status() const;


private:
        int http_status{0};
};

#endif
