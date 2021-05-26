#pragma once

#include <iostream>

#include "AbstractPlayer.hpp"

class MinimaxPlayer : public AbstractPlayer
{

	public:

	virtual Position Play(const Board& board, char me, char opponent)
	{
		this->me = me;
		this->opponent = opponent;

		Board simulationBoard = board;
		Position bestPos;
		int bestScore = -999;

		for (int y = 0; y < LINE_COUNT; ++y)
		{
			for (int x = 0; x < COLUMN_COUNT; ++x)
			{
				if (simulationBoard(x, y) == EMPTY)
				{
					simulationBoard(x, y) = me;
					int score = Minimax(simulationBoard, false);
					simulationBoard(x, y) = EMPTY;

					if (score > bestScore)
					{
						bestScore = score;
						bestPos = {x, y};
					}
				}
			}
		}
		return bestPos;
	}

	int Minimax(Board& board, bool isMaximazing)
	{
		if (board.CheckIfPlayerWon(me))
			return 10;
		
		if (board.CheckIfPlayerWon(opponent))
			return -10;

		if (board.IsFull())
			return 0;

		int bestScore = isMaximazing ? -999 : 999;

		for (int y = 0; y < LINE_COUNT; ++y)
		{
			for (int x = 0; x < COLUMN_COUNT; ++x)
			{
				if (board(x, y) == EMPTY)
				{
					board(x, y) = isMaximazing ? me : opponent;
					int score = Minimax(board, !isMaximazing);
					board(x, y) = EMPTY;

					if (isMaximazing && score > bestScore)
						bestScore = score;

					if (!isMaximazing && score < bestScore)
						bestScore = score;
				}
			}
		}

		return bestScore;
	}

	private:

	char me, opponent;
};