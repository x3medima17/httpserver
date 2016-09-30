

#include <iostream>
#include <fstream> 
#include <utility>
#include "socket.h"
#include "message.h"


void send_error(Socket &sock, int seq)
{
	std::cout<<"error on seq "<<seq<<'\n';
	Message msg(seq, 5, "");
	msg.pack();
	sock.send(msg.to_string());
	sock.close();
}


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
		int command = -1;
		unsigned short  seq = -1;
		int error_flag = 0;
		//Hello
		Message msg = Message::get_msg(client);
	
		command = msg.get_command();
		seq = msg.get_seq();
		//Hello
		if(command != 1)
			send_error(client, seq);
		else
		{	
			
			//Send hello
			msg = Message(seq, 2,"");
			msg.pack();
			client.send(msg.to_string());

			std::string out;
			
			//Deliver
			command = 3;
			while(command == 3 && error_flag == 0)
			{
				Message msg = Message::get_msg(client);
				command = msg.get_command();
				if(msg.get_seq() != seq+1)
				{
					send_error(client,seq);
					error_flag = 1;
					msg.print();
				}
				seq = msg.get_seq();
				if(command == 3 && error_flag == 0)
					out += msg.get_data();
			}
			//Store
			if(command != 4 || error_flag == 1)
				send_error(client,seq);
			else
			{
				std::ofstream fout("out.txt");
				fout<<out;
				fout.close();
				client.close();
			}

		} 
	}
	sock.close();
	return 0;
}
