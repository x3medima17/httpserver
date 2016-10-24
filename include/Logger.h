#pragma once

#include <string>
#include <fstream>
#include <iostream>
class Logger {
private:
        std::string fname{""};

public:
	Logger(std::string fname);
        Logger();

        template<class T>
        Logger& operator<<(const T& arg)
        {
            if(fname != "")
            {
                std::ofstream fout(fname);
                fout<<arg;
                fout.close();

            }
            else
            {
                std::cout<<arg;
                std::cout.flush();
            }
            return *this;
        }

};
