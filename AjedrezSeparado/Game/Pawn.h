#pragma once

#include "Piece.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"

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