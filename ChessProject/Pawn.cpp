#include "Pawn.h"
#include <cmath>

/*Initializes a pawn*/
Pawn::Pawn(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

/*Clears a pawn*/
Pawn::~Pawn()
{
}

/*Checks if a move is legal for a pawn*/
bool Pawn::checkLegalMove(int source[], int destination[], const Board& board)
{
    bool legal = true;
    int srcRow = source[ROW_INDEX];
    int srcCol = source[COL_INDEX];
    int destRow = destination[ROW_INDEX];
    int destCol = destination[COL_INDEX];

    int rowDiff = destRow - srcRow;
    int colDiff = std::abs(destCol - srcCol);

    int direction = 0;
    int startRow = 0;

    if (this->getColor() == "white")
    {
        direction = 1;
        startRow = 1;
    }
    else
    {
        direction = -1;
        startRow = 6;
    }

    if (colDiff == 0)
    {
        if (rowDiff == direction)
        {
            if (board.getPiece(destRow, destCol)->getType() != "empty")
            {
                legal = false;
            }
        }
        else if (rowDiff == 2 * direction && srcRow == startRow && legal)
        {
            if (board.getPiece(srcRow + direction, srcCol)->getType() != "empty" || board.getPiece(destRow, destCol)->getType() != "empty")
            {
                legal = false;
            }
        }
        else
        {
            legal = false;
        }
    }
    else if (colDiff == 1 && rowDiff == direction)
    {
        if (board.getPiece(destRow, destCol)->getType() == "empty")
        {
            legal = false;
        }
        if (board.getPiece(destRow, destCol)->getColor() == this->getColor())
        {
            legal = false;
        }
    }
    else
    {
        legal = false;
    }
    return legal;
}

//Checks if the pawn is checking the enemy king
bool Pawn::checkMakeCheck(int source[], const Board& board)
{
    int srcRow = source[ROW_INDEX];
    int srcCol = source[COL_INDEX];
    std::string currColor = board.getPiece(srcRow, srcCol)->getColor();

    int direction = 0;

    if (currColor == "white")
    {
        direction = 1;
    }
    else
    {
        direction = -1;
    }

    int checkRows[] = { srcRow + direction, srcRow + direction };
    int checkCols[] = { srcCol - 1, srcCol + 1 };

    for (int i = 0; i < 2; i++)
    {
        int targetRow = checkRows[i];
        int targetCol = checkCols[i];

        if (targetRow >= 0 && targetRow < ROWS_AND_COLS && targetCol >= 0 && targetCol < ROWS_AND_COLS)
        {
            std::string type = board.getPiece(targetRow, targetCol)->getType();
            std::string color = board.getPiece(targetRow, targetCol)->getColor();

            if (type == "king" && color != currColor)
            {
                return true;
            }
        }
    }
    return false;
}