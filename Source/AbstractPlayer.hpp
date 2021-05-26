#pragma once

#include "Board.hpp"

class AbstractPlayer
{

	public:

	virtual Position Play(const Board& board, char me, char opponent) = 0;
};