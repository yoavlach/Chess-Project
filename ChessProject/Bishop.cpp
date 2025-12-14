#include "Bishop.h"

Bishop::Bishop(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

Bishop::~Bishop()
{
}

bool Bishop::checkLegalMove(int source[], int destination[], const Board& board)
{
    return false;
}
