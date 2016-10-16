#ifndef HTTP_APPLICATION_H_ 
#define HTTP_APPLICATION_H_

#include <string>
#include <map>
#include <memory>

#include "RequestHandler.h"


class HttpApplication {
typedef std::map<std::string, std::shared_ptr<RequestHandler>> MapHand;
public:
	MapHand handlers;
	
public:
	HttpApplication(MapHand);
	HttpApplication();
};

#endif
