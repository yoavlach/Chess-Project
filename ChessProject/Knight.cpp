#include "Knight.h"

Knight::Knight(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

Knight::~Knight()
{
}

bool Knight::checkLegalMove(int source[], int destination[], Board board)
{
    return false;
}
