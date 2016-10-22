#ifndef REQUESTHANDLER_H_
#define REQUESTHANDLER_H_

#include <string>


class RequestHandler {
friend class HttpServer;

public:
	virtual void get();
	RequestHandler();
	
	void initialize();	
	std::string get_response_body() const;
protected:
	void write(std::string);
	void render(std::string);
	std::string response_body;
        std::string remote_ip;

};

#endif
