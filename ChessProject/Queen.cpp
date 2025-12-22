#include "Queen.h"
#include <cmath> // Required for std::abs

/*Initializes a queen
input: the queen's type and color
output: none*/
Queen::Queen(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

/*Clears a queen
input: none
output: none*/
Queen::~Queen()
{
}

/*Checks if a move is legal for a queen
input: the source coordinates, the destination coordinates and the board
output: none*/
bool Queen::checkLegalMove(int source[], int destination[], const Board& board)
{
    bool legal = true;
    int srcRow = source[ROW_INDEX];
    int srcCol = source[COL_INDEX];

    int destRow = destination[ROW_INDEX];
    int destCol = destination[COL_INDEX];

    int rowDiff = std::abs(srcRow - destRow);
    int colDiff = std::abs(srcCol - destCol);

    bool isStraight = (srcRow == destRow || srcCol == destCol);
    bool isDiagonal = (rowDiff == colDiff);

    if (!isStraight && !isDiagonal)
    {
        legal = false;
    }

    if (isStraight && legal)
    {
        if (rowDiff == 0)
        {
            if (destCol < srcCol)
            {
                for (int col = destCol + 1; col < srcCol; ++col)
                {
                    if (board.getPiece(srcRow, col)->getType() != "empty")
                    {
                        legal = false;
                    }
                }
            }
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
        else
        {
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
    }
    else
    {
        int rowStep = 0;
        int colStep = 0;

        if (destRow > srcRow)
        {
            rowStep = 1;
        }
        else
        {
            rowStep = -1;
        }

        if (destCol > srcCol)
        {
            colStep = 1;
        }
        else
        {
            colStep = -1;
        }

        for (int i = 1; i < rowDiff; ++i)
        {
            int currentRow = srcRow + (i * rowStep);
            int currentCol = srcCol + (i * colStep);

            if (board.getPiece(currentRow, currentCol)->getType() != "empty")
            {
                legal = false;
            }
        }
    }
    return legal;
}

/*Checks if the queen is checking the enemy king
input: the source coordinates and the board
output: true if the queen is checking the king, false otherwise*/
bool Queen::checkMakeCheck(int source[], const Board& board)
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
    blocked = false;

    for (int i = srcRow + 1, j = srcCol + 1; i < ROWS_AND_COLS && j < ROWS_AND_COLS && !makeCheck; i++, j++)
    {
        if (!blocked)
        {
            std::string type = board.getPiece(i, j)->getType();
            std::string color = board.getPiece(i, j)->getColor();
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

    for (int i = srcRow + 1, j = srcCol - 1; i < ROWS_AND_COLS && j >= 0 && !makeCheck; i++, j--)
    {
        if (!blocked)
        {
            std::string type = board.getPiece(i, j)->getType();
            std::string color = board.getPiece(i, j)->getColor();
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

    for (int i = srcRow - 1, j = srcCol + 1; i >= 0 && j < ROWS_AND_COLS && !makeCheck; i--, j++)
    {
        if (!blocked)
        {
            std::string type = board.getPiece(i, j)->getType();
            std::string color = board.getPiece(i, j)->getColor();
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

    for (int i = srcRow - 1, j = srcCol - 1; i >= 0 && j >= 0 && !makeCheck; i--, j--)
    {
        if (!blocked)
        {
            std::string type = board.getPiece(i, j)->getType();
            std::string color = board.getPiece(i, j)->getColor();
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