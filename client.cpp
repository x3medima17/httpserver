

#include <iostream> 
#include <fstream>
#include <utility>
#include <stdexcept>
#include "socket.h"
#include "message.h"


const int CHUNK_SIZE = 512;

int main(int argc, char* argv[])
{

	if(argc < 3)
		throw std::invalid_argument("Port, host or file not supplied");

	
	int port = atoi(argv[2]);
	std::string host(argv[1]);
	
	
	Socket sock(host, port);
	sock.connect();

	Message msg("Hello World");
	//msg.print();
	Message::print_binary(msg.__to_string());
	sock.send(msg.__to_string());
	sock.close();
	return 0;
}
