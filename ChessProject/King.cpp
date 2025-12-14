#include "King.h"
#include <cmath>

King::King(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

King::~King()
{
}

bool King::checkLegalMove(int source[], int destination[], const Board& board)
{
    bool isLegal = true;

    int srcRow = source[0];
    int srcCol = source[1];

    int destRow = destination[0];
    int destCol = destination[1];

    int rowDiff = std::abs(srcRow - destRow);
    int colDiff = std::abs(srcCol - destCol);

    if (rowDiff > 1 || colDiff > 1)
    {
        isLegal = false;//can not move more then one
    }

    if (isLegal)
    {
        ChessPiece* targetPiece = board.getPiece(destRow, destCol);

        //if there is a piece of the same color on destination then its illegal (if there is a piece from the outher color then its ok (the base for takeing)
        if (targetPiece != nullptr &&
            targetPiece->getColor() == this->getColor())
        {
            isLegal = false;
        }
    }

    return isLegal;
}
