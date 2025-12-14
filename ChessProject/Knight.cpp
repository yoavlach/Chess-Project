#include "Knight.h"

/*Initializes a knight
input: the knight's type and color
output: none*/
Knight::Knight(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

/*Clears a knight
input: none
output: none*/
Knight::~Knight()
{
}

/*Checks if a move is legal for a knight
input: the source coordinates, the destination coordinates and the board
output: none*/
void Knight::checkLegalMove(int source[], int destination[], const Board& board)
{ //empty for now
}

/*Checks if the knight is checking the enemy king
input: the source coordinates and the board
output: true if the knight is checking the king, false otherwise*/
bool Knight::checkMakeCheck(int source[], const Board& board)
{
    return false; //for now
}