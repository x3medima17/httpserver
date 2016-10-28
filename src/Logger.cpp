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
        flock fl = {F_WRLCK, SEEK_SET,   0,      0,     0 };
        fl.l_pid = getpid();
        fl.l_type = F_WRLCK;
        int fd;
        char ch;
        int lines = 0;

        FILE* f = fopen(fname.c_str(),"r");

        do
        {
            ch = fgetc(f);
            if(ch == '\n')
                lines++;
        }while(ch != EOF);
        fclose(f);

        if ((fd = open(fname.c_str(), O_RDWR|O_APPEND)) == -1)
            throw std::runtime_error("Open log error");

        //Getting the lock
        if(fcntl(fd, F_SETLKW, &fl) == -1)
            throw std::runtime_error("Get lock error");

        // do something
        data = std::to_string(lines+1) +" "+ data +"\n";
        write(fd, data.c_str(), data.length());

        //unlock
        fl.l_type = F_UNLCK;
        if (fcntl(fd, F_SETLK, &fl) == -1)
            throw std::runtime_error("Set lock error");


        close(fd);


    }
    else
    {
        std::cout<<data;
        std::cout.flush();
    }
    data = "";

}
