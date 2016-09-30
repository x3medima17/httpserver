
#include <string>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdexcept>
#include "socket.h"
#include <utility>
#include <vector>


void error(std::string msg)
{
	std::cout<<(msg)<<'\n';
	exit(1);
}


void Socket::create_base()
{
	this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	this->port = port;

	if (this->sockfd < 0) 
        	throw std::runtime_error("ERROR opening socket");
}

Socket::Socket(int port)
{
	this->port = port;
	this->socket_type = Socket::SERVER;
	this->create_base();
	bzero((char *) &(this->serv_addr), sizeof(this->serv_addr));
	this->serv_addr.sin_family = AF_INET;
	this->serv_addr.sin_addr.s_addr = INADDR_ANY;
	this->serv_addr.sin_port = htons(this->port);
}

Socket::Socket()
{
	this->socket_type = Socket::CLIENT;
}

Socket::Socket(std::string host, int port)
{
	this->port = port;
	this->socket_type = Socket::CLIENT;
	this->create_base();
	
	this->server = gethostbyname((char *)host.c_str());
    	if(this->server == NULL) 
        	throw std::runtime_error("ERROR, no such host");

    	bzero((char *) &(this->serv_addr), sizeof(this->serv_addr));
 	this->serv_addr.sin_family = AF_INET;
    	bcopy((char *)(this->server->h_addr), 
          (char *)&(this->serv_addr.sin_addr.s_addr),
          this->server->h_length);
    	this->serv_addr.sin_port = htons(port);
	
}


void Socket::bind()
{
	if(this->socket_type != Socket::SERVER)
		throw std::runtime_error("Only server can invoke bind()");
	if (::bind(this->sockfd, (struct sockaddr *) &(this->serv_addr),
	    sizeof(this->serv_addr)) < 0) 
		throw std::runtime_error("ERROR on binding");
}


void Socket::listen(int n)
{
	if(this->socket_type != Socket::SERVER)
		throw std::runtime_error("Only server can invoke listen()");
	::listen(this->sockfd, n);
}

void Socket::connect()
{
	if(this->socket_type != Socket::CLIENT) 
		throw std::runtime_error("Only client can invoke connect()");
	if (::connect(this->sockfd,(struct sockaddr *) &(this->serv_addr),sizeof(this->serv_addr)) < 0)
        	throw std::runtime_error("ERROR connecting");

}

Socket Socket::accept()
{

	if(this->socket_type != Socket::SERVER) 
		throw std::runtime_error("Only server can invoke accept()");
	Socket client_socket;
	
	socklen_t clilen;
	clilen = sizeof(this->cli_addr);
	
	client_socket.sockfd  = ::accept(this->sockfd, 
	(struct sockaddr *) &(this->cli_addr), 
                 &clilen);
	if (client_socket.sockfd < 0) 
		throw std::runtime_error("ERROR on accept");
	
	return client_socket;

}

#include <cassert>
std::pair<int, std::string> Socket::recv(int length)
{
	assert(length >= 0);
	if(length == 0)
		return std::make_pair(0, "");
	std::vector<char> buff(length);
	int n = ::recv(this->sockfd, buff.data() ,length, 0);
   	if (n < 0){
        	throw std::runtime_error("ERROR reading from socket");
	}

	std::string s(buff.begin(), buff.end());
    	return std::make_pair(n, s);


}

int Socket::send(std::string msg)
{
	char* buffer = (char*)msg.c_str();
	
	int n = ::write(this->sockfd, buffer , msg.length());
    	if (n < 0){
        	throw std::runtime_error("ERROR writing to socket");
	}

    	return n;
}


void Socket::close()
{
	::close(this->sockfd);
}

Socket::~Socket()
{
	this->close();
}


