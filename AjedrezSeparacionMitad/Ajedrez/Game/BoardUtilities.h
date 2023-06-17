#pragma once
#include "Utilities.h"
#include <Windows.h>
struct Board
{

	struct Tile
	{
		Colors colour{};
	};

	Tile panel[BOARD_SIZE][BOARD_SIZE];

	void SetBoard()
	{
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			for (int j = 0; j < BOARD_SIZE; j++)
			{

				if (i % 2 == 0 || i == 0)
				{
					if (j % 2 == 0 || j == 0)
						panel[i][j].colour = Colors::White;
					else
						panel[i][j].colour = Colors::Black;
				}
				else
				{
					if (j % 2 == 0 || j == 0)
						panel[i][j].colour = Colors::Black;
					else
						panel[i][j].colour = Colors::White;
				}
			}
		}
	}
};

void PrintBoard(Board board);
