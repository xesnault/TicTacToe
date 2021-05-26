#pragma once

#include <iostream>

#include "Board.hpp"
#include "AbstractPlayer.hpp"

class TicTacToe
{
	public:

	void Play(AbstractPlayer& player1, AbstractPlayer& player2)
	{
		int slot;
	
		while (!IsGameFinished())
		{
			std::cout << "Player " << currentPlayer << ": " << std::endl;

			Position pos;
			if (currentPlayer == CROSS)
				pos = player1.Play(board, CROSS, CIRCLE);
			else
				pos = player2.Play(board, CIRCLE, CROSS);

			if (board(pos.x, pos.y) != EMPTY)
			{
				std::cout << "This slot is already used!" << std::endl;
				continue ;
			}

			board(pos.x, pos.y) = currentPlayer;
			board.Print();
			currentPlayer = currentPlayer == CROSS ? CIRCLE : CROSS;
		}
	}

	bool IsGameFinished() const
	{
		return board.IsFull() || board.CheckIfPlayerWon(CROSS) || board.CheckIfPlayerWon(CIRCLE);
	}

	char GetWinner() const
	{
		if (board.CheckIfPlayerWon(CROSS))
			return CROSS;
		if (board.CheckIfPlayerWon(CIRCLE))
			return CIRCLE;
		return EMPTY;
	}

	private:

	Board board;
	char currentPlayer = CROSS;
};