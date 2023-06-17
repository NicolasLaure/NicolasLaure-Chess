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

struct King : Piece
{
	void Move(Piece ownTeam[], Piece enemyTeam[])
	{
		int possibleDirections = 0;

		bool canMoveDown = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::Down);
		if (canMoveDown)
		{
			possibleDirections++;
			cout << "Se puede mover hacia abajo" << endl;
		}

		bool canMoveUp = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::Up);
		if (canMoveUp)
		{
			possibleDirections++;
			cout << "Se puede mover hacia arriba" << endl;
		}

		bool canMoveLeft = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::Left);
		if (canMoveLeft)
		{
			possibleDirections++;
			cout << "Se puede mover hacia la izquierda" << endl;
		}

		bool canMoveRight = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::Right);
		if (canMoveRight)
		{
			possibleDirections++;
			cout << "Se puede mover hacia la derecha" << endl;
		}

		bool canMoveUpLeft = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::UpLeft);
		if (canMoveUpLeft)
		{
			possibleDirections++;
			cout << "Se puede mover hacia arriba a la izquierda" << endl;
		}

		bool canMoveUpRight = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::UpRight);
		if (canMoveUpRight)
		{
			possibleDirections++;
			cout << "Se puede mover hacia arriba a la derecha" << endl;
		}

		bool canMoveDownLeft = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::DownLeft);
		if (canMoveDownLeft)
		{
			possibleDirections++;
			cout << "Se puede mover hacia abajo a la izquierda" << endl;
		}

		bool canMoveDownRight = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::DownRight);
		if (canMoveDownRight)
		{
			possibleDirections++;
			cout << "Se puede mover hacia abajo a la derecha" << endl;
		}

		int directionInput = 0;
		switch (possibleDirections)
		{
		case 1:
			if (canMoveDown)
				MoveDown();
			else if (canMoveUp)
				MoveUp();
			else if (canMoveLeft)
				MoveLeft();
			else if (canMoveRight)
				MoveRight();
			else if (canMoveDownLeft)
				MoveDownLeft();
			else if (canMoveDownRight)
				MoveDownRight();
			else if (canMoveUpLeft)
				MoveUpLeft();
			else
				MoveUpRight();
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, Orden:  1.Abajo, 2.Arriba, 3.Izquierda, 4.Derecha, 5.Abajo-Izq, 6.Abajo-Der, 7.Arriba-Izq, 8.Arriba-Der --> ";
			directionInput = PromptInput(1, 8);
			switch (directionInput)
			{
			case 1:
				if (canMoveDown)
					MoveDown();
				break;
			case 2:
				if (canMoveUp)
					MoveUp();
				break;
			case 3:
				if (canMoveLeft)
					MoveLeft();
				break;
			case 4:
				if (canMoveRight)
					MoveRight();
				break;
			case 5:
				if (canMoveDownLeft)
					MoveDownLeft();
				break;
			case 6:
				if (canMoveDownRight)
					MoveDownRight();
				break;
			case 7:
				if (canMoveUpLeft)
					MoveUpLeft();
				break;
			case 8:
				if (canMoveUpRight)
					MoveUpRight();
				break;
			}
			break;
		default:
			break;
		}

		if (possibleDirections == 0)
		{
			cout << "No te podes mover";
			system("pause");
		}

		for (int i = 0; i < TEAM_SIZE; i++)
		{
			if (enemyTeam[i].position.y == position.y && enemyTeam[i].position.x == position.x)
			{
				enemyTeam[i].isAlive = false;
			}
		}
	}
	void MoveDown()
	{
		position.y++;
	}
	void MoveUp()
	{
		position.y--;
	}
	void MoveLeft()
	{
		position.x--;
	}
	void MoveRight()
	{
		position.x++;
	}
	void MoveDownLeft()
	{
		position.y++;
		position.x--;
	}
	void MoveDownRight()
	{
		position.y++;
		position.x++;
	}
	void MoveUpLeft()
	{
		position.y--;
		position.x--;
	}
	void MoveUpRight()
	{
		position.y--;
		position.x++;
	}
};
struct Queen : Piece
{
	void Move(Piece ownTeam[], Piece enemyTeam[])
	{
		int possibleDirections = 0;

		int availableMovesDown = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::Down);
		if (availableMovesDown)
		{
			possibleDirections++;
			cout << "Se puede mover hacia abajo" << endl;
		}

		int availableMovesUp = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::Up);
		if (availableMovesUp)
		{
			possibleDirections++;
			cout << "Se puede mover hacia arriba" << endl;
		}

		int availableMovesLeft = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::Left);
		if (availableMovesLeft)
		{
			possibleDirections++;
			cout << "Se puede mover hacia la izquierda" << endl;
		}

		int availableMovesRight = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::Right);
		if (availableMovesRight)
		{
			possibleDirections++;
			cout << "Se puede mover hacia la derecha" << endl;
		}

		int availableMovesUpLeft = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::UpLeft);
		if (availableMovesUpLeft)
		{
			possibleDirections++;
			cout << "Se puede mover hacia arriba a la izquierda" << endl;
		}

		int availableMovesUpRight = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::UpRight);
		if (availableMovesUpRight)
		{
			possibleDirections++;
			cout << "Se puede mover hacia arriba a la derecha" << endl;
		}

		int availableMovesDownLeft = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::DownLeft);
		if (availableMovesDownLeft)
		{
			possibleDirections++;
			cout << "Se puede mover hacia abajo a la izquierda" << endl;
		}

		int availableMovesDownRight = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::DownRight);
		if (availableMovesDownRight)
		{
			possibleDirections++;
			cout << "Se puede mover hacia abajo a la derecha" << endl;
		}

		int directionInput = 0;
		switch (possibleDirections)
		{
		case 1:
			if (availableMovesDownLeft > 0)
				MoveDownLeft(availableMovesDownLeft);
			else if (availableMovesDownRight > 0)
				MoveDownRight(availableMovesDownRight);
			else if (availableMovesUpLeft > 0)
				MoveUpLeft(availableMovesUpLeft);
			else if (availableMovesUpRight > 0)
				MoveUpRight(availableMovesUpRight);
			else if (availableMovesDown > 0)
				MoveDown(availableMovesDown);
			else if (availableMovesUp > 0)
				MoveUp(availableMovesUp);
			else if (availableMovesLeft > 0)
				MoveLeft(availableMovesLeft);
			else
				MoveRight(availableMovesRight);
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, Orden:  1.Abajo, 2.Arriba, 3.Izquierda, 4.Derecha, 5.Abajo-Izq, 6.Abajo-Der, 7.Arriba-Izq, 8.Arriba-Der --> ";
			directionInput = PromptInput(1, 8);
			switch (directionInput)
			{
			case 1:
				if (availableMovesDown > 0)
					MoveDown(availableMovesDown);
				break;
			case 2:
				if (availableMovesUp > 0)
					MoveUp(availableMovesUp);
				break;
			case 3:
				if (availableMovesLeft > 0)
					MoveLeft(availableMovesLeft);
				break;
			case 4:
				if (availableMovesRight > 0)
					MoveRight(availableMovesRight);
				break;
			case 5:
				if (availableMovesDownLeft > 0)
					MoveDownLeft(availableMovesDownLeft);
				break;
			case 6:
				if (availableMovesDownRight > 0)
					MoveDownRight(availableMovesDownRight);
				break;
			case 7:
				if (availableMovesUpLeft > 0)
					MoveUpLeft(availableMovesUpLeft);
				break;
			case 8:
				if (availableMovesUpRight > 0)
					MoveUpRight(availableMovesUpRight);
				break;
			}
			break;
		default:
			break;
		}

		if (possibleDirections == 0)
		{
			cout << "No te podes mover";
			system("pause");
		}

		for (int i = 0; i < TEAM_SIZE; i++)
		{
			if (enemyTeam[i].position.y == position.y && enemyTeam[i].position.x == position.x)
			{
				enemyTeam[i].isAlive = false;
			}
		}
	}
};
struct Bishop : Piece
{
	void Move(Piece ownTeam[], Piece enemyTeam[])
	{
		int possibleDirections = 0;

		int availableMovesDownLeft = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::DownLeft);
		if (availableMovesDownLeft > 0)
			possibleDirections++;

		int availableMovesDownRight = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::DownRight);
		if (availableMovesDownRight > 0)
			possibleDirections++;

		int availableMovesUpLeft = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::UpLeft);
		if (availableMovesUpLeft > 0)
			possibleDirections++;

		int availableMovesUpRight = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::UpRight);
		if (availableMovesUpRight > 0)
			possibleDirections++;

		int directionInput = 0;
		switch (possibleDirections)
		{
		case 1:
			if (availableMovesDownLeft > 0)
				MoveDownLeft(availableMovesDownLeft);
			else if (availableMovesDownRight > 0)
				MoveDownRight(availableMovesDownRight);
			else if (availableMovesUpLeft > 0)
				MoveUpLeft(availableMovesUpLeft);
			else
				MoveUpRight(availableMovesUpRight);
			break;
		case 2:
			if (availableMovesDownLeft > 0)
			{
				if (availableMovesDownRight > 0)
				{
					cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Abajo-Izq, Abajo-Der  --> ";
					directionInput = PromptInput(1, possibleDirections);
					if (directionInput == 1)
						MoveDownLeft(availableMovesDownLeft);
					else if (directionInput == 2)
						MoveDownRight(availableMovesDownRight);
				}
				else if (availableMovesUpLeft > 0)
				{
					cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Abajo-Izq, Arriba-Izq  --> ";
					directionInput = PromptInput(1, possibleDirections);
					if (directionInput == 1)
						MoveDownLeft(availableMovesDownLeft);
					else if (directionInput == 2)
						MoveUpLeft(availableMovesUpLeft);
				}
				else
				{
					cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Abajo-Izq, Arriba-Der  --> ";
					directionInput = PromptInput(1, possibleDirections);
					if (directionInput == 1)
						MoveDownLeft(availableMovesDownLeft);
					else if (directionInput == 2)
						MoveUpRight(availableMovesUpRight);
				}
			}
			else if (availableMovesDownRight > 0)
			{
				if (availableMovesUpLeft > 0)
				{
					cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Abajo-Der, Arriba-Izq  --> ";
					directionInput = PromptInput(1, possibleDirections);
					if (directionInput == 1)
						MoveDownRight(availableMovesDownRight);
					else if (directionInput == 2)
						MoveUpLeft(availableMovesUpLeft);
				}
				else if (availableMovesUpRight > 0)
				{
					cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Abajo-Der, Arriba-Der  --> ";
					directionInput = PromptInput(1, possibleDirections);
					if (directionInput == 1)
						MoveDownRight(availableMovesDownRight);
					else if (directionInput == 2)
						MoveUpRight(availableMovesUpRight);
				}
			}
			else if (availableMovesUpLeft > 0)
			{
				cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Arriba-Izq, Arriba-Der  --> ";
				directionInput = PromptInput(1, possibleDirections);
				if (directionInput == 1)
					MoveUpLeft(availableMovesUpLeft);
				else if (directionInput == 2)
					MoveUpRight(availableMovesUpRight);
			}
			break;
		case 3:
			if (availableMovesDownLeft > 0)
			{
				if (availableMovesDownRight > 0)
				{
					if (availableMovesUpLeft > 0)
					{
						//Down-Up-Left
						cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Abajo-Izq, Abajo-Der, Arriba-Izq --> ";
						directionInput = PromptInput(1, possibleDirections);
						if (directionInput == 1)
							MoveDownLeft(availableMovesDownLeft);
						else if (directionInput == 2)
							MoveDownRight(availableMovesDownRight);
						else
							MoveUpLeft(availableMovesUpLeft);
					}
					else
					{
						//Down-Up-Right
						cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Abajo-Izq, Abajo-Der, Arriba-Der --> ";
						directionInput = PromptInput(1, possibleDirections);
						if (directionInput == 1)
							MoveDownLeft(availableMovesDownLeft);
						else if (directionInput == 2)
							MoveDownRight(availableMovesDownRight);
						else
							MoveUpRight(availableMovesUpRight);
					}
				}
				else if (availableMovesUpLeft > 0)
				{
					//Down-Left-Right
					cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Abajo-Izq, Arriba-Izq, Arriba-Der --> ";
					directionInput = PromptInput(1, possibleDirections);
					if (directionInput == 1)
						MoveDownLeft(availableMovesDownLeft);
					else if (directionInput == 2)
						MoveUpLeft(availableMovesUpLeft);
					else
						MoveUpRight(availableMovesUpRight);
				}
			}
			else
			{
				//Up-Left-Right
				cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Abajo-Der, Arriba-Izq, Arriba-Der --> ";
				directionInput = PromptInput(1, possibleDirections);
				if (directionInput == 1)
					MoveDownRight(availableMovesDownRight);
				else if (directionInput == 2)
					MoveUpLeft(availableMovesUpLeft);
				else
					MoveUpRight(availableMovesUpRight);
			}
			break;
		case 4:
			cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Abajo-Izq, Abajo-Der, Arriba-Izq, Arriba-Der --> ";
			directionInput = PromptInput(1, possibleDirections);

			if (directionInput == 1)
				MoveDownLeft(availableMovesDownLeft);
			else if (directionInput == 2)
				MoveDownRight(availableMovesDownRight);
			else if (directionInput == 3)
				MoveUpLeft(availableMovesUpLeft);
			else
				MoveUpRight(availableMovesUpRight);
			break;
		default:
			break;
		}

		if (possibleDirections == 0)
		{
			cout << "No te podes mover";
			system("pause");
		}
		for (int i = 0; i < TEAM_SIZE; i++)
		{
			if (enemyTeam[i].position.y == position.y && enemyTeam[i].position.x == position.x)
			{
				enemyTeam[i].isAlive = false;
			}
		}
	}
};
struct Knight : Piece
{
	void Move(Piece ownTeam[], Piece enemyTeam[])
	{
		int possibleDirections = 0;
		Directions dir;
		bool canMoveDownLeft = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::L_DownLeft);
		if (canMoveDownLeft)
		{
			dir = Directions::L_DownLeft;
			possibleDirections++;
			cout << "puede moverse en la direccion: Abajo-Izquierda \n";
		}
		bool canMoveDownRight = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::L_DownRight);
		if (canMoveDownRight)
		{
			dir = Directions::L_DownRight;
			possibleDirections++;
			cout << "puede moverse en la direccion: Abajo-Derecha \n";
		}
		bool canMoveUpLeft = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::L_UpLeft);
		if (canMoveUpLeft)
		{
			dir = Directions::L_UpLeft;
			possibleDirections++;
			cout << "puede moverse en la direccion: Arriba-Izquierda \n";
		}
		bool canMoveUpRight = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::L_UpRight);
		if (canMoveUpRight)
		{
			dir = Directions::L_UpRight;
			possibleDirections++;
			cout << "puede moverse en la direccion: Arriba-Derecha \n";
		}
		bool canMoveLeftDown = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::L_LeftDown);
		if (canMoveLeftDown)
		{
			dir = Directions::L_LeftDown;
			possibleDirections++;
			cout << "puede moverse en la direccion: Izquierda-Abajo \n";
		}
		bool canMoveLeftUp = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::L_LeftUp);
		if (canMoveLeftUp)
		{
			dir = Directions::L_LeftUp;
			possibleDirections++;
			cout << "puede moverse en la direccion: Izquierda-Arriba \n";
		}
		bool canMoveRightDown = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::L_RightDown);
		if (canMoveRightDown)
		{
			dir = Directions::L_RightDown;
			possibleDirections++;
			cout << "puede moverse en la direccion: Derecha-Abajo \n";
		}
		bool canMoveRightUp = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::L_RightUp);
		if (canMoveRightUp)
		{
			dir = Directions::L_RightUp;
			possibleDirections++;
			cout << "puede moverse en la direccion: Derecha-Arriba \n";
		}

		if (possibleDirections == 0)
		{
			cout << "No se puede mover el caballo \n";
			system("pause");
		}
		else if (possibleDirections == 1)
		{
			switch (dir)
			{
			case Directions::L_DownLeft:
				HorseMoveDown(false);
				break;
			case Directions::L_DownRight:
				HorseMoveDown(true);
				break;
			case Directions::L_UpLeft:
				HorseMoveUp(false);
				break;
			case Directions::L_UpRight:
				HorseMoveUp(true);
				break;
			case Directions::L_LeftUp:
				HorseMoveLeft(true);
				break;
			case Directions::L_LeftDown:
				HorseMoveLeft(false);
				break;
			case Directions::L_RightUp:
				HorseMoveRight(true);
				break;
			case Directions::L_RightDown:
				HorseMoveRight(false);
				break;
			default:
				break;
			}
		}
		else
		{
			cout << "Seleccione en que direccion de las mencionadas se quiere mover, orden : \n 1. Abajo-Izquierda \n 2. Abajo-Derecha \n" <<
				" 3. Arriba-Izquierda \n 4. Arriba-Derecha \n 5. Izquierda-Abajo \n 6. Izquierda-Arriba \n 7. Derecha-Abajo \n 8. Derecha-Arriba \n";
			int response;
			bool isValidMove = true;
			do
			{
				response = PromptInput(1, 8);
				switch (response)
				{
				case 1:
					if (canMoveDownLeft)
						HorseMoveDown(false);
					else
						isValidMove = false;
					break;
				case 2:
					if (canMoveDownRight)
						HorseMoveDown(true);
					else
						isValidMove = false;
					break;
				case 3:
					if (canMoveUpLeft)
						HorseMoveUp(false);
					else
						isValidMove = false;
					break;
				case 4:
					if (canMoveUpRight)
						HorseMoveUp(true);
					else
						isValidMove = false;
					break;
				case 5:
					if (canMoveLeftDown)
						HorseMoveLeft(false);
					else
						isValidMove = false;
					break;
				case 6:
					if (canMoveLeftUp)
						HorseMoveLeft(true);
					else
						isValidMove = false;
					break;
				case 7:
					if (canMoveRightDown)
						HorseMoveRight(false);
					else
						isValidMove = false;
					break;
				case 8:
					if (canMoveRightUp)
						HorseMoveRight(true);
					else
						isValidMove = false;
					break;
				}
				if (!isValidMove)
					cout << "Elija un movimiento valido \n";
			} while (!isValidMove);
		}
	}
	void HorseMoveDown(bool isRight)
	{
		if (isRight)
		{
			position.y += 2;
			position.x += 1;
		}
		else
		{
			position.y += 2;
			position.x -= 1;
		}

	}
	void HorseMoveUp(bool isRight)
	{
		if (isRight)
		{
			position.y -= 2;
			position.x += 1;
		}
		else
		{
			position.y -= 2;
			position.x -= 1;
		}

	}
	void HorseMoveLeft(bool isUp)
	{
		if (isUp)
		{
			position.x -= 2;
			position.y -= 1;
		}
		else
		{
			position.x += 2;
			position.y -= 1;
		}

	}
	void HorseMoveRight(bool isUp)
	{
		if (isUp)
		{
			position.x += 2;
			position.y -= 1;
		}
		else
		{
			position.x += 2;
			position.y += 1;
		}

	}
};
struct Rook : Piece
{
	void Move(Piece ownTeam[], Piece enemyTeam[])
	{
		int possibleDirections = 0;

		int availableMovesDown = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::Down);
		if (availableMovesDown > 0)
			possibleDirections++;

		int availableMovesUp = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::Up);
		if (availableMovesUp > 0)
			possibleDirections++;

		int availableMovesLeft = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::Left);
		if (availableMovesLeft > 0)
			possibleDirections++;

		int availableMovesRight = DirectionCheck(graphic, ownTeam, enemyTeam, Directions::Right);
		if (availableMovesRight > 0)
			possibleDirections++;

		int directionInput = 0;
		switch (possibleDirections)
		{
		case 1:
			if (availableMovesDown > 0)
				MoveDown(availableMovesDown);
			else if (availableMovesUp > 0)
				MoveUp(availableMovesUp);
			else if (availableMovesLeft > 0)
				MoveLeft(availableMovesLeft);
			else
				MoveRight(availableMovesRight);
			break;
		case 2:
			if (availableMovesDown > 0)
			{
				if (availableMovesUp > 0)
				{
					cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Abajo, Arriba  --> ";
					directionInput = PromptInput(1, possibleDirections);
					if (directionInput == 1)
						MoveDown(availableMovesDown);
					else if (directionInput == 2)
						MoveUp(availableMovesUp);
				}
				else if (availableMovesLeft > 0)
				{
					cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Abajo, Izquierda  --> ";
					directionInput = PromptInput(1, possibleDirections);
					if (directionInput == 1)
						MoveDown(availableMovesDown);
					else if (directionInput == 2)
						MoveLeft(availableMovesLeft);
				}
				else
				{
					cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Abajo, Derecha  --> ";
					directionInput = PromptInput(1, possibleDirections);
					if (directionInput == 1)
						MoveDown(availableMovesDown);
					else if (directionInput == 2)
						MoveRight(availableMovesRight);
				}
			}
			else if (availableMovesUp > 0)
			{
				if (availableMovesLeft > 0)
				{
					cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Arriba, Izquierda  --> ";
					directionInput = PromptInput(1, possibleDirections);
					if (directionInput == 1)
						MoveUp(availableMovesUp);
					else if (directionInput == 2)
						MoveLeft(availableMovesLeft);
				}
				else if (availableMovesRight > 0)
				{
					cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Arriba, Derecha  --> ";
					directionInput = PromptInput(1, possibleDirections);
					if (directionInput == 1)
						MoveUp(availableMovesUp);
					else if (directionInput == 2)
						MoveRight(availableMovesRight);
				}
			}
			else if (availableMovesLeft > 0)
			{
				cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Izquierda, Derecha  --> ";
				directionInput = PromptInput(1, possibleDirections);
				if (directionInput == 1)
					MoveLeft(availableMovesLeft);
				else if (directionInput == 2)
					MoveRight(availableMovesRight);
			}
			break;
		case 3:
			if (availableMovesDown > 0)
			{
				if (availableMovesUp > 0)
				{
					if (availableMovesLeft > 0)
					{
						//Down-Up-Left
						cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Abajo, Arriba, Izquierda  --> ";
						directionInput = PromptInput(1, possibleDirections);
						if (directionInput == 1)
							MoveDown(availableMovesDown);
						else if (directionInput == 2)
							MoveUp(availableMovesUp);
						else
							MoveLeft(availableMovesLeft);
					}
					else
					{
						//Down-Up-Right
						cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Abajo, Arriba, Derecha  --> ";
						directionInput = PromptInput(1, possibleDirections);
						if (directionInput == 1)
							MoveDown(availableMovesDown);
						else if (directionInput == 2)
							MoveUp(availableMovesUp);
						else
							MoveRight(availableMovesRight);
					}
				}
				else if (availableMovesLeft > 0)
				{
					//Down-Left-Right
					cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Abajo, Izquierda, Derecha  --> ";
					directionInput = PromptInput(1, possibleDirections);
					if (directionInput == 1)
						MoveDown(availableMovesDown);
					else if (directionInput == 2)
						MoveLeft(availableMovesLeft);
					else
						MoveRight(availableMovesRight);
				}
			}
			else
			{
				//Up-Left-Right
				cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Arriba, Izquierda, Derecha  --> ";
				directionInput = PromptInput(1, possibleDirections);
				if (directionInput == 1)
					MoveUp(availableMovesUp);
				else if (directionInput == 2)
					MoveLeft(availableMovesLeft);
				else
					MoveRight(availableMovesRight);
			}
			break;
		case 4:
			cout << "Elija en cual de las " << possibleDirections << " direcciones desea moverse, 1-" << possibleDirections << " Orden, Abajo, Arriba, Izquierda, Derecha --> ";
			directionInput = PromptInput(1, possibleDirections);

			if (directionInput == 1)
				MoveDown(availableMovesDown);
			else if (directionInput == 2)
				MoveUp(availableMovesUp);
			else if (directionInput == 3)
				MoveLeft(availableMovesLeft);
			else
				MoveRight(availableMovesRight);
			break;
		default:
			break;
		}

		if (possibleDirections == 0)
		{
			cout << "No te podes mover";
			system("pause");
		}
		for (int i = 0; i < TEAM_SIZE; i++)
		{
			if (enemyTeam[i].position.y == position.y && enemyTeam[i].position.x == position.x)
			{
				enemyTeam[i].isAlive = false;
			}
		}
	}
};
struct Pawn : Piece
{
	void Move(Piece ownTeam[], Piece enemyTeam[])
	{
		int moveInput;
		int signChange;
		if (colour == Colors::White)
		{
			signChange = -1;
		}
		else if (colour == Colors::Black)
		{
			signChange = 1;
		}
		bool canMove = true;

		int possibleMoves = 1;
		bool pieceForward = false;
		bool pieceTwoForward = false;
		bool pieceUpLeft = false;
		bool pieceUpRight = false;
		if (firstTurn)
			possibleMoves = 2;
		for (int i = 0; i < TEAM_SIZE; i++)
		{

			if ((enemyTeam[i].position.y == position.y + 1 * signChange && enemyTeam[i].position.x == position.x && enemyTeam[i].isAlive) || (position.y + 1 * signChange == ownTeam[i].position.y && position.x == ownTeam[i].position.x))
			{
				if (firstTurn)
					possibleMoves -= 2;
				else
					possibleMoves--;
				pieceForward = true;
			}
			else if ((position.y + 2 * signChange == enemyTeam[i].position.y && position.x == enemyTeam[i].position.x && !pieceForward && firstTurn) || (position.y + 2 * signChange == ownTeam[i].position.y && position.x == ownTeam[i].position.x && !pieceForward && firstTurn))
			{
				possibleMoves--;
				pieceTwoForward = true;
			}
			else if (enemyTeam[i].position.y == position.y + 1 * signChange && enemyTeam[i].position.x == position.x - 1 && enemyTeam[i].isAlive)
			{
				pieceUpLeft = true;
				possibleMoves++;
			}
			else if (enemyTeam[i].position.y == position.y + 1 * signChange && enemyTeam[i].position.x == position.x + 1 && enemyTeam[i].isAlive)
			{
				pieceUpRight = true;
				possibleMoves++;
			}
		}
		if (possibleMoves == 0)
			canMove = false;
		if (canMove)
		{
			switch (possibleMoves)
			{

			case 1:
				if (!pieceForward)
					position.y += 1 * signChange;
				else if (pieceUpLeft)
				{
					position.y += 1 * signChange;
					position.x--;
				}
				else if (pieceUpRight)
				{
					position.y += 1 * signChange;
					position.x++;
				}
				break;
			case 2:

				if (firstTurn && !pieceForward && !pieceTwoForward)
				{
					cout << "Elija entre moverse uno o dos casilleros adelante --> ";
					moveInput = PromptInput(1, 2);
					if (moveInput == 1)
						position.y += 1 * signChange;
					else
						position.y += 2 * signChange;
				}

				if (!pieceForward && pieceUpLeft)
				{
					cout << "Elija entre Izquierda y adelante, 1 o 2 --> ";
					moveInput = PromptInput(1, 2);
					if (moveInput == 1)
					{
						position.y += 1 * signChange;
						position.x--;
					}
					else
						position.y += 1 * signChange;
				}
				else if (!pieceForward && pieceUpRight)
				{
					cout << "Elija entre adelante y derecha, 1 o 2 --> ";
					moveInput = PromptInput(1, 2);

					if (moveInput == 1)
						position.y += 1 * signChange;
					else
					{
						position.y += 1 * signChange;
						position.x++;
					}
				}
				else if (pieceUpLeft && pieceUpRight)
				{
					cout << "Elija entre izquierda y derecha, 1 o 2 --> ";
					moveInput = PromptInput(1, 2);

					if (moveInput == 1)
					{
						position.y += 1 * signChange;
						position.x--;
					}
					else
					{
						position.y += 1 * signChange;
						position.x++;
					}
				}
				break;
			case 3:
				if (!firstTurn)
				{
					cout << "Elija entre Izquierda, Adelante y Derecha 1/2/3 --> ";
					moveInput = PromptInput(1, 3);
					if (moveInput == 1)
					{
						position.y += 1 * signChange;
						position.x--;
					}
					else if (moveInput == 2)
						position.y += 1 * signChange;
					else
					{
						position.y += 1 * signChange;
						position.x++;
					}
				}
				else
				{
					if (!pieceForward)
					{
						if (!pieceTwoForward && pieceUpLeft)
						{
							cout << "Elija entre moverse una o dos posiciones adelante o en diagonal izquierda --> ";
							moveInput = PromptInput(1, 3);
							if (moveInput == 1)
							{
								position.y += 1 * signChange;
							}
							else if (moveInput == 2)
							{
								position.y += 2 * signChange;
							}
							else
							{
								position.y += 1 * signChange;
								position.x--;
							}
						}
						else if (!pieceTwoForward && pieceUpRight)
						{
							cout << "Elija entre moverse una o dos posiciones adelante o en diagonal derecha --> ";
							moveInput = PromptInput(1, 3);
							if (moveInput == 1)
							{
								position.y += 1 * signChange;
							}
							else if (moveInput == 2)
							{
								position.y += 2 * signChange;
							}
							else
							{
								position.y += 1 * signChange;
								position.x++;
							}
						}
						else if (pieceUpLeft && pieceUpRight)
						{
							cout << "Elija entre moverse adelante, en diagonal izquierda o en diagonal derecha --> ";
							moveInput = PromptInput(1, 3);
							if (moveInput == 1)
							{
								position.y += 1 * signChange;
							}
							else if (moveInput == 2)
							{
								position.y += 1 * signChange;
								position.x--;
							}
							else
							{
								position.y += 1 * signChange;
								position.x++;
							}
						}
					}
				}
				break;
			case 4:
				if (firstTurn)
				{
					cout << "Elija entre 1. uno o 2. dos adelante, 3. izquierda o 4. derecha --> ";
					moveInput = PromptInput(1, 3);
					if (moveInput == 1)
					{
						position.y += 1 * signChange;
					}
					else if (moveInput == 2)
						position.y += 2 * signChange;
					else if (moveInput == 3)
					{
						position.y += 1 * signChange;
						position.x--;
					}
					else
					{
						position.y += 1 * signChange;
						position.x++;
					}
				}
				break;
			default:
				break;
			}
			if (firstTurn)
				firstTurn = false;
		}
		else
		{
			cout << "No se puede mover el peon \n";
			system("pause");
		}

		for (int i = 0; i < TEAM_SIZE; i++)
		{
			if (enemyTeam[i].position.y == position.y && enemyTeam[i].position.x == position.x)
			{
				enemyTeam[i].isAlive = false;
			}
		}

		if ((colour == Colors::White && position.y == 0) || (colour == Colors::Black && position.y == 7))
			ChangeInto(ownTeam);
	}

	void ChangeInto(Piece ownTeam[])
	{
		char response;
		cout << "Elija en que quiere transformar al peon. Opciones (Q,R,B,k) ---> ";

		Piece pieceToConvertInto;
		bool isValidInput;
		do
		{
			isValidInput = true;
			cin >> response;
			switch (response)
			{
			case 'Q':
				pieceToConvertInto = Queen();
				pieceToConvertInto.colour = colour;
				pieceToConvertInto.position = position;
				if (pieceToConvertInto.colour == Colors::White)
					pieceToConvertInto.graphic = "WQ";
				else
					pieceToConvertInto.graphic = "BQ";

				pieceToConvertInto.isAlive = true;
				break;
			case 'R':
				pieceToConvertInto = Rook();
				pieceToConvertInto.colour = colour;
				pieceToConvertInto.position = position;
				if (pieceToConvertInto.colour == Colors::White)
					pieceToConvertInto.graphic = "WR";
				else
					pieceToConvertInto.graphic = "BR";
				pieceToConvertInto.isAlive = true;
				break;
			case 'B':
				pieceToConvertInto = Bishop();
				pieceToConvertInto.colour = colour;
				pieceToConvertInto.position = position;
				if (pieceToConvertInto.colour == Colors::White)
					pieceToConvertInto.graphic = "WB";
				else
					pieceToConvertInto.graphic = "BB";
				pieceToConvertInto.isAlive = true;
				break;
			case 'k':
				pieceToConvertInto = Knight();
				pieceToConvertInto.colour = colour;
				pieceToConvertInto.position = position;
				if (pieceToConvertInto.colour == Colors::White)
					pieceToConvertInto.graphic = "Wk";
				else
					pieceToConvertInto.graphic = "Bk";
				pieceToConvertInto.isAlive = true;
				break;
			default:
				cout << "Ingrese un caracter Valido...";
				isValidInput = false;
				break;
			}
		} while (!isValidInput);

		for (int i = 0; i < TEAM_SIZE; i++)
		{
			if (ownTeam[i].graphic == graphic)
				ownTeam[i] = pieceToConvertInto;
		}
	}
};
