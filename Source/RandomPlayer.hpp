#pragma once

#include <cstdlib>
#include <ctime>

#include "AbstractPlayer.hpp"

class RandomPlayer : public AbstractPlayer
{

	public:

	RandomPlayer()
	{
		std::srand(std::time(nullptr));
	}

	virtual Position Play(const Board& board, char me, char opponent)
	{
		int slot = -1;
		Position pos;

		while (slot < 0 || slot > 8)
		{
			slot = std::rand() % 9;
			pos = {slot % COLUMN_COUNT, slot / LINE_COUNT};
			if (board(pos.x, pos.y) != EMPTY)
				slot = -1;
		}
		return pos;
	}
};