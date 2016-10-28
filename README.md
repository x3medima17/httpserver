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

You need CMake to build this project.
~~~ sh
$ cmake .
$ make
~~~
It will produce 3 executables: `httpserver`, `proxy`, `httppserver_test`.

Usage
-----
To use it you need to start httpserver and proxy  processes. Httpserver binds to 8081 port while proxy binds to port 80.
~~~ sh
$ ./httpserver
~~~
~~~ sh
$ sudo ./proxy
~~~

Now you can access http://localhost/ from your browser.
There are 4 predefined pages:
~~~
http://localost/
http://localhost/hello
http://localhost/web
http://localhost/index
~~~
Highly recommend to take a look to the sources.

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
               render("index.html!");
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
