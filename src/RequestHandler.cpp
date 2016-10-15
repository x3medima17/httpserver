#include "RequestHandler.h"
#include <iostream>
#include <fstream>
//RequestHandler::RequestHandler();
void RequestHandler::get()
{

}

RequestHandler::RequestHandler():response_body(""){}

void RequestHandler::write(std::string str)
{
	response_body += str;
}

void RequestHandler::render(std::string fname)
{
	std::string file_name = "templates/" + fname;
	std::ifstream t(file_name);
	std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());
	response_body = str;
}

void RequestHandler::initialize()
{
	response_body = std::string("");
}

std::string RequestHandler::get_response_body() const 
{

	return response_body;
}
