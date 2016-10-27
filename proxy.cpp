#include <iostream>
#include "HttpRequest.h"
#include "HttpApplication.h"
#include "RequestHandler.h"
#include "HttpServer.h"
#include "HttpResponse.h"
#include "Logger.h"
#include "HttpClient.h"

#include <map>
#include <thread>
#include <chrono>


const std::string HOST = "127.0.0.1";
const int IP = 8081;

class Proxy : public RequestHandler
{
public:
    void get()
    {
        Logger log("log.txt");
        std::string URI = request.get_uri();
        std::string url = "http://" + HOST + ":" + std::to_string(IP) + URI;

        HttpClient cli(url);

        //Add headers
        for(auto& header : request.get_headers())
            if(header.first != "Host")
                    cli.add_header(header.first, header.second);
        cli.add_header("Host", HOST);
        cli.fetch();

        for(auto& header : cli.response.get_headers())
            if(header.first != "Content-length")
                cli.add_header(header.first, header.second);
        write(cli.response.get_content());
        log.flush();
    }
};


int main()
{
/*
    HttpClient cli("http://localhost:8081/");
    cli.fetch();
    std::cout<<cli.response.get_content();
    return 0;
*/
    std::map<std::string, std::shared_ptr<RequestHandler>> H;

    H["/*"] = std::shared_ptr<RequestHandler>(new Proxy);

    HttpApplication app(H);
    HttpServer server(app);
    server.bind(8080);

    server.listen(100);
    std::cout<<"Starting proxy..."<<std::endl;
    server.start();
    return 0;
}
