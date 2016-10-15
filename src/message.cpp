
#include <string>
#include <iostream>
#include <stdexcept>
#include <netinet/in.h>
#include <vector>
#include <bitset>

#include "message.h"

Message::Message(): length(0),data(""){};

Message::Message(std::string data): length(data.length() + sizeof(length)), data(data){}


std::string Message::get_data() const
{
	return this->data;
}

Message Message::get_msg(Socket &sock)
{
	//Get length
        std::string s_length = sock.recv(sizeof(length)).second;
       	unsigned short length =  ntohs(s_length[0] << 8) | s_length[1];

	std::string data = sock.recv(length - sizeof(length)).second;
        Message out(data);
        return out;

}

void Message::print_binary(std::string str) 
{
	for(auto c : str)
		std::cout<< std::bitset<8>(c)<<' ';
	std::cout<<std::endl;
}

std::string Message::__to_string() const
{
	std::string packed;
        unsigned short tmp = htons(this->length);
        unsigned char H =  (unsigned char)(tmp >> 8);//tmp & 0xff;
        unsigned char L = (unsigned char)(tmp & 0xff);//(tmp >> 8) & 0xff;
	packed += H;
	packed += L;
	packed += this->data;
	return packed;
}
/*
void pack()
{
	compute_length();
	std::string packed;
	packed += version;
	packed += userid;
	
	std::vector<unsigned short> V = {seq, length, command};
	for(auto &item: V)
	{
		unsigned short tmp = htons(item);
		unsigned char H =  (unsigned char)(tmp >> 8);//tmp & 0xff;
		unsigned char L = (unsigned char)(tmp & 0xff);//(tmp >> 8) & 0xff;
		packed += H;
		packed += L;
	}
	for(auto &c : this->data)
		packed += c;
	
	this->packed = packed;
}

void Message::unpack()
{
	this->version = this->packed[0];
	this->userid = this->packed[1];
	this->seq = ntohs((this->packed[2] << 8) | this->packed[3]);
	this->length = ntohs((this->packed[4] << 8) | this->packed[5]);
	this->command = ntohs((this->packed[6] << 8) | this->packed[7]);
	this->data = this->packed.substr(8,this->packed.length()-8);
}
*/

unsigned short Message::get_length() const
{
	return this->length;
}


void Message::print() const
{
	std::cout<<"Length: "<<this->length<<'\n';
	std::cout<<"Data: "<<this->data<<'\n';
}


