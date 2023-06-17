#include <iostream>
#include <Windows.h>
#include <string>
#include "GameLoop.h"
using namespace std;



//Global Variables
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
int width = 6;
int height = 3;
const int BOARD_SIZE = 8;
const int TEAM_SIZE = 16;

void main()
{
	const int teamSize = 16;
	Piece whitePieces[teamSize];
	Piece blackPieces[teamSize];
	TeamSetup(blackPieces, teamSize, Colors::Black);
	TeamSetup(whitePieces, teamSize, Colors::White);

	Game(whitePieces, blackPieces);
}



