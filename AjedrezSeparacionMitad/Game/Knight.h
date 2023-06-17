#pragma once

#include "Piece.h"

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