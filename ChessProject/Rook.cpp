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
    bool legal = true;
    int srcRow = source[ROW_INDEX];
    int srcCol = source[COL_INDEX];

    int destRow = destination[ROW_INDEX];
    int destCol = destination[COL_INDEX];

    int rowDiff = std::abs(srcRow - destRow);
    int colDiff = std::abs(srcCol - destCol);

    // rook can move only in straight lines (row OR column)
    if (rowDiff != 0 && colDiff != 0)
    {
        legal = false;
    }
    // horizontal move
// horizontal move
    else if (rowDiff == 0)
    {
        // moving left
        if (destCol < srcCol)
        {
            // Iterate strictly between source and dest
            for (int col = destCol + 1; col < srcCol; ++col)
            {
                // If ANY piece is here, the path is blocked
                if (board.getPiece(srcRow, col)->getType() != "empty")
                {
                    legal = false;
                }
            }
        }
        // moving right
        else
        {
            for (int col = srcCol + 1; col < destCol; ++col)
            {
                if (board.getPiece(srcRow, col)->getType() != "empty")
                {
                    legal = false;
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
                if (board.getPiece(row, srcCol)->getType() != "empty")
                {
                    legal = false;
                }
            }
        }
        // moving up
        else
        {
            for (int row = destRow + 1; row < srcRow; ++row)
            {
                if (board.getPiece(row, srcCol)->getType() != "empty")
                {
                    legal = false;
                }
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
    bool makeCheck = false;
    bool blocked = false;
    for (int j = srcCol + 1; j < ROWS_AND_COLS && !makeCheck; j++)
    {
        if (!blocked)
        {
            std::string type = board.getPiece(srcRow, j)->getType();
            std::string color = board.getPiece(srcRow, j)->getColor();
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
    }
    blocked = false;
    for (int j = srcCol - 1; j >= 0 && !makeCheck; j--)
    {
        if (!blocked)
        {
            std::string type = board.getPiece(srcRow, j)->getType();
            std::string color = board.getPiece(srcRow, j)->getColor();
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
    }
    blocked = false;
    for (int i = srcRow - 1; i >= 0 && !makeCheck; i--)
    {
        if (!blocked)
        {
            std::string type = board.getPiece(i, srcCol)->getType();
            std::string color = board.getPiece(i, srcCol)->getColor();
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
    }
    blocked = false;
    for (int i = srcRow + 1; i < ROWS_AND_COLS && !makeCheck; i++)
    {
        if (!blocked)
        {
            std::string type = board.getPiece(i, srcCol)->getType();
            std::string color = board.getPiece(i, srcCol)->getColor();
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
    }
    return makeCheck;
}
