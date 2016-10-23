#ifndef HTTPMESSAGE_H
#define HTTPMESSAGE_H

#include <string>
#include <vector>
#include <map>
#include "socket.h"

class HttpMessage
{
public:
    typedef std::map<std::string, std::string> VecHeaders;
    enum http_methods {GET, POST};

    //Getters
    VecHeaders  get_headers() const;
    std::string get_version() const;
    std::string get_content() const;
    int  get_content_length() const;
    int          get_status() const;

    virtual ~HttpMessage();
protected:
    // Must set everything except first line (put it in variable)
    HttpMessage();
    HttpMessage(std::string);

    std::vector<std::string> split(std::string, std::string);
    VecHeaders Headers;

    std::string version{"HTTP/1.1"};
    std::string content{""};
    int content_length{0};
    int status{0};

    //Misc
    std::string raw_header{""};
    std::string raw_content{""};
    std::string first_line{""};



};

#endif // HTTPMESSAGE_H
