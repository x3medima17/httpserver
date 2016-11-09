#pragma once

#include <string>
#include "HttpRequest.h"
#include "utils.h"

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
        void add_header(const std::string&, const std::string&);

        std::string content{""};

        HttpRequest request;
        Utils::VecHeaders Headers;

};
