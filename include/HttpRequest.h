#ifndef HTTPREQUEST_H_
#define HTTPREQUEST_H_ 

#include <string>
#include <vector>


class HttpRequest {
public:
	enum http_methods {GET, POST};	
	http_methods get_method() const;
	int get_status() const;
	std::string get_version() const;
	std::string get_uri() const;
private:
	http_methods method;
	std::string URI, version;
	std::vector<std::string> Methods;
	int status;
	HttpRequest();
public:
	HttpRequest(http_methods, std::string,std::string);
	HttpRequest(std::string);

	void print() const;
};

#endif
