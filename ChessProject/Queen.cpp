#include "Queen.h"

/*Initializes a queen
input: the queen's type and color
output: none*/
Queen::Queen(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

/*Clears a queen
input: none
output: none*/
Queen::~Queen()
{
}

/*Checks if a move is legal for a queen
input: the source coordinates, the destination coordinates and the board
output: none*/
void Queen::checkLegalMove(int source[], int destination[], const Board& board)
{ //empty for now
}

/*Checks if the queen is checking the enemy king
input: the source coordinates and the board
output: true if the queen is checking the king, false otherwise*/
bool Queen::checkMakeCheck(int source[], const Board& board)
{
    return false; //for now
}