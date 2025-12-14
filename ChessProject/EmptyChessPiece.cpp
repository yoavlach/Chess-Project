#include "EmptyChessPiece.h"

EmptyChessPiece::EmptyChessPiece(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

EmptyChessPiece::~EmptyChessPiece()
{
}

void EmptyChessPiece::checkLegalMove(int source[], int destination[], const Board& board)
{ //empty for now
}
bool EmptyChessPiece::checkMakeCheck(int source[], const Board& board)
{
	return false; //for now
}