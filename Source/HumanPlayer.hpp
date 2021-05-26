#pragma once

#include <iostream>
#include <limits>

#include "AbstractPlayer.hpp"

class HumanPlayer : public AbstractPlayer
{

	public:

	virtual Position Play(const Board& board, char me, char opponent)
	{
		int slot = -1;

		while (slot < 1 || slot > 9)
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			std::cin >> slot;
		}

		slot = slot - 1;
		Position pos = {slot % COLUMN_COUNT, slot / LINE_COUNT};

		return pos;
	}
};