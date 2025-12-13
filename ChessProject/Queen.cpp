#include "Queen.h"

Queen::Queen(const std::string& color) : ChessPiece(color, "Queen")
{
}

Queen::~Queen()
{
}

bool Queen::checkLegalMove(int source[], int destination[], Board board)
{
    // Queen move logic goes here
}
