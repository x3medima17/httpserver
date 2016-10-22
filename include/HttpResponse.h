#ifndef HTTPRESPONSE_H_
#define HTTPRESPONSE_H_ 

#include <string>
#include <vector>
#include <map>

class HttpResponse {
public:
        typedef std::map<std::string, std::string> VecHeaders;

        HttpResponse();
        HttpResponse(int);
        HttpResponse(int, std::string);
        HttpResponse(std::string, int);
        HttpResponse(std::string, int, VecHeaders);
        HttpResponse(std::string, int, std::string);
        HttpResponse(std::string, int, VecHeaders, std::string );

        void print() const;
        std::string __to_string() const;

private:
	std::string version;
	int status;
	VecHeaders Headers;
	std::string body;	
	int content_length;
	std::map<int, std::string> StatusCodes;
};

#endif
