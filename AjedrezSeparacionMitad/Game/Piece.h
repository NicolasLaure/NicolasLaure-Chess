#pragma once

#include "Utilities.h"
#include <iostream>
using namespace std;

enum class Pieces
{
	King,
	Queen,
	Bishop1,
	Bishop2,
	Knight1,
	Knight2,
	Rook1,
	Rook2,
	Pawn1,
	Pawn2,
	Pawn3,
	Pawn4,
	Pawn5,
	Pawn6,
	Pawn7,
	Pawn8,
};
enum class Directions
{
	Down,
	Up,
	Left,
	Right,
	DownLeft,
	DownRight,
	UpLeft,
	UpRight,
	L_DownLeft,
	L_DownRight,
	L_UpLeft,
	L_UpRight,
	L_LeftUp,
	L_LeftDown,
	L_RightUp,
	L_RightDown,
};

struct Piece
{
public:
	Colors colour{};
	Vector2 position{};
	string graphic{};
	bool isAlive{};
	bool firstTurn = true;

	int DirectionCheck(string piece, Piece ownTeam[], Piece enemyTeam[], Directions direction)
	{
		bool hasLimit = false;
		int lastPossibleMove = 0;
		bool foundLastPossible = false;
		bool canMove = true;
		if (piece == "WK" || piece == "BK")
		{
			hasLimit = true;
			lastPossibleMove = 1;
		}
		else if (piece == "k1" || piece == "k2" || piece == "Wk" || piece == "Bk")
			lastPossibleMove = 1;

		switch (direction)
		{
		case Directions::Down:
			if (hasLimit)
			{
				for (int i = 0; i < TEAM_SIZE; i++)
				{

					if (position.y + 1 == ownTeam[i].position.y && position.x == ownTeam[i].position.x || position.y == 7)
					{
						lastPossibleMove = 0;
						break;
					}
				}
			}
			else
			{
				for (int down = 1; down <= 7 - position.y; down++)
				{
					for (int i = 0; i < TEAM_SIZE; i++)
					{
						if (piece != "p" && piece != "P")
						{
							if (position.y + down == ownTeam[i].position.y && position.x == ownTeam[i].position.x)
							{
								lastPossibleMove = (ownTeam[i].position.y - 1) - position.y;
								foundLastPossible = true;
								break;
							}
							else if (position.y + down == enemyTeam[i].position.y && position.x == enemyTeam[i].position.x)
							{
								lastPossibleMove = enemyTeam[i].position.y - position.y;
								foundLastPossible = true;
								break;
							}
						}
						else
						{
							if (position.y + down == ownTeam[i].position.y && position.x == ownTeam[i].position.x)
							{
								lastPossibleMove = (ownTeam[i].position.y - 1) - position.y;
								foundLastPossible = true;
								break;
							}
							else if (position.y + down == enemyTeam[i].position.y && position.x == enemyTeam[i].position.x)
							{
								lastPossibleMove = enemyTeam[i].position.y - position.y;
								foundLastPossible = true;
								break;
							}
						}
					}
					if (foundLastPossible)
						break;
				}
				if (!foundLastPossible)
					lastPossibleMove = 7 - position.y;
			}
			break;
		case Directions::Up:
			if (hasLimit)
			{
				for (int i = 0; i < TEAM_SIZE; i++)
				{
					if (position.y - 1 == ownTeam[i].position.y && position.x == ownTeam[i].position.x || position.y == 0)
					{
						lastPossibleMove = 0;
						break;
					}
				}
			}
			else
			{
				for (int up = 1; up <= 0 + position.y; up++)
				{
					for (int i = 0; i < TEAM_SIZE; i++)
					{
						if (piece != "p" && piece != "P")
						{
							if (position.y - up == ownTeam[i].position.y && position.x == ownTeam[i].position.x)
							{
								lastPossibleMove = position.y - (ownTeam[i].position.y + 1);
								foundLastPossible = true;
								break;
							}
							else if (position.y - up == enemyTeam[i].position.y && position.x == enemyTeam[i].position.x)
							{
								lastPossibleMove = position.y - enemyTeam[i].position.y;
								foundLastPossible = true;
								break;
							}
						}
						else
						{
							if (position.y - up == ownTeam[i].position.y && position.x == ownTeam[i].position.x)
							{
								lastPossibleMove = position.y - (ownTeam[i].position.y + 1);
								foundLastPossible = true;
								break;
							}
							else if (position.y - up == enemyTeam[i].position.y && position.x == enemyTeam[i].position.x)
							{
								lastPossibleMove = position.y - enemyTeam[i].position.y + 1;
								foundLastPossible = true;
								break;
							}
						}

					}
					if (foundLastPossible)
						break;
				}
				if (!foundLastPossible)
					lastPossibleMove = 0 + position.y;
			}
			break;
		case Directions::Left:
			if (hasLimit)
			{
				for (int i = 0; i < TEAM_SIZE; i++)
				{
					if (position.x - 1 == ownTeam[i].position.x && position.y == ownTeam[i].position.y || position.x == 0)
					{
						lastPossibleMove = 0;
						break;
					}
				}
			}
			else
			{
				for (int left = 1; left <= 0 + position.x; left++)
				{
					for (int i = 0; i < TEAM_SIZE; i++)
					{
						if (position.x - left == ownTeam[i].position.x && position.y == ownTeam[i].position.y)
						{
							lastPossibleMove = position.x - (ownTeam[i].position.x + 1);
							foundLastPossible = true;
							break;
						}
						else if (position.x - left == enemyTeam[i].position.x && position.y == enemyTeam[i].position.y)
						{
							lastPossibleMove = position.x - enemyTeam[i].position.x;
							foundLastPossible = true;
							break;
						}
					}
					if (foundLastPossible)
						break;
				}
				if (!foundLastPossible)
					lastPossibleMove = 0 + position.x;
			}
			break;
		case Directions::Right:
			if (hasLimit)
			{
				for (int i = 0; i < TEAM_SIZE; i++)
				{
					if (position.x + 1 == ownTeam[i].position.x && position.y == ownTeam[i].position.y || position.x == 7)
					{
						lastPossibleMove = 0;
						break;
					}
				}
			}
			else
			{
				for (int right = 1; right <= 7 - position.x; right++)
				{
					for (int i = 0; i < TEAM_SIZE; i++)
					{
						if (position.x + right == ownTeam[i].position.x && position.y == ownTeam[i].position.y)
						{
							lastPossibleMove = (ownTeam[i].position.x - 1) - position.x;
							foundLastPossible = true;
							break;
						}
						else if (position.x + right == enemyTeam[i].position.x && position.y == enemyTeam[i].position.y)
						{
							lastPossibleMove = enemyTeam[i].position.x - position.x;
							foundLastPossible = true;
							break;
						}
					}
					if (foundLastPossible)
						break;
				}
				if (!foundLastPossible)
					lastPossibleMove = 7 - position.x;
			}
			break;
		case Directions::DownLeft:
			if (hasLimit)
			{
				for (int i = 0; i < TEAM_SIZE; i++)
				{

					if (position.y + 1 == ownTeam[i].position.y && position.x - 1 == ownTeam[i].position.x || position.x == 0 || position.y == 7)
					{
						lastPossibleMove = 0;
						break;
					}
				}
			}
			else
			{
				for (int downLeft = 1; downLeft <= 7 - position.y; downLeft++)
				{
					for (int i = 0; i < TEAM_SIZE; i++)
					{
						if (position.y + downLeft == ownTeam[i].position.y && position.x - downLeft == ownTeam[i].position.x)
						{
							lastPossibleMove = (ownTeam[i].position.y - 1) - position.y;
							foundLastPossible = true;
							break;
						}
						else if (position.y + downLeft == enemyTeam[i].position.y && position.x - downLeft == enemyTeam[i].position.x)
						{
							lastPossibleMove = enemyTeam[i].position.y - position.y;
							foundLastPossible = true;
							break;
						}
					}
					if (foundLastPossible)
						break;
				}
				if (!foundLastPossible)
				{
					if (position.x < BOARD_SIZE - position.y)
						lastPossibleMove = 0 + position.x;
					else
						lastPossibleMove = 7 - position.y;
				}
			}
			break;
		case Directions::DownRight:
			if (hasLimit)
			{
				for (int i = 0; i < TEAM_SIZE; i++)
				{
					if (position.y + 1 == ownTeam[i].position.y && position.x + 1 == ownTeam[i].position.x || position.x == 7 || position.y == 7)
					{
						lastPossibleMove = 0;
						break;
					}
				}
			}
			else
			{
				for (int downRight = 1; downRight <= 7 - position.y; downRight++)
				{
					for (int i = 0; i < TEAM_SIZE; i++)
					{
						if (position.y + downRight == ownTeam[i].position.y && position.x + downRight == ownTeam[i].position.x)
						{
							lastPossibleMove = (ownTeam[i].position.y - 1) - position.y;
							foundLastPossible = true;
							break;
						}
						else if (position.y + downRight == enemyTeam[i].position.y && position.x + downRight == enemyTeam[i].position.x)
						{
							lastPossibleMove = enemyTeam[i].position.y - position.y;
							foundLastPossible = true;
							break;
						}
					}
					if (foundLastPossible)
						break;
				}
				if (!foundLastPossible)
				{
					if (position.x > position.y)
						lastPossibleMove = 7 - position.x;
					else
						lastPossibleMove = 7 - position.y;
				}
			}
			break;
		case Directions::UpLeft:
			if (hasLimit)
			{
				for (int i = 0; i < TEAM_SIZE; i++)
				{
					if (position.y - 1 == ownTeam[i].position.y && position.x - 1 == ownTeam[i].position.x || position.x == 0 || position.y == 0)
					{
						lastPossibleMove = 0;
						break;
					}
				}
			}
			else
			{
				for (int upLeft = 1; upLeft <= 0 + position.y; upLeft++)
				{
					for (int i = 0; i < TEAM_SIZE; i++)
					{
						if (position.y - upLeft == ownTeam[i].position.y && position.x - upLeft == ownTeam[i].position.x)
						{
							lastPossibleMove = position.y - (ownTeam[i].position.y + 1);
							foundLastPossible = true;
							break;
						}
						else if (position.y - upLeft == enemyTeam[i].position.y && position.x - upLeft == enemyTeam[i].position.x)
						{
							lastPossibleMove = position.y - enemyTeam[i].position.y;
							foundLastPossible = true;
							break;
						}
					}
					if (foundLastPossible)
						break;
				}
				if (!foundLastPossible)
				{
					if (position.x < position.y)
						lastPossibleMove = 0 + position.x;
					else
						lastPossibleMove = 0 + position.y;
				}
			}
			break;
		case Directions::UpRight:
			if (hasLimit)
			{
				for (int i = 0; i < TEAM_SIZE; i++)
				{
					if (position.y - 1 == ownTeam[i].position.y && position.x + 1 == ownTeam[i].position.x || position.x == 7 || position.y == 0)
					{
						lastPossibleMove = 0;
						break;
					}
				}
			}
			else
			{
				for (int upRight = 1; upRight <= 0 + position.y; upRight++)
				{
					for (int i = 0; i < TEAM_SIZE; i++)
					{
						if (position.y - upRight == ownTeam[i].position.y && position.x + upRight == ownTeam[i].position.x)
						{
							lastPossibleMove = position.y - (ownTeam[i].position.y + 1);
							foundLastPossible = true;
							break;
						}
						else if (position.y - upRight == enemyTeam[i].position.y && position.x + upRight == enemyTeam[i].position.x)
						{
							lastPossibleMove = position.y - enemyTeam[i].position.y;
							foundLastPossible = true;
							break;
						}
					}
					if (foundLastPossible)
						break;
				}
				if (!foundLastPossible)
				{
					if (position.x > BOARD_SIZE - position.y)
						lastPossibleMove = 7 - position.x;
					else
						lastPossibleMove = 0 + position.y;
				}
			}
			break;
		case Directions::L_DownLeft:
			for (int i = 0; i < TEAM_SIZE; i++)
			{
				if (position.y + 2 == ownTeam[i].position.y && position.x - 1 == ownTeam[i].position.x || position.y + 2 > 7 || position.x - 1 < 0)
				{
					lastPossibleMove = 0;
				}
			}
			break;
		case Directions::L_DownRight:
			for (int i = 0; i < TEAM_SIZE; i++)
			{
				if (position.y + 2 == ownTeam[i].position.y && position.x + 1 == ownTeam[i].position.x || position.y + 2 > 7 || position.x + 1 > 7)
				{
					lastPossibleMove = 0;
				}
			}
			break;
		case Directions::L_UpLeft:
			for (int i = 0; i < TEAM_SIZE; i++)
			{
				if (position.y - 2 == ownTeam[i].position.y && position.x - 1 == ownTeam[i].position.x || position.y - 2 < 0 || position.x - 1 < 0)
				{
					lastPossibleMove = 0;
				}
			}
			break;
		case Directions::L_UpRight:
			for (int i = 0; i < TEAM_SIZE; i++)
			{
				if (position.y - 2 == ownTeam[i].position.y && position.x + 1 == ownTeam[i].position.x || position.y - 2 < 0 || position.x + 1 > 7)
				{
					lastPossibleMove = 0;
				}
			}
			break;
		case Directions::L_LeftDown:
			for (int i = 0; i < TEAM_SIZE; i++)
			{
				if (position.x - 2 == ownTeam[i].position.x && position.y + 1 == ownTeam[i].position.y || position.x - 2 < 0 || position.y + 1 > 7)
				{
					lastPossibleMove = 0;
				}
			}
			break;
		case Directions::L_LeftUp:
			for (int i = 0; i < TEAM_SIZE; i++)
			{
				if (position.x - 2 == ownTeam[i].position.x && position.y - 1 == ownTeam[i].position.y || position.x - 2 < 0 || position.y - 1 < 0)
				{
					lastPossibleMove = 0;
				}
			}
			break;
		case Directions::L_RightDown:
			for (int i = 0; i < TEAM_SIZE; i++)
			{
				if (position.x + 2 == ownTeam[i].position.x && position.y + 1 == ownTeam[i].position.y || position.x + 2 > 7 || position.y + 1 > 7)
				{
					lastPossibleMove = 0;
				}
			}
			break;
		case Directions::L_RightUp:
			for (int i = 0; i < TEAM_SIZE; i++)
			{
				if (position.x + 2 == ownTeam[i].position.x && position.y - 1 == ownTeam[i].position.y || position.x + 2 > 7 || position.y - 1 < 0)
				{
					lastPossibleMove = 0;
				}
			}
			break;
		}
		return lastPossibleMove;
	}

