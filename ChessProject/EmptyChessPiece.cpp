#include "EmptyChessPiece.h"

EmptyChessPiece::EmptyChessPiece(const std::string& color) : ChessPiece(color, "EmptyChessPiece")
{
}

EmptyChessPiece::~EmptyChessPiece()
{
}

bool EmptyChessPiece::checkLegalMove(const std::string& source, const std::string& dest)
{
    return false;
}