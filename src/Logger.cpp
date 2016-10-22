#include "Logger.h"
#include <string>
#include <fstream>
#include <iostream>

Logger::Logger(std::string fname = "") : fname(fname)
{}

void Logger::operator<<(std::string data)
{	
	if(fname == "")
		std::cout<<data<<std::endl;
	else
	{
		std::ofstream fout(fname);
		fout << data << "\n";
		fout.close();
	}
}

