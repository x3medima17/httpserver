#pragma once
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
#include <memory>

class Socket {
private:
	enum socket_types {CLIENT, SERVER};
	socket_types socket_type;
	int port, n;
	sockaddr_in serv_addr, cli_addr;
	hostent* server;
        int sockfd;

	void create_base();
	
public:

	Socket(int port);
	Socket(std::string host, int port);
	Socket();
	void bind();
	void listen(int n);
	void connect();
        std::shared_ptr<Socket> accept();
	std::pair<int, std::string> recv(int length);
        int send(std::string msg);

        std::string get_remote_ip() const;
        int get_remote_port() const;
        int get_fd() const;

	void close();
	
        ~Socket();

        Socket(const Socket&) = delete;
        Socket& operator=(const Socket&) = delete;
};
