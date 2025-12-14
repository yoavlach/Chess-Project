#include "Queen.h"

Queen::Queen(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

Queen::~Queen()
{
}

void Queen::checkLegalMove(int source[], int destination[], const Board& board)
{ //empty for now
}
bool Queen::checkMakeCheck(int source[], const Board& board)
{
    return false; //for now
}