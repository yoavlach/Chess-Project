#include "Bishop.h"

Bishop::Bishop(const std::string& color) : ChessPiece(color, "Bishop")
{
}

Bishop::~Bishop()
{
}

bool Bishop::checkLegalMove(const std::string& source, const std::string& dest)
{
    // Bishop move logic goes here
}
