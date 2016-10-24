#include <iostream>
#include "HttpRequest.h"
#include "HttpApplication.h"
#include "RequestHandler.h"
#include "HttpServer.h"
#include "HttpResponse.h"
#include "Logger.h"
#include "HttpClient.h"
#include <map>


class Main : public RequestHandler
{
public:
    void get()
    {
        Logger log("log.txt");
        log<<"heelo"<<" "<<"world";
        write("data\n");

        write(this->request["remote_ip"]);
        write("\n");
        write(this->request["remote_port"]);
        write("\n");
        //render("index.html");
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
    HttpApplication app(H);
    HttpServer server(app);
    server.bind(8081);

    server.listen(5);
    std::cout<<"Starting server...\n"<<std::endl;
    server.start();
    return 0;
}
