#include "Knight.h"
#include <cmath>

/*Initializes a knight
input: the knight's type and color
output: none*/
Knight::Knight(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

/*Clears a knight*/
Knight::~Knight()
{
}

/*Checks if a move is legal for a knight
A Knight move is legal if it moves in an L-shape (2x1 or 1x2).
Unlike the Rook, we do NOT check if the path is blocked.*/
bool Knight::checkLegalMove(int source[], int destination[], const Board& board)
{
    int srcRow = source[ROW_INDEX];
    int srcCol = source[COL_INDEX];

    int destRow = destination[ROW_INDEX];
    int destCol = destination[COL_INDEX];

    int rowDiff = std::abs(srcRow - destRow);
    int colDiff = std::abs(srcCol - destCol);

    return (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);
}

/*Checks if the knight is checking the enemy king
We check the 8 specific squares a knight can attack.*/
bool Knight::checkMakeCheck(int source[], const Board& board)
{
    int srcRow = source[ROW_INDEX];
    int srcCol = source[COL_INDEX];
    std::string currColor = board.getPiece(srcRow, srcCol)->getColor();
    bool makeCheck = false;

    int rowOffsets[] = { -2, -2, -1, -1,  1, 1,  2, 2 };
    int colOffsets[] = { -1,  1, -2,  2, -2, 2, -1, 1 };



    for (int i = 0; i < ROWS_AND_COLS && !makeCheck; i++)
    {
        int targetRow = srcRow + rowOffsets[i];
        int targetCol = srcCol + colOffsets[i];

        if (targetRow >= 0 && targetRow < ROWS_AND_COLS && targetCol >= 0 && targetCol < ROWS_AND_COLS)
        {
            std::string type = board.getPiece(targetRow, targetCol)->getType();
            std::string color = board.getPiece(targetRow, targetCol)->getColor();

            if (type == "king" && color != currColor)
            {
                makeCheck = true;
            }
        }
    }

    return makeCheck;
}