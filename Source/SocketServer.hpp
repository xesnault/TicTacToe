#pragma once

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "SocketClient.hpp"
#include "Exception.hpp"

class SocketServer
{
	public:

	SocketServer(int serverPort)
	{
		sockFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(serverPort);
		addr.sin_addr.s_addr = INADDR_ANY;

		if (bind(sockFd, (sockaddr*) &addr, sizeof(addr)) != 0)
			throw Exception("Bind error");

		if (listen(sockFd, 1) != 0)
			throw Exception("Listen error");
	}

	SocketClient Listen()
	{
		int clientSockFd;
		sockaddr_in clientAddr;
		unsigned int clientAddrLen = sizeof(clientAddr);
		if ((clientSockFd = accept(sockFd, (sockaddr *) &clientAddr, &clientAddrLen)) == -1)
			throw Exception("Accept error");

		char ip[INET_ADDRSTRLEN];
		inet_ntop(AF_INET, &(clientAddr.sin_addr), ip, INET_ADDRSTRLEN);
		std::cout << "Connection from " << ip << std::endl;

		SocketClient clientSocket(clientSockFd, clientAddr);

		return clientSocket;
	}

	private:

	int sockFd;
};