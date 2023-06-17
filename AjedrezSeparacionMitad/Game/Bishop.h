#pragma once

#include "Piece.h"

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