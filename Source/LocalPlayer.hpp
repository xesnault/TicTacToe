#pragma once

#include <iostream>
#include <memory>

#include "SocketServer.hpp"
#include "SocketClient.hpp"

#include "HumanPlayer.hpp"

class LocalPlayer : public HumanPlayer
{

	public:

	LocalPlayer(SocketClient& clientSock) : clientSock(clientSock)
	{
		
	}

	virtual Position Play(const Board& board, char me, char opponent)
	{
		std::cout << "It's your turn" << std::endl;

		Position pos = HumanPlayer::Play(board, me, opponent);
		clientSock.SendStruct<Position>(pos);

		return pos;
	}

	private:

	SocketClient clientSock;
};