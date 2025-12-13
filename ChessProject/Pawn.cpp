#include "Pawn.h"

Pawn::Pawn(const std::string& color): ChessPiece(color, "Pawn")
{
}

Pawn::~Pawn()
{
}

bool Pawn::checkLegalMove(const std::string& source, const std::string& dest)
{
    // Pawn move logic goes here
}
