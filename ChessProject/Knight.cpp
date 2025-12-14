#include "Knight.h"

Knight::Knight(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

Knight::~Knight()
{
}

void Knight::checkLegalMove(int source[], int destination[], const Board& board)
{ //empty for now
}

bool Knight::checkMakeCheck(int source[], const Board& board)
{
    return false; //for now
}