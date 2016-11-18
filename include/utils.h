#pragma once

#include <memory>
#include <vector>
#include <map>
#include <iostream>
#include <cassert>
#include "socket.h"

class HttpMessage;
class RequestHandler;

namespace Utils {

    class iHandler{
    public:
        virtual std::shared_ptr<RequestHandler> make() = 0;
    };

    template<class T>
    class Handler : public iHandler
    {
    public:
        std::shared_ptr<RequestHandler> make()
        {
            return std::shared_ptr<RequestHandler>(new T);
        }

    };

    template<class T>
    std::shared_ptr<iHandler> make_handler()
    {
        return std::shared_ptr<iHandler>(new Handler<T>());
    }

    template<class T>
    std::shared_ptr<HttpMessage> get_http_message(Socket &client)
    {

            std::string data("");
            std::pair<int,std::string> tmp;
            do
            {
                tmp = client.recv(1024);
                data += tmp.second;
                if(tmp.first < 2)
                    break;
            } while(data.substr(data.size()-4) != "\r\n\r\n" && tmp.first == 1024 );
        //assert(data.substr(data.size() - 4) == "\r\n\r\n" || tmp.first != 1024);
        // Check for content
        int clen = 0;
        int to_read = 0;
        if(data.find("Content-Length: ") != std::string::npos)
        {
                int p = data.find("Content-Length:");
                int l = data.find(" ",p);
                int r = data.find("\r\n",p);
                clen = std::stoi( data.substr(l+1, r-l) );
                to_read = clen - (data.length() - r);
        }
        if(to_read > 0)
           data += client.recv(clen).second;
        auto ip = "";//client.get_remote_ip();

        return std::make_shared<T>(data, ip, client.get_remote_port());
    }

    const std::vector<std::string> HttpMethods = {"GET", "POST"};

    enum http_methods {GET, POST};

    typedef std::map<std::string, std::string> VecHeaders;
}

