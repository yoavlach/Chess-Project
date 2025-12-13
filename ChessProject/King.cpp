#include "King.h"

King::King(const std::string& color) : ChessPiece(color, "King")
{
}

King::~King()
{
}

bool King::checkLegalMove(const std::string& source, const std::string& dest)
{
    // King move logic goes here
}
