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

size_t request_no = 0;
pthread_mutex_t proxy_lock;
class Proxy : public RequestHandler
{
public:
    void get()
    {
        Logger log("proxy.log");
        std::string URI = request.get_uri();
        std::string url = URI;

        pthread_mutex_lock(&proxy_lock);
        request_no++;
        log<<request_no<<" "<<request.get_remote_ip()<<":"<<request.get_remote_port()<<" "<<url<<" GET "<<"\n";
        log.flush();
        pthread_mutex_unlock(&proxy_lock);

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

class Ha : public RequestHandler
{
public:
    void get()
    {
        write("haha\n");
    }
};


int main()
{
    pthread_mutex_init(&proxy_lock, NULL);

    std::map<std::string, std::shared_ptr<Utils::iHandler>> H;

    H["/*"] = Utils::make_handler<Proxy>();

    H["/ha"] = Utils::make_handler<Ha>();

    HttpApplication app(H);
    HttpServer server(app);
    server.bind(8080);

    server.listen(1000);
    std::cout<<"Starting proxy..."<<std::endl;
    server.start();
    return 0;
}
