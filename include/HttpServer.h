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
#include "Logger.h"

#include <pthread.h>

class HttpClient;

class HttpServer {

    struct Context{
        HttpServer* server;
        size_t tid;
        fd_set* readfds;
        Context(HttpServer* server, size_t tid, fd_set* readfds):
            server(server),
            tid(tid),
            readfds(readfds)
        {}
    };


friend class HttpClient;
typedef std::map<int, std::string> HttpCodesMap;




private:
	HttpApplication app;
	std::unique_ptr<Socket> sock;
        size_t max_clients{ 0 };
        size_t request_no { 0 };

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
        Logger log { "proxy.log.old" };
        pthread_mutex_t lock;
        std::vector<std::shared_ptr<Socket>> clients;



        //Deleted
        HttpServer(const HttpServer&) = delete;
        HttpServer& operator=(const HttpServer&) = delete;


};

#endif
