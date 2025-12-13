#include "Rook.h"

Rook::Rook(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

Rook::~Rook()
{
}

bool Rook::checkLegalMove(int source[], int destination[], Board board)
{
    bool isLegal = true;

    int srcRow = source[0];
    int srcCol = source[1];

    int destRow = destination[0];
    int destCol = destination[1];

    // cannot stay in the same place
    if (srcRow == destRow && srcCol == destCol)
    {
        isLegal = false;
    }

    int rowDiff = std::abs(srcRow - destRow);
    int colDiff = std::abs(srcCol - destCol);

    // rook can move only in straight lines (row OR column)
    if (rowDiff != 0 && colDiff != 0)
    {
        isLegal = false;
    }

    if (isLegal)
    {
        // horizontal move
        if (rowDiff == 0)
        {
            // moving left
            if (destCol < srcCol)
            {
                for (int col = destCol + 1; col < srcCol; ++col)
                {
                    // path must be empty
                    if (board.getPiece(srcRow, col) != nullptr)
                    {
                        isLegal = false;
                    }
                }
            }
            // moving right
            else
            {
                for (int col = srcCol + 1; col < destCol; ++col)
                {
                    // path must be empty
                    if (board.getPiece(srcRow, col) != nullptr)
                    {
                        isLegal = false;
                    }
                }
            }
        }
        // vertical move
        else
        {
            // moving down
            if (destRow > srcRow)
            {
                for (int row = srcRow + 1; row < destRow; ++row)
                {
                    // path must be empty
                    if (board.getPiece(row, srcCol) != nullptr)
                    {
                        isLegal = false;
                    }
                }
            }
            // moving up
            else
            {
                for (int row = destRow + 1; row < srcRow; ++row)
                {
                    // path must be empty
                    if (board.getPiece(row, srcCol) != nullptr)
                    {
                        isLegal = false;
                    }
                }
            }
        }
    }

    if (isLegal)
    {
        ChessPiece* targetPiece = board.getPiece(destRow, destCol);//wating for getPiece to be added in baord.h

        // cannot capture a piece of the same color
        if (targetPiece != nullptr &&
            targetPiece->getColor() == this->getColor())
        {
            isLegal = false;
        }
    }

    return isLegal;
}