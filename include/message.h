#ifndef MESSAGE_H
#define MESSAGE_H 

#include <string>
#include <utility>
#include "socket.h"

class Message {
private:
	unsigned short length;
	std::string data;
		
public:
	Message();
	Message(std::string data);

	unsigned short get_length() const;
	void compute_length();
	void print() const;
	std::string get_data() const;
	
	static Message get_msg(Socket &sock);
	static void print_binary(std::string);
	
	std::string __to_string() const;
};


#endif
