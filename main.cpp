#include <iostream>
#include "HttpRequest.h"
#include "HttpApplication.h"
#include "RequestHandler.h"
#include "HttpServer.h"
#include "HttpResponse.h"
#include "Logger.h"
#include <map>


class Main : public RequestHandler
{
public:
    void get()
    {
        Logger log("requests.log");
        log<<"get";
        write(this->remote_ip);
        //render("index.html");
    }
};
int main()
{


    std::map<std::string, std::shared_ptr<RequestHandler>> H;

    H["/"] = std::shared_ptr<RequestHandler>(new Main);

    HttpApplication app(H);
    HttpServer server(app);
    server.bind(8081);

    server.listen(5);
    server.start();
    return 0;
}
