#include "Logger.h"
#include <string>
#include <fstream>
#include <iostream>

Logger::Logger()   {}

Logger::Logger(const std::string& fname):
    fname(fname)
{}

void Logger::flush()
{

    if(fname != "")
    {
        std::ofstream fout(fname, std::ios_base::app);
        fout<<data<<'\n';
        fout.close();

    }
    else
    {
        std::cout<<data;
        std::cout.flush();
    }

}
