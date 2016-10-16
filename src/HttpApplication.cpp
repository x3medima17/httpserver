#include "HttpApplication.h"
#include "RequestHandler.h"
#include "socket.h"

#include <string>
#include <map>
#include <iostream>


HttpApplication::HttpApplication(HttpApplication::MapHand a_handlers): 
						handlers(a_handlers)
{}

HttpApplication::HttpApplication(){}