	void MoveDownLeft(int lastPossibleMoveDown)
	{

		int response = 0;
		switch (lastPossibleMoveDown)
		{
		case 1:
			position.y++;
			position.x--;
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			cout << "Seleccione cuantos movimientos hacia abajo a la izquierda quiere realizar entre 1 y " << lastPossibleMoveDown << " --> ";
			response = PromptInput(1, lastPossibleMoveDown);
			position.y += response;
			position.x -= response;
			break;
		default:
			break;
		}
	}
	void MoveDownRight(int lastPossibleMoveDown)
	{

		int response = 0;
		switch (lastPossibleMoveDown)
		{
		case 1:
			position.y++;
			position.x++;
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			cout << "Seleccione cuantos movimientos hacia abajo a la derecha quiere realizar entre 1 y " << lastPossibleMoveDown << " --> ";
			response = PromptInput(1, lastPossibleMoveDown);
			position.y += response;
			position.x += response;
			break;
		}
	}
	void MoveUpLeft(int lastPossibleMoveDown)
	{

		int response = 0;
		switch (lastPossibleMoveDown)
		{
		case 1:
			position.y--;
			position.x--;
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			cout << "Seleccione cuantos movimientos hacia arriba a la izquierda quiere realizar entre 1 y " << lastPossibleMoveDown << " --> ";
			response = PromptInput(1, lastPossibleMoveDown);
			position.y -= response;
			position.x -= response;
			break;
		}
	}
	void MoveUpRight(int lastPossibleMoveDown)
	{

		int response = 0;
		switch (lastPossibleMoveDown)
		{
		case 1:
			position.y--;
			position.x++;
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			cout << "Seleccione cuantos movimientos hacia arriba a la derecha quiere realizar entre 1 y " << lastPossibleMoveDown << " --> ";
			response = PromptInput(1, lastPossibleMoveDown);
			position.y -= response;
			position.x += response;
			break;
		}
	}
	void MoveDown(int lastPossibleMoveDown)
	{

		int response = 0;
		switch (lastPossibleMoveDown)
		{
		case 1:
			position.y++;
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			cout << "Seleccione cuantos movimientos hacia abajo quiere realizar entre 1 y " << lastPossibleMoveDown << " --> ";
			response = PromptInput(1, lastPossibleMoveDown);
			position.y += response;
			break;
		default:
			break;
		}
	}
	void MoveUp(int lastPossibleMoveDown)
	{

		int response = 0;
		switch (lastPossibleMoveDown)
		{
		case 1:
			position.y--;
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			cout << "Seleccione cuantos movimientos hacia arriba quiere realizar entre 1 y " << lastPossibleMoveDown << " --> ";
			response = PromptInput(1, lastPossibleMoveDown);
			position.y -= response;
			break;
		}
	}
	void MoveLeft(int lastPossibleMoveDown)
	{

		int response = 0;
		switch (lastPossibleMoveDown)
		{
		case 1:
			position.x--;
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			cout << "Seleccione cuantos movimientos hacia la izquierda quiere realizar entre 1 y " << lastPossibleMoveDown << " --> ";
			response = PromptInput(1, lastPossibleMoveDown);
			position.x -= response;
			break;
		}
	}
	void MoveRight(int lastPossibleMoveDown)
	{

		int response = 0;
		switch (lastPossibleMoveDown)
		{
		case 1:
			position.x++;
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			cout << "Seleccione cuantos movimientos hacia la derecha quiere realizar entre 1 y " << lastPossibleMoveDown << " --> ";
			response = PromptInput(1, lastPossibleMoveDown);
			position.x += response;
			break;
		}
	}
};






