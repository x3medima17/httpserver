#ifndef MESSAGE_H
#define MESSAGE_H 

#include <string>
#include <utility>
#include "socket.h"

class Message {
private:
	char version, userid;
	unsigned short seq, length, command;
	std::string data;
	std::string packed;
		
public:
	enum command {CLIENT_HELLO, SERVER_HELLO, DELIVER, STORE, ERROR}; 
	//Message(): userid(0x08), version(0x04) {}
	Message();
	Message(unsigned short seq, unsigned short command, std::string data);
	Message(std::string);

	void pack();
	void unpack();
	unsigned short get_length() const;
	void compute_length();
	std::string to_string() const;
	void print_binary(std::string) const;
	void print() const;
	unsigned short get_seq() const;
	unsigned short get_command() const;
	std::string get_data() const;
	static Message get_msg(Socket &sock);
};


#endif
