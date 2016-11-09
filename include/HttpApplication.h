#pragma once
#include <string>
#include <map>
#include <memory>

#include "RequestHandler.h"
#include "utils.h"

class HttpApplication {
typedef std::map<std::string, std::shared_ptr<RequestHandler>> MapHand;

public:
	MapHand handlers;
	
public:
	HttpApplication(MapHand);
        HttpApplication();

};
