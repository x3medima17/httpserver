#ifndef HTTP_APPLICATION_H_ 
#define HTTP_APPLICATION_H_

#include <string>
#include <map>
#include <memory>

#include "RequestHandler.h"


class HttpApplication {
public:
	std::map<std::string, std::shared_ptr<RequestHandler> > handlers;
	
public:
	HttpApplication(
		std::map<std::string, 
		std::shared_ptr<RequestHandler> >
	);
	HttpApplication();
};

#endif
