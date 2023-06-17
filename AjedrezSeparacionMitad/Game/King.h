#pragma once

#include "Piece.h"

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