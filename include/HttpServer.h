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

friend class HttpClient;
typedef std::map<int, std::string> HttpCodesMap;




private:
	HttpApplication app;
	std::unique_ptr<Socket> sock;
	
        HttpResponse process_request(HttpRequest&);
        void setup_handler(std::shared_ptr<RequestHandler>, HttpRequest&);

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
