#include <iostream>

#include "Args.hpp"
#include "TicTacToe.hpp"
#include "HumanPlayer.hpp"
#include "RandomPlayer.hpp"
#include "MinimaxPlayer.hpp"
#include "RemotePlayer.hpp"
#include "LocalPlayer.hpp"

#define DEFAULT_PORT 8888

AbstractPlayer* NewPlayer(const std::string& playerType)
{
	AbstractPlayer* player = nullptr;

	if (playerType == "human")
		player = new HumanPlayer();
	else if (playerType == "random")
		player = new RandomPlayer();
	else if (playerType == "minimax")
		player = new MinimaxPlayer();
	else
		player = new HumanPlayer();

	return player;
}

int main(int argc, char** argv)
{
	try
	{
		Args args(argc, argv);

		TicTacToe game;

		AbstractPlayer* player1;
		AbstractPlayer* player2;

		if (args.Has("-host"))
		{
			SocketServer server(DEFAULT_PORT);
			SocketClient client = server.Listen();

			player1 = new LocalPlayer(client);
			player2 = new RemotePlayer(client);
		}
		else if (args.Has("-join"))
		{
			SocketClient client;
			client.Connect(args.ValueOf("-join"), DEFAULT_PORT);

			player1 = new RemotePlayer(client);
			player2 = new LocalPlayer(client);
		}
		else
		{
			player1 = NewPlayer(args.ValueOf("-p1"));
			player2 = NewPlayer(args.ValueOf("-p2"));
		}

		game.Play(*player1, *player2);

		std::cout << "Player " << game.GetWinner() << " won." << std::endl;

		delete player1;
		delete player2;
	}
	catch (std::exception& e)
	{
		std::cerr << "An unexpected error occured: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}