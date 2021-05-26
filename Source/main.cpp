#include <cstring>

#include "Args.hpp"
#include "TicTacToe.hpp"
#include "HumanPlayer.hpp"
#include "RandomPlayer.hpp"
#include "MinimaxPlayer.hpp"

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

		AbstractPlayer* player1 = NewPlayer(args.ValueOf("-p1"));
		AbstractPlayer* player2 = NewPlayer(args.ValueOf("-p2"));

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