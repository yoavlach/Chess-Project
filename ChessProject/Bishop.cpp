#include "Bishop.h"

Bishop::Bishop(const std::string& color) : ChessPiece(color, "Bishop")
{
}

Bishop::~Bishop()
{
}

bool Bishop::checkLegalMove(int source[], int destination[], Board board)
{
    // Bishop move logic goes here
}
