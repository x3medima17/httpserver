#pragma once

#include <string>
#include <fstream>
#include <iostream>
class Logger {
private:
        std::string fname{""};
        std::string data{""};

public:
        Logger(const std::string& fname);
        Logger();

        void flush();

        Logger& operator<<(const char* arg)
        {
            data += std::string(arg);
            return *this;
        }

        Logger& operator<<(const std::string& arg)
        {
            data += arg;
            return *this;
        }

        template<class T>
        Logger& operator<<(const T& arg)
        {
            std::string tmp(std::to_string(arg));
            data += tmp;
            return *this;
        }

};
