#ifndef HTTP_SERVER_H_ 
#define HTTP_SERVER_H_

#include <string>
#include <map>
#include <memory>
#include <iostream>

#include "socket.h"
#include "HttpApplication.h"
#include "HttpRequest.h"
#include "HttpMessage.h"

class HttpClient;

class HttpServer {

    struct Context{
        HttpServer* server;
        std::shared_ptr<Socket> client;
    };


friend class HttpClient;
typedef std::map<int, std::string> HttpCodesMap;




private:
	HttpApplication app;
	std::unique_ptr<Socket> sock;
        int max_clients{ 0 };

        HttpResponse process_request(HttpRequest&);

        void setup_handler(std::shared_ptr<RequestHandler>, HttpRequest&);
        static void* thread_func(void*);

public:
	HttpServer(HttpApplication app);
	HttpServer();
	~HttpServer();
	void bind(int port);
	void listen(int);
	void start();	


        static  std::map<int, std::string> StatusCodes;



};

#endif
