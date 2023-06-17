#pragma once
#include "Piece.h"
#include "King.h"
#include "Pawn.h"
#include "BoardUtilities.h"
#include <string>

void TeamSetup(Piece pieces[], int size, Colors colour);
void TeamPieceSelection(Piece ownTeam[], Piece otherTeam[]);
void PrintPieces(Piece whitePieces[], Piece blackPieces[]);
void Game(Piece whitePieces[], Piece blackPieces[]);