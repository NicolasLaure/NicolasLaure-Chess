#include "Utilities.h"
#include "GameLoop.h"


//Global Variables
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
int width = 6;
int height = 3;

void main()
{
	const int teamSize = 16;
	Piece whitePieces[teamSize];
	Piece blackPieces[teamSize];
	TeamSetup(blackPieces, teamSize, Colors::Black);
	TeamSetup(whitePieces, teamSize, Colors::White);

	Game(whitePieces, blackPieces);
}



