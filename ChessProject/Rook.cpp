#include "Rook.h"

/*Initializes a rook
input: the rook's type and color
output: none*/
Rook::Rook(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

/*Clears a rook
input: none
output: none*/
Rook::~Rook()
{
}

/*Checks if a move is legal for a rook
input: the source coordinates, the destination coordinates and the board
output: none*/
bool Rook::checkLegalMove(int source[], int destination[], const Board& board)
{
    bool legal = true, reachDest = false;
    int srcRow = source[ROW_INDEX];
    int srcCol = source[COL_INDEX];
    int destRow = destination[ROW_INDEX];
    int destCol = destination[COL_INDEX];
    int rowDiff = std::abs(srcRow - destRow);
    int colDiff = std::abs(srcCol - destCol);
    int row = srcRow, col = srcCol;
    // rook can move only in straight lines (row OR column)
    if (rowDiff != 0 && colDiff != 0)
    {
        legal = false;
    }
    else
    {
        while (!reachDest && legal)
        {
            if (destRow - srcRow > 0) row++;
            else if (destRow - srcRow < 0) row--;
            else if (destCol - srcCol > 0) col++;
            else col--;
            if (row != destRow || col != destCol)
            {
                if (board.getPiece(row, col)->getType() != "empty")
                {
                    legal = false;
                }
            }
            else
            {
                reachDest = true;
            }
        }
    }
    return legal;
}

/*Checks if the rook is checking the enemy king
input: the source coordinates and the board
output: true if the rook is checking the king, false otherwise*/
bool Rook::checkMakeCheck(int source[], const Board& board)
{
    int srcRow = source[ROW_INDEX];
    int srcCol = source[COL_INDEX];
    std::string currColor = board.getPiece(srcRow, srcCol)->getColor();
    std::string type = "", color = "";
    bool makeCheck = false, blocked = false, inBounds = true;
    int direction = 0;
    int row = 0, col = 0;
    for (direction = UP; direction <= RIGHT && !makeCheck; direction++)
    {
        blocked = false;
        row = srcRow, col = srcCol;
        inBounds = true;
        while (inBounds && !blocked)
        {
            if (direction == UP) row++;
            else if (direction == DOWN) row--;
            else if (direction == RIGHT) col++;
            else col--;
            if (row < ROWS_AND_COLS && row >= 0 && col < ROWS_AND_COLS && col >= 0 && !blocked)
            {
                type = board.getPiece(row, col)->getType();
                color = board.getPiece(row, col)->getColor();
                if (type != "empty")
                {
                    if (type == "king" && color != currColor)
                    {
                        makeCheck = true;
                    }
                    else
                    {
                        blocked = true;
                    }
                }
            }
            else
            {
                inBounds = false;
            }
        }
    }
    return makeCheck;
}
