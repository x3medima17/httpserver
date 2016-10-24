#include "RequestHandler.h"
#include <iostream>
#include <fstream>
//RequestHandler::RequestHandler();
void RequestHandler::get()
{

}

RequestHandler::RequestHandler():content(""){}

void RequestHandler::write(std::string str)
{
    content += str;
}

void RequestHandler::render(std::string fname)
{
	std::string file_name = "templates/" + fname;
	std::ifstream t(file_name);
	std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());
    content = str;
}

void RequestHandler::initialize()
{
    content = std::string("");
}

std::string RequestHandler::get_content() const
{

    return content;
}
