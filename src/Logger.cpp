#include "Logger.h"
#include <string>
#include <fstream>
#include <iostream>

Logger::Logger()   {}

Logger::Logger(std::string fname):
    fname(fname)
{
}
