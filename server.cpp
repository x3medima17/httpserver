

#include <iostream>
#include <fstream> 
#include <utility>
#include <stdexcept>
#include "socket.h"
#include "message.h"




int main(int argc, char* argv[])
{
	if(argc < 2)
		throw std::invalid_argument("Port  not supplied");
	int port = atoi(argv[1]);
	Socket sock(port);
	sock.bind();
	sock.listen(5);
	
	while(1)
	{
		Socket client = sock.accept();
		
		Message msg = Message::get_msg(client);
		msg.print();
		client.close();	
	}
	sock.close();
	return 0;
}
