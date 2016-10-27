#pragma once

#include <string>
#include <map>
#include "HttpRequest.h"
//class HttpRequest;

class RequestHandler {
friend class HttpServer;

public:
	virtual void get();
        //RequestHandler(const HttpRequest*);
        RequestHandler();

	void initialize();	
        std::string get_content() const;
protected:
	void write(std::string);
	void render(std::string);
        std::string content;
        HttpRequest request;

};
