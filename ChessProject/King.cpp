#include "King.h"
#include <cmath>

/*Initializes a king
input: the king's type and color
output: none*/
King::King(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

/*Clears a king
input: none
output: none*/
King::~King()
{
}

/*Checks if a move is legal for a king
input: the source coordinates, the destination coordinates and the board
output: none*/
bool King::checkLegalMove(int source[], int destination[], const Board& board)
{
    int srcRow = source[0];
    int srcCol = source[1];

    int destRow = destination[0];
    int destCol = destination[1];

    int rowDiff = std::abs(srcRow - destRow);
    int colDiff = std::abs(srcCol - destCol);

    return rowDiff > 1 || colDiff > 1;
}

/*Checks if the king is checking the enemy king
input: the source coordinates and the board
output: true if the king is checking the king, false otherwise*/
bool King::checkMakeCheck(int source[], const Board& board)
{
        int srcRow = source[ROW_INDEX];
        int srcCol = source[COL_INDEX];
        int checkRow = 0;
        int checkCol = 0;
        bool makeCheck = false;
        std::string sourceColor = board.getPiece(srcRow, srcCol)->getColor();
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i != 0 || j != 0)
                {
                    checkRow = srcRow + i;
                    checkCol = srcCol + j;
                    if (checkRow >= 0 && checkRow < ROWS_AND_COLS &&
                        checkCol >= 0 && checkCol < ROWS_AND_COLS)
                    {
                        ChessPiece* piece = board.getPiece(checkRow, checkCol);
                        if (piece->getType() == "king" && piece->getColor() != sourceColor)
                        {
                            makeCheck = true;
                        }
                    }
                }

            }
        }
        return makeCheck;
}