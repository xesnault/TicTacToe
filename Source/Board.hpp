#pragma once

#include <iostream>

#define LINE_COUNT 3
#define COLUMN_COUNT 3

#define EMPTY '.'
#define CROSS 'X' // Player 1
#define CIRCLE 'O' // Player 2

struct Position
{
	int x;
	int y;
};

class Board
{
	public:

	void Print() const
	{
		for (int y = 0; y < LINE_COUNT; ++y)
		{
			for (int x = 0; x < COLUMN_COUNT; ++x)
			{
				std::cout << board[x][y] << " ";
			}
			std::cout << std::endl;
		}
	}

	bool IsFull() const
	{
		for (int y = 0; y < LINE_COUNT; ++y)
		{
			for (int x = 0; x < COLUMN_COUNT; ++x)
			{
				if (board[x][y] == EMPTY)
					return false;
			}
		}
		return true;
	}

	int GetFreeSlotCount() const
	{
		int count = 0;
		for (int y = 0; y < LINE_COUNT; ++y)
		{
			for (int x = 0; x < COLUMN_COUNT; ++x)
			{
				if (board[x][y] == EMPTY)
					++count;
			}
		}
		return count;
	}

	bool CheckIfPlayerWon(int player) const
	{
		// Check lines
		for (int y = 0; y < LINE_COUNT; ++y)
		{
			if (board[0][y] == player && board[1][y] == player && board[2][y] == player)
				return true;
		}

		// Check columns
		for (int x = 0; x < COLUMN_COUNT; ++x)
		{
			if (board[x][0] == player && board[x][1] == player && board[x][2] == player)
				return true;
		}

		// Check diagonal 1
		if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
			return true;

		// Check diagonal 2
		if (board[2][0] == player && board[1][1] == player && board[0][2] == player)
			return true;

		return false;
	}

	char& operator() (int x, int y)
	{
		return board[x][y];
	}

	const char& operator() (int x, int y) const
	{
		return board[x][y];
	}

	private:

	char board[COLUMN_COUNT][LINE_COUNT] = {
		{EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY}
	};
};