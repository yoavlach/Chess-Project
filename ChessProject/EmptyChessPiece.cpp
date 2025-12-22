#include "EmptyChessPiece.h"

/*Initializes an empty chess piece
input: the piece's type and color
output: none*/
EmptyChessPiece::EmptyChessPiece(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

/*Clears an empty chess piece
input: none
output: none*/
EmptyChessPiece::~EmptyChessPiece()
{
}

/*Checks if a move is legal for an empty chess piece
input: the source coordinates, the destination coordinates and the board
output: none*/
bool EmptyChessPiece::checkLegalMove(int source[], int destination[], const Board& board)
{
	return false;
}

/*Checks if the empty chess piece is checking the enemy king
input: the source coordinates and the board
output: true if the piece is checking the king, false otherwise*/
bool EmptyChessPiece::checkMakeCheck(int source[], const Board& board)
{
	return false; //for now
}