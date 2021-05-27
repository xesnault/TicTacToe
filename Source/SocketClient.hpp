#pragma once

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "Exception.hpp"

class SocketClient
{
	public:

	SocketClient(int sockFd, sockaddr_in addr) : sockFd(sockFd), addr(addr)
	{

	}

	SocketClient()
	{
		
	}

	void Connect(std::string serverIp, int serverPort)
	{
		std::cout << "Connecting to " << serverIp << ":" << serverPort << std::endl;
		sockFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		addr.sin_family = AF_INET;
		addr.sin_port = htons(serverPort);
		addr.sin_addr.s_addr = inet_addr(serverIp.c_str());

		if (connect(sockFd, (sockaddr*) &addr, sizeof(addr)) == -1)
			throw Exception("Connect error");

		std::cout << "Connected" << std::endl;
	}

	void SendMessage(std::string message)
	{
		write(sockFd, message.c_str(), message.length());
	}

	template<class T>
	void SendStruct(T s)
	{
		write(sockFd, &s, sizeof(s));
	}

	std::string WaitMessage()
	{
		size_t size = read(sockFd, buffer, 256);
		buffer[size] = '\0';
		return buffer;
	}

	template<class T>
	T WaitStruct()
	{
		T s;
		read(sockFd, &s, sizeof(s));
		return s;
	}

	private:

	char buffer[256];
	int sockFd;
	sockaddr_in addr;
};