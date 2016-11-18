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


class Index : public RequestHandler
{
    void get()
    {
        render("index.html");
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
    std::map<std::string, std::shared_ptr<Utils::iHandler>> Handlers;

    Handlers = {
        {"/", Utils::make_handler<Main>() },
        {"/web", Utils::make_handler<Html>() },
        {"/hello", Utils::make_handler<Hello>() },
        {"/index", Utils::make_handler<Index>() }

    };



    HttpApplication app(Handlers);
    HttpServer server(app);
    server.bind(8081);

    server.listen(1000);
    std::cout<<"Starting server...\n"<<std::endl;
    server.start();
    return 0;


}
