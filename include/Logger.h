#pragma once

#include <string>

class Logger {
private:
	std::string fname;

public:
	Logger(std::string fname);

	void operator << (std::string);
};
