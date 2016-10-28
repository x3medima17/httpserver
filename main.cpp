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

class Main : public RequestHandler
{
public:
    void get()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));


        write("data\n");

    }
};

class Html : public RequestHandler
{
    void get()
    {

        render("web.html");
    }
};


class Hello : public RequestHandler
{
    void get()
    {
        write("Hello World\n");
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

    H["/"] = std::shared_ptr<RequestHandler>(new Main);
    H["/web"] = std::shared_ptr<RequestHandler>(new Html);
    H["/hello"] = std::shared_ptr<RequestHandler>(new Hello);

    HttpApplication app(H);
    HttpServer server(app);
    server.bind(8081);

    server.listen(100);
    std::cout<<"Starting server...\n"<<std::endl;
    server.start();
    return 0;
}
