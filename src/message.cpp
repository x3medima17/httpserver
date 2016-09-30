
#include <string>
#include <iostream>
#include <stdexcept>
#include <netinet/in.h>
#include <vector>
#include <bitset>

#include "message.h"

Message::Message(): version(0x04), userid(0x08), length(0), seq(0), command(0), data(""){};

Message::Message(unsigned short seq, unsigned short command, std::string data):Message()
{
	this->seq = seq;
	this->command = command;
	this->data = data;
}

Message::Message(std::string packed):Message()
{
	this->packed = packed;
}

std::string Message::get_data() const
{
	return this->data;
}

Message Message::get_msg(Socket &sock)
{
        Message msg(sock.recv(8).second);
        msg.unpack();
	unsigned short  length = msg.get_length();
        unsigned short command = msg.get_command();
        int seq = msg.get_seq(); 
	std::string data = sock.recv(length - 8).second;
        Message out(seq, command, data);
        out.compute_length();
        return out;

}

void Message::print_binary(std::string str) const
{
	for(auto c : str)
		std::cout<< std::bitset<8>(c)<<' ';
	std::cout<<'\n';
}

std::string Message::to_string() const
{
	if (this->packed.empty())
		throw std::runtime_error("Pack first");
	return this->packed;
}

void Message::pack()
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

unsigned short Message::get_seq() const
{
	return this->seq;
}

unsigned short Message::get_command() const
{
	return this->command;
}

unsigned short Message::get_length() const
{
	return this->length;
}

void Message::compute_length() 
{
	unsigned short base_size = sizeof(version) + sizeof(userid) + sizeof(seq) + sizeof(length) + sizeof(command);
	this->length = base_size + this->data.length();
} 

void Message::print() const
{
	std::cout<<"Version: "<<(int)this->version<<'\n';
	std::cout<<"UserID: "<<(int)this->userid<<'\n';
	std::cout<<"Seq: "<<this->seq<<'\n';
	std::cout<<"Length: "<<this->length<<'\n';
	std::cout<<"Command: "<<this->command<<'\n';
	std::cout<<"Data: "<<this->data<<'\n';
}


