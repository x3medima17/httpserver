#include "Logger.h"
#include <string>
#include <fstream>
#include <iostream>
#include "fcntl.h"
#include <stdio.h>
#include <unistd.h>

Logger::Logger()   {}

Logger::Logger(const std::string& fname):
    fname(fname)
{}

void Logger::flush()
{

    if(fname != "")
    {
        std::fstream fout;
        fout.open(fname, std::fstream::out | std::fstream::app);
        fout<<data;

    }
    else
    {
        std::cout<<data;
        std::cout.flush();
    }
    data = "";

}
