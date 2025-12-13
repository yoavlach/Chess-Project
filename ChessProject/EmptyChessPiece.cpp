#include "EmptyChessPiece.h"

EmptyChessPiece::EmptyChessPiece(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

EmptyChessPiece::~EmptyChessPiece()
{
}

bool EmptyChessPiece::checkLegalMove(int source[], int destination[], Board board)
{
    return false;
}