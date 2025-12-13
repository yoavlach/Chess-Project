#include "Pawn.h"

Pawn::Pawn(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

Pawn::~Pawn()
{
}

bool Pawn::checkLegalMove(int source[], int destination[], Board board)
{
    return false;
}
