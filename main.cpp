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

template<class T>
class Handler
{

    std::shared_ptr<RequestHandler> operator()()
    {
        return std::shared_ptr<RequestHandler>(new T);
    }

};


template<class T>
std::shared_ptr<RequestHandler> make_handler()
{
    auto pt = new T;
    return std::shared_ptr<RequestHandler>(pt);
}


int main()
{
    //auto func = Handler;

    /*
    std::map<std::string, Handler> H;
    std::map<int, std::vector<int>> M;

    std::vector<int> aa;
    Handler<RequestHandler> qq;

    H.insert({"/", qq});
*/


    std::map<std::string, std::shared_ptr<RequestHandler>> H;
    H["/"] = std::shared_ptr<RequestHandler>(new Main);
    H["/web"] = std::shared_ptr<RequestHandler>(new Html);
    H["/hello"] = std::shared_ptr<RequestHandler>(new Hello);
    H["/index"] = std::shared_ptr<RequestHandler>(new Index);

    HttpApplication app(H);
    HttpServer server(app);
    server.bind(8081);

    server.listen(5);
    std::cout<<"Starting server...\n"<<std::endl;
    server.start();
    return 0;


}
