#include "Pawn.h"

/*Initializes a pawn
input: the pawn's type and color
output: none*/
Pawn::Pawn(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

/*Clears a pawn
input: none
output: none*/
Pawn::~Pawn()
{
}

/*Checks if a move is legal for a pawn
input: the source coordinates, the destination coordinates and the board
output: none*/
void Pawn::checkLegalMove(int source[], int destination[], const Board& board)
{ //empty for now
}

/*Checks if the pawn is checking the enemy king
input: the source coordinates and the board
output: true if the pawn is checking the king, false otherwise*/
bool Pawn::checkMakeCheck(int source[], const Board& board)
{
    return false; //for now
}