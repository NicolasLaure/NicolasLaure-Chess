#include "GameLoop.h"

void Game(Piece whitePieces[], Piece blackPieces[])
{
	bool arePlaying = true;
	bool whiteMoves = true;

	Board board;
	board.SetBoard();

	int selectedBetween;
	while (arePlaying)
	{
		system("cls");
		PrintBoard(board);
		PrintPieces(whitePieces, blackPieces);
		SetConsoleCursorPosition(handle, { 0, 25 });

		if (whiteMoves)
		{
			cout << endl << "Turno de las blancas, Seleccione una pieza: K, Q, B, k, R, P   ---> ";
			TeamPieceSelection(whitePieces, blackPieces);
			whiteMoves = false;
		}
		else
		{
			cout << endl << "Turno de las negras, Seleccione una pieza: K, Q, B, k, R, P   ---> ";
			TeamPieceSelection(blackPieces, whitePieces);
			whiteMoves = true;
		}

		if (!whitePieces[0].isAlive || !blackPieces[0].isAlive)
			arePlaying = false;
	}

	if (!whitePieces[0].isAlive)
		cout << "El jugador con las piezas negras gano!";
	else
		cout << "El jugador con las piezas blancas gano!";

	system("pause");
}

void TeamPieceSelection(Piece ownTeam[], Piece otherTeam[])
{
	bool isValidInput = true;
	char response;
	int selectedBetween;

	string graphic;
	do
	{
		cin >> response;
		switch (response)
		{
		case 'K':
			static_cast<King&>(ownTeam[static_cast<int>(Pieces::King)]).Move(ownTeam, otherTeam);
			break;
		case 'Q':
			if (ownTeam[static_cast<int>(Pieces::Queen)].isAlive)
				static_cast<Queen&>(ownTeam[static_cast<int>(Pieces::Queen)]).Move(ownTeam, otherTeam);
			else
			{
				cout << "No se puede seleccionar esa pieza porque esta muerta";
				isValidInput = false;
			}
			break;

		case 'B':
			cout << "Cual de los 2? --> ";

			selectedBetween = PromptInput(1, 2);
			if (selectedBetween == 1)
			{
				if (ownTeam[static_cast<int>(Pieces::Bishop1)].isAlive)
					static_cast<Bishop&>(ownTeam[static_cast<int>(Pieces::Bishop1)]).Move(ownTeam, otherTeam);
				else
				{
					cout << "No se puede seleccionar esa pieza porque esta muerta";
					isValidInput = false;
				}
			}
			else
			{
				if (ownTeam[static_cast<int>(Pieces::Bishop2)].isAlive)
					static_cast<Bishop&>(ownTeam[static_cast<int>(Pieces::Bishop2)]).Move(ownTeam, otherTeam);
				else
				{
					cout << "No se puede seleccionar esa pieza porque esta muerta";
					isValidInput = false;
				}

			}
			break;

		case 'k':
			cout << "Cual de los 2? --> ";

			selectedBetween = PromptInput(1, 2);
			if (selectedBetween == 1)
			{
				if (ownTeam[static_cast<int>(Pieces::Knight1)].isAlive)
					static_cast<Knight&>(ownTeam[static_cast<int>(Pieces::Knight1)]).Move(ownTeam, otherTeam);
				else
				{
					cout << "No se puede seleccionar esa pieza porque esta muerta";
					isValidInput = false;
				}
			}
			else
			{
				if (ownTeam[static_cast<int>(Pieces::Knight2)].isAlive)
					static_cast<Knight&>(ownTeam[static_cast<int>(Pieces::Knight2)]).Move(ownTeam, otherTeam);
				else
				{
					cout << "No se puede seleccionar esa pieza porque esta muerta";
					isValidInput = false;
				}
			}
			break;
		case 'R':
			cout << "Cual de los 2? --> ";

			selectedBetween = PromptInput(1, 2);
			if (selectedBetween == 1)
			{
				if (ownTeam[static_cast<int>(Pieces::Rook1)].isAlive)
					static_cast<Rook&>(ownTeam[static_cast<int>(Pieces::Rook1)]).Move(ownTeam, otherTeam);
				else
				{
					cout << "No se puede seleccionar esa pieza porque esta muerta";
					isValidInput = false;
				}

			}
			else
			{
				if (ownTeam[static_cast<int>(Pieces::Rook2)].isAlive)
					static_cast<Rook&>(ownTeam[static_cast<int>(Pieces::Rook2)]).Move(ownTeam, otherTeam);
				else
				{
					cout << "No se puede seleccionar esa pieza porque esta muerta";
					isValidInput = false;
				}

			}
			break;
		case 'P':
			cout << "Cual de los 8? --> ";

			selectedBetween = PromptInput(1, 8);
			switch (selectedBetween)
			{
			case 1:
				if (ownTeam[static_cast<int>(Pieces::Pawn1)].isAlive)
				{
					graphic = ownTeam[static_cast<int>(Pieces::Pawn1)].graphic;

					if (graphic == "P1")
						static_cast<Pawn&>(ownTeam[static_cast<int>(Pieces::Pawn1)]).Move(ownTeam, otherTeam);
					else if (graphic == "WQ" || graphic == "BQ")
						static_cast<Queen&>(ownTeam[static_cast<int>(Pieces::Pawn1)]).Move(ownTeam, otherTeam);
					else if (graphic == "WR" || graphic == "BR")
						static_cast<Rook&>(ownTeam[static_cast<int>(Pieces::Pawn1)]).Move(ownTeam, otherTeam);
					else if (graphic == "WB" || graphic == "BB")
						static_cast<Bishop&>(ownTeam[static_cast<int>(Pieces::Pawn1)]).Move(ownTeam, otherTeam);
					else if (graphic == "Wk" || graphic == "Bk")
						static_cast<Knight&>(ownTeam[static_cast<int>(Pieces::Pawn1)]).Move(ownTeam, otherTeam);
				}
				else
				{
					cout << "No se puede seleccionar esa pieza porque esta muerta";
					isValidInput = false;
				}
				break;
			case 2:
				if (ownTeam[static_cast<int>(Pieces::Pawn2)].isAlive)
				{
					graphic = ownTeam[static_cast<int>(Pieces::Pawn2)].graphic;
					if (graphic == "P2")
						static_cast<Pawn&>(ownTeam[static_cast<int>(Pieces::Pawn2)]).Move(ownTeam, otherTeam);
					else if (graphic == "WQ" || graphic == "BQ")
						static_cast<Queen&>(ownTeam[static_cast<int>(Pieces::Pawn2)]).Move(ownTeam, otherTeam);
					else if (graphic == "WR" || graphic == "BR")
						static_cast<Rook&>(ownTeam[static_cast<int>(Pieces::Pawn2)]).Move(ownTeam, otherTeam);
					else if (graphic == "WB" || graphic == "BB")
						static_cast<Bishop&>(ownTeam[static_cast<int>(Pieces::Pawn2)]).Move(ownTeam, otherTeam);
					else if (graphic == "Wk" || graphic == "Bk")
						static_cast<Knight&>(ownTeam[static_cast<int>(Pieces::Pawn2)]).Move(ownTeam, otherTeam);
				}
				else
				{
					cout << "No se puede seleccionar esa pieza porque esta muerta";
					isValidInput = false;
				}
				break;
			case 3:
				if (ownTeam[static_cast<int>(Pieces::Pawn3)].isAlive)
				{
					graphic = ownTeam[static_cast<int>(Pieces::Pawn3)].graphic;
					if (graphic == "P3")
						static_cast<Pawn&>(ownTeam[static_cast<int>(Pieces::Pawn3)]).Move(ownTeam, otherTeam);
					else if (graphic == "WQ" || graphic == "BQ")
						static_cast<Queen&>(ownTeam[static_cast<int>(Pieces::Pawn3)]).Move(ownTeam, otherTeam);
					else if (graphic == "WR" || graphic == "BR")
						static_cast<Rook&>(ownTeam[static_cast<int>(Pieces::Pawn3)]).Move(ownTeam, otherTeam);
					else if (graphic == "WB" || graphic == "BB")
						static_cast<Bishop&>(ownTeam[static_cast<int>(Pieces::Pawn3)]).Move(ownTeam, otherTeam);
					else if (graphic == "Wk" || graphic == "Bk")
						static_cast<Knight&>(ownTeam[static_cast<int>(Pieces::Pawn3)]).Move(ownTeam, otherTeam);
				}
				else
				{
					cout << "No se puede seleccionar esa pieza porque esta muerta";
					isValidInput = false;
				}
				break;
			case 4:
				if (ownTeam[static_cast<int>(Pieces::Pawn4)].isAlive)
				{
					graphic = ownTeam[static_cast<int>(Pieces::Pawn4)].graphic;
					if (graphic == "P4")
						static_cast<Pawn&>(ownTeam[static_cast<int>(Pieces::Pawn4)]).Move(ownTeam, otherTeam);
					else if (graphic == "WQ" || graphic == "BQ")
						static_cast<Queen&>(ownTeam[static_cast<int>(Pieces::Pawn4)]).Move(ownTeam, otherTeam);
					else if (graphic == "WR" || graphic == "BR")
						static_cast<Rook&>(ownTeam[static_cast<int>(Pieces::Pawn4)]).Move(ownTeam, otherTeam);
					else if (graphic == "WB" || graphic == "BB")
						static_cast<Bishop&>(ownTeam[static_cast<int>(Pieces::Pawn4)]).Move(ownTeam, otherTeam);
					else if (graphic == "Wk" || graphic == "Bk")
						static_cast<Knight&>(ownTeam[static_cast<int>(Pieces::Pawn4)]).Move(ownTeam, otherTeam);
				}
				else
				{
					cout << "No se puede seleccionar esa pieza porque esta muerta";
					isValidInput = false;
				}
				break;
			case 5:
				if (ownTeam[static_cast<int>(Pieces::Pawn5)].isAlive)
				{
					graphic = ownTeam[static_cast<int>(Pieces::Pawn5)].graphic;
					if (graphic == "P5")
						static_cast<Pawn&>(ownTeam[static_cast<int>(Pieces::Pawn5)]).Move(ownTeam, otherTeam);
					else if (graphic == "WQ" || graphic == "BQ")
						static_cast<Queen&>(ownTeam[static_cast<int>(Pieces::Pawn5)]).Move(ownTeam, otherTeam);
					else if (graphic == "WR" || graphic == "BR")
						static_cast<Rook&>(ownTeam[static_cast<int>(Pieces::Pawn5)]).Move(ownTeam, otherTeam);
					else if (graphic == "WB" || graphic == "BB")
						static_cast<Bishop&>(ownTeam[static_cast<int>(Pieces::Pawn5)]).Move(ownTeam, otherTeam);
					else if (graphic == "Wk" || graphic == "Bk")
						static_cast<Knight&>(ownTeam[static_cast<int>(Pieces::Pawn5)]).Move(ownTeam, otherTeam);
				}
				else
				{
					cout << "No se puede seleccionar esa pieza porque esta muerta";
					isValidInput = false;
				}
				break;
			case 6:
				if (ownTeam[static_cast<int>(Pieces::Pawn6)].isAlive)
				{
					graphic = ownTeam[static_cast<int>(Pieces::Pawn6)].graphic;
					if (graphic == "P6")
						static_cast<Pawn&>(ownTeam[static_cast<int>(Pieces::Pawn6)]).Move(ownTeam, otherTeam);
					else if (graphic == "WQ" || graphic == "BQ")
						static_cast<Queen&>(ownTeam[static_cast<int>(Pieces::Pawn6)]).Move(ownTeam, otherTeam);
					else if (graphic == "WR" || graphic == "BR")
						static_cast<Rook&>(ownTeam[static_cast<int>(Pieces::Pawn6)]).Move(ownTeam, otherTeam);
					else if (graphic == "WB" || graphic == "BB")
						static_cast<Bishop&>(ownTeam[static_cast<int>(Pieces::Pawn6)]).Move(ownTeam, otherTeam);
					else if (graphic == "Wk" || graphic == "Bk")
						static_cast<Knight&>(ownTeam[static_cast<int>(Pieces::Pawn6)]).Move(ownTeam, otherTeam);
				}
				else
				{
					cout << "No se puede seleccionar esa pieza porque esta muerta";
					isValidInput = false;
				}
				break;
			case 7:
				if (ownTeam[static_cast<int>(Pieces::Pawn7)].isAlive)
				{
					graphic = ownTeam[static_cast<int>(Pieces::Pawn7)].graphic;
					if (graphic == "P7")
						static_cast<Pawn&>(ownTeam[static_cast<int>(Pieces::Pawn7)]).Move(ownTeam, otherTeam);
					else if (graphic == "WQ" || graphic == "BQ")
						static_cast<Queen&>(ownTeam[static_cast<int>(Pieces::Pawn7)]).Move(ownTeam, otherTeam);
					else if (graphic == "WR" || graphic == "BR")
						static_cast<Rook&>(ownTeam[static_cast<int>(Pieces::Pawn7)]).Move(ownTeam, otherTeam);
					else if (graphic == "WB" || graphic == "BB")
						static_cast<Bishop&>(ownTeam[static_cast<int>(Pieces::Pawn7)]).Move(ownTeam, otherTeam);
					else if (graphic == "Wk" || graphic == "Bk")
						static_cast<Knight&>(ownTeam[static_cast<int>(Pieces::Pawn7)]).Move(ownTeam, otherTeam);
				}
				else
				{
					cout << "No se puede seleccionar esa pieza porque esta muerta";
					isValidInput = false;
				}
				break;
			case 8:
				if (ownTeam[static_cast<int>(Pieces::Pawn8)].isAlive)
				{
					graphic = ownTeam[static_cast<int>(Pieces::Pawn8)].graphic;
					if (graphic == "P8")
						static_cast<Pawn&>(ownTeam[static_cast<int>(Pieces::Pawn8)]).Move(ownTeam, otherTeam);
					else if (graphic == "WQ" || graphic == "BQ")
						static_cast<Queen&>(ownTeam[static_cast<int>(Pieces::Pawn8)]).Move(ownTeam, otherTeam);
					else if (graphic == "WR" || graphic == "BR")
						static_cast<Rook&>(ownTeam[static_cast<int>(Pieces::Pawn8)]).Move(ownTeam, otherTeam);
					else if (graphic == "WB" || graphic == "BB")
						static_cast<Bishop&>(ownTeam[static_cast<int>(Pieces::Pawn8)]).Move(ownTeam, otherTeam);
					else if (graphic == "Wk" || graphic == "Bk")
						static_cast<Knight&>(ownTeam[static_cast<int>(Pieces::Pawn8)]).Move(ownTeam, otherTeam);
				}
				else
				{
					cout << "No se puede seleccionar esa pieza porque esta muerta";
					isValidInput = false;
				}
				break;
			}
			break;
		default:
			isValidInput = false;
			break;
		}
	} while (!isValidInput);
}

void TeamSetup(Piece pieces[], int size, Colors colour)
{
	int pawnPosX = 0;
	for (int i = 0; i < size; i++)
	{
		switch (i)
		{
		case 0:
			if (colour == Colors::Black)
			{
				pieces[i] = King();
				pieces[i].colour = Colors::Black;
				pieces[i].position = { 4,0 };
				pieces[i].graphic = "BK";
				pieces[i].isAlive = true;
			}
			else
			{
				pieces[i] = King();
				pieces[i].colour = Colors::White;
				pieces[i].position = { 4,7 };
				pieces[i].graphic = "WK";
				pieces[i].isAlive = true;
			}
			break;
		case 1:
			if (colour == Colors::Black)
			{
				pieces[i] = Queen{};
				pieces[i].colour = Colors::Black;
				pieces[i].position = { 3,0 };
				pieces[i].graphic = "BQ";
				pieces[i].isAlive = true;
			}
			else
			{
				pieces[i] = Queen{};
				pieces[i].colour = Colors::White;
				pieces[i].position = { 3,7 };
				pieces[i].graphic = "WQ";
				pieces[i].isAlive = true;
			}
			break;
		case 2:
		case 3:
			if (colour == Colors::Black)
			{
				pieces[i] = Bishop{};
				pieces[i].colour = Colors::Black;
				i == 2 ? pieces[i].position = { 2,0 } : pieces[i].position = { 5,0 };
				i == 2 ? pieces[i].graphic = "B1" : pieces[i].graphic = "B2";
				pieces[i].isAlive = true;
			}
			else
			{
				pieces[i] = Bishop{};
				pieces[i].colour = Colors::White;
				i == 2 ? pieces[i].position = { 2,7 } : pieces[i].position = { 5,7 };
				i == 2 ? pieces[i].graphic = "B1" : pieces[i].graphic = "B2";
				pieces[i].isAlive = true;
			}
			break;
		case 4:
		case 5:
			if (colour == Colors::Black)
			{
				pieces[i] = Knight{};
				pieces[i].colour = Colors::Black;
				i == 4 ? pieces[i].position = { 1,0 } : pieces[i].position = { 6,0 };
				i == 4 ? pieces[i].graphic = "k1" : pieces[i].graphic = "k2";
				pieces[i].isAlive = true;
			}
			else
			{
				pieces[i] = Knight{};
				pieces[i].colour = Colors::White;
				i == 4 ? pieces[i].position = { 1,7 } : pieces[i].position = { 6,7 };
				i == 4 ? pieces[i].graphic = "k1" : pieces[i].graphic = "k2";
				pieces[i].isAlive = true;
			}
			break;
		case 6:
		case 7:
			if (colour == Colors::Black)
			{
				pieces[i] = Rook{};
				pieces[i].colour = Colors::Black;
				i == 6 ? pieces[i].position = { 0,0 } : pieces[i].position = { 7,0 };
				i == 6 ? pieces[i].graphic = "R1" : pieces[i].graphic = "R2";
				pieces[i].isAlive = true;
			}
			else
			{
				pieces[i] = Rook{};
				pieces[i].colour = Colors::White;
				i == 6 ? pieces[i].position = { 0,7 } : pieces[i].position = { 7,7 };
				i == 6 ? pieces[i].graphic = "R1" : pieces[i].graphic = "R2";
				pieces[i].isAlive = true;
			}
			break;
		default:
			if (colour == Colors::Black)
			{
				pieces[i] = Pawn{};
				pieces[i].colour = Colors::Black;
				pieces[i].position = { pawnPosX, 1 };
				pieces[i].graphic = "P" + to_string(i - 8 + 1);
				pieces[i].isAlive = true;
				pawnPosX++;
			}
			else
			{
				pieces[i] = Pawn{};
				pieces[i].colour = Colors::White;
				pieces[i].position = { pawnPosX, 6 };
				pieces[i].graphic = "P" + to_string(i - 8 + 1);
				pieces[i].isAlive = true;
				pawnPosX++;
			}
			break;
		}
	}
}

void PrintPieces(Piece whitePieces[], Piece blackPieces[])
{
	Piece pieces[32];

	int j = 0;
	for (int i = 0; i < 32; i++)
	{
		if (i < 16)
		{
			pieces[i] = whitePieces[i];
		}
		else
		{
			pieces[i] = blackPieces[j];
			j++;
		}
	}

	for (Piece piece : pieces)
	{
		if (piece.isAlive)
		{
			COORD coords = { (short)(piece.position.x * width + (width - 1) / 2), (short)(piece.position.y * height + (height - 1) / 2) };
			SetConsoleCursorPosition(handle, coords);

			if (piece.colour == Colors::Black)
			{
				if ((piece.position.x % 2 != 0 && piece.position.y % 2 == 0) || (piece.position.x % 2 == 0 && piece.position.y % 2 != 0))
					SetConsoleTextAttribute(handle, 8);
				else if ((piece.position.x % 2 == 0 && piece.position.y % 2 == 0) || (piece.position.x % 2 != 0 && piece.position.y % 2 != 0))
					SetConsoleTextAttribute(handle, 96);
			}
			else
			{
				if ((piece.position.x % 2 != 0 && piece.position.y % 2 == 0) || (piece.position.x % 2 == 0 && piece.position.y % 2 != 0))
					SetConsoleTextAttribute(handle, 15);
				else if ((piece.position.x % 2 == 0 && piece.position.y % 2 == 0) || (piece.position.x % 2 != 0 && piece.position.y % 2 != 0))
					SetConsoleTextAttribute(handle, 111);
			}
			cout << piece.graphic;
			SetConsoleTextAttribute(handle, 7);
		}
	}
}