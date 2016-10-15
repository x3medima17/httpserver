#include "HttpApplication.h"
#include "RequestHandler.h"
#include "socket.h"

#include <string>
#include <map>
#include <iostream>


HttpApplication::HttpApplication(
		std::map<std::string, 
		std::shared_ptr<RequestHandler> > handlers
		): 
		handlers(handlers)
{}

HttpApplication::HttpApplication(){}

