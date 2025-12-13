#include "Rook.h"

Rook::Rook(const std::string& color) : ChessPiece(color, "Rook")
{
}

Rook::~Rook()
{
}

bool Rook::checkLegalMove(int source[], int destination[], Board board)
{
    // Rook move logic goes here
}
