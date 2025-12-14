#include "Bishop.h"

Bishop::Bishop(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

Bishop::~Bishop()
{
}

void Bishop::checkLegalMove(int source[], int destination[], const Board& board)
{ //empty for now
}

bool Bishop::checkMakeCheck(int source[], const Board& board)
{
	return false; //for now
}