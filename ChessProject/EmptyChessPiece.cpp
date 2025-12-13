#include "EmptyChessPiece.h"

EmptyChessPiece::EmptyChessPiece(const std::string& color) : ChessPiece(color, "EmptyChessPiece")
{
}

EmptyChessPiece::~EmptyChessPiece()
{
}

bool EmptyChessPiece::checkLegalMove(int source[], int destination[], Board board)
{
    return false;
}