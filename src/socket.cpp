#include "socket.h"
#include <string>
#include <iostream>


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
        	error("ERROR opening socket");
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
	//this->host = host;
	this->socket_type = Socket::CLIENT;
	this->create_base();
	
	this->server = gethostbyname((char *)host.c_str());
    	if(this->server == NULL) {
        	std::cout<<("ERROR, no such host\n");
        	exit(1);
    	}

    	bzero((char *) &(this->serv_addr), sizeof(this->serv_addr));
 	this->serv_addr.sin_family = AF_INET;
    	bcopy((char *)(this->server->h_addr), 
          (char *)&(this->serv_addr.sin_addr.s_addr),
          this->server->h_length);
    	this->serv_addr.sin_port = htons(port);
	
}


void Socket::bind()
{
	if (bind(this->sockfd, (struct sockaddr *) &(this->serv_addr),
	    sizeof(this->serv_addr)) < 0) 
		std::cout<<("ERROR on binding\n");
}


void Socket::listen(int n)
{
	listen(this->sockfd, n);
}


Socket Socket::accept()
{

	Socket client_socket;
	
	Socket::socklen_t clilen;
	clilen = sizeof(sock->cli_addr);
	
	client_socket->sockfd  = accept(this->sockfd, 
	(struct sockaddr *) &(this->cli_addr), 
                 &clilen);
	if (client_socket->sockfd < 0) 
		error("ERROR on accept");
	
	return client_socket;

}






