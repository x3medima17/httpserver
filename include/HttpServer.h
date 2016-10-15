#ifndef HTTP_SERVER_H_ 
#define HTTP_SERVER_H_

#include <string>
#include <map>
#include <memory>

#include "socket.h"
#include "HttpApplication.h"
#include "HttpRequest.h"

class HttpServer {
private:
	HttpApplication app;
	std::unique_ptr<Socket> sock;
	
	HttpRequest get_http_request(Socket&);	
public:
	HttpServer(HttpApplication app);
	HttpServer();
	~HttpServer();
	void bind(int port);
	void listen(int);
	void start();	
};

#endif