#ifndef SOKET_H_
#define SCOKET_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string>
#include <utility>


class Socket {
protected:
	enum socket_types {CLIENT, SERVER};
	socket_types socket_type;
	int sockfd, port, n;
	sockaddr_in serv_addr, cli_addr;
	hostent* server;

	void create_base();
	~Socket();
public:
	Socket(int port);
	Socket(std::string host, int port);
	Socket();
	void bind();
	void listen(int n);
	void connect();
	Socket accept();
	/*std::pair<int, std::string> recv(int length);
	int send(std::string msg);
	void close();
	*/


};

#endif
