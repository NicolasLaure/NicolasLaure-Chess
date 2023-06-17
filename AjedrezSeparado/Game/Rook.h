#pragma once

#include "Piece.h"

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