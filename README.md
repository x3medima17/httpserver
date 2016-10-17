# HTTP Server 


Repository link: https://github.com/x3medima17/httpserver

This is a simple C++ HTTP Server with a small web framework, inspired by [Tornado](<http://www.tornadoweb.org>).

This project is  written for Network Programming course, KAIST.

 
Instalation
-----------

First of all clone or download this repository.
~~~ sh
$ git clone https://github.com/x3medima17/httpserver
~~~

Then make project, it will produce `server` executable.
~~~ sh
$ make
~~~

Usage
-----
To use it you need to start server process. By default it binds to port 8081.
~~~ sh
$ ./server 
~~~
Now you can access http://localhost:8081 from your browser.


Hello, world
------------
~~~ cpp
#include "HttpRequest.h"
#include "HttpApplication.h"
#include "RequestHandler.h"
#include "HttpServer.h"
#include "HttpResponse.h"

#include <map>
#include <iostream>

class Main : public RequestHandler
{
public:
        void get()
        {
                this->write("Hello, World!");
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
~~~
