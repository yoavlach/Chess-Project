#include "Pawn.h"

Pawn::Pawn(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

Pawn::~Pawn()
{
}

void Pawn::checkLegalMove(int source[], int destination[], const Board& board)
{ //empty for now
}

bool Pawn::checkMakeCheck(int source[], const Board& board)
{
    return false; //for now
}