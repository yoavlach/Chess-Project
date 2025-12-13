#include "Queen.h"

Queen::Queen(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

Queen::~Queen()
{
}

bool Queen::checkLegalMove(int source[], int destination[], Board board)
{
    return false;
}
