#pragma once

#include <iostream>
#include <memory>

#include "SocketServer.hpp"
#include "SocketClient.hpp"

#include "AbstractPlayer.hpp"

class RemotePlayer : public AbstractPlayer
{

	public:

	RemotePlayer(SocketClient& clientSock) : clientSock(clientSock)
	{
		
	}

	virtual Position Play(const Board& board, char me, char opponent)
	{
		std::cout << "Waiting for your opponent" << std::endl;
		Position pos = clientSock.WaitStruct<Position>();
		return pos;
	}

	private:

	SocketClient clientSock;
};