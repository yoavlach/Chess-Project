#include "King.h"
#include <cmath>

King::King(const std::string& color) : ChessPiece(color, "King")
{
}

King::~King()
{
}

bool King::checkLegalMove(int source[], int destination[], Board board)
{
    int srcRow = source[0];
    int srcCol = source[1];

    int destRow = destination[0];
    int destCol = destination[1];


    int rowDiff = std::abs(srcRow - destRow);
    int colDiff = std::abs(srcCol - destCol);


    if (rowDiff > 1 || colDiff > 1)
    {
        return false;
    }

    if (rowDiff == 0 && colDiff == 0)
    {
        return false;
    }

    ChessPiece* targetPiece = board.getPiece(destRow, destCol);

    if (targetPiece == nullptr)
    {
        return true;
    }
    else
    {
        if (targetPiece->getColor() == this->getColor())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}