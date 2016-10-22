#ifndef REQUESTHANDLER_H_
#define REQUESTHANDLER_H_

#include <string>
#include <map>

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
        std::map<std::string, std::string> request;

};

#endif
