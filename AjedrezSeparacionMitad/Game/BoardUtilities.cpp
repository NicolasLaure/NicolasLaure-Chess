#include "BoardUtilities.h"

void PrintBoard(Board board)
{
	COORD coordinates = { 0,0 };
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, coordinates);
	COORD pos = { coordinates.X , coordinates.Y };

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			for (int k = 0; k < height; k++)
			{
				for (int w = 0; w < width; w++)
				{
					if (board.panel[i][j].colour == Colors::White)
					{
						SetConsoleTextAttribute(handle, 6);
						cout << (char)219;
					}
					else
					{
						SetConsoleTextAttribute(handle, 0);
						cout << (char)219;
					}

					coordinates.X++;
					SetConsoleCursorPosition(handle, coordinates);
				}
				coordinates.X = pos.X;
				coordinates.Y++;
				SetConsoleCursorPosition(handle, coordinates);
			}
			pos.X += width;
			coordinates.X = pos.X;
			coordinates.Y = pos.Y;
			SetConsoleCursorPosition(handle, coordinates);

		}
		pos.Y += height;
		coordinates.Y = pos.Y;
		pos.X = 0;
		coordinates.X = pos.X;
		SetConsoleCursorPosition(handle, coordinates);
	}
}