#pragma once

#include "Piece.h"

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