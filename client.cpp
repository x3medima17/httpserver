

#include <iostream> 
#include <fstream>
#include <utility>
#include "socket.h"
#include "message.h"


const int CHUNK_SIZE = 512;

int main(int argc, char* argv[])
{

	if(argc < 4)
		throw std::invalid_argument("Port, host or file not supplied");

	
	int port = atoi(argv[2]);
	std::string host(argv[1]);
	std::string filename(argv[3]);
	
	std::ifstream fin(filename, std::ios::binary);
	
	Socket sock(host, port);
	sock.connect();

	char buff[CHUNK_SIZE];
	int seq = 1;
	//Hello
	Message msg(seq++, 1,"");
	msg.pack();
	sock.send(msg.to_string());
	//Wait hello
	msg = Message::get_msg(sock);
	if(msg.get_command() != 2)
		throw std::runtime_error("Server didn't greet");
 	
	//Deliver
	while(fin.get(buff, CHUNK_SIZE, '\0'))
	{
		std::string data(buff);
		msg = Message(seq++,3,data);
		msg.pack();
		try
		{
			sock.send(msg.to_string());
		}
		catch(std::exception &e){
			std::cout<<e.what()<<std::endl; 
		}
	}
	//Store
	msg = Message(seq++,4,"");
	msg.pack();

	sock.send(msg.to_string());
	sock.close();
	return 0;
}
