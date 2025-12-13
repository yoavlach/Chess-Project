#include "Pawn.h"

Pawn::Pawn(const std::string& color): ChessPiece(color, "Pawn")
{
}

Pawn::~Pawn()
{
}

bool Pawn::checkLegalMove(int source[], int destination[], Board board)
{
    // Pawn move logic goes here
}
