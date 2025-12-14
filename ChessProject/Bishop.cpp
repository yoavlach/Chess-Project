#include "Bishop.h"

/*Initializes a bishop
input: the bishop's type and color
output: none*/
Bishop::Bishop(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

/*Clears a bishop
input: none
output: none*/
Bishop::~Bishop()
{
}

/*Checks if a move is legal for a bishop
input: the source coordinates, the destination coordinates and the board
output: none*/
void Bishop::checkLegalMove(int source[], int destination[], const Board& board)
{ //empty for now
}

/*Checks if the bishop is checking the enemy king
input: the source coordinates and the board
output: true if the bishop is checking the king, false otherwise*/
bool Bishop::checkMakeCheck(int source[], const Board& board)
{
	return false; //for now
}