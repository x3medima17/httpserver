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

class Proxy : public RequestHandler
{
public:
    void get()
    {
        Logger log("proxy.log");
        std::string URI = request.get_uri();
        std::string url = URI;

        log<<request.get_remote_ip()<<":"<<request.get_remote_port()<<" "<<url<<" GET "<<URI;
        log.flush();
        HttpClient cli(url);

        //Add headers
        for(auto& header : request.get_headers())
            if(header.first != "Host")
                    cli.add_header(header.first, header.second);
        cli.fetch();

        for(auto& header : cli.response.get_headers())
            if(header.first != "Content-length")
                cli.add_header(header.first, header.second);
        write(cli.response.get_content());

    }
};



int main()
{

    std::map<std::string, std::shared_ptr<RequestHandler>> H;


    H["/*"] = std::shared_ptr<RequestHandler>(new Proxy);

    HttpApplication app(H);
    HttpServer server(app);
    server.bind(80);

    server.listen(100);
    std::cout<<"Starting proxy..."<<std::endl;
    server.start();
    return 0;
}
