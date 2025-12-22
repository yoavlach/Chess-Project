#include "Bishop.h"

/*Initializes a bishop
input: the bishop's type and color
output: none*/
Bishop::Bishop(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

/*Clears a bishop
input: none
output: none*/
Bishop::~Bishop()
{
}

/*Checks if a move is legal for a bishop
input: the source coordinates, the destination coordinates and the board
output: none*/
bool Bishop::checkLegalMove(int source[], int destination[], const Board& board)
{ 
    bool legal = true;
    int srcRow = source[ROW_INDEX];
    int srcCol = source[COL_INDEX];

    int destRow = destination[ROW_INDEX];
    int destCol = destination[COL_INDEX];

    int rowDiff = std::abs(srcRow - destRow);
    int colDiff = std::abs(srcCol - destCol);

    int colAndRow = 0, row = srcRow, col = srcCol;

    // only moves diagonaly so must move x rows and x cols
    if (rowDiff != colDiff)
    {
        legal = false;
    }
    //up
    else if (srcRow - destRow < 0)
    {
        for (row = row + 1; row < destRow; row++)
        {
            if (board.getPiece(row, col)->getType() != "empty")
            {
                legal = false;
            }
            if (colDiff > 0) //right
            {
                col++;
            }
            else //left
            {
                col--;
            }
        }
    }
    //down
    else if(legal)
    {
        for (row = row - 1; row > destRow; row--)
        {
            if (board.getPiece(row, col)->getType() != "empty")
            {
                legal = false;
            }
            if (colDiff > 0) //right
            {
                col++;
            }
            else //left
            {
                col--;
            }
        }
    }
    return legal;
}

/*Checks if the bishop is checking the enemy king
input: the source coordinates and the board
output: true if the bishop is checking the king, false otherwise*/
bool Bishop::checkMakeCheck(int source[], const Board& board)
{
    int srcRow = source[ROW_INDEX];
    int srcCol = source[COL_INDEX];
    std::string currColor = board.getPiece(srcRow, srcCol)->getColor();
    bool makeCheck = false;
    bool blocked = false;
    int row = srcRow, col = srcCol;
    std::string type = "", color = "";
    int i = 0;
    for (i = UP_RIGHT; i < DOWN_LEFT; i++)
    {
        row = srcRow, col = srcCol;
        blocked = false;
        while ((i == UP_RIGHT && row < ROWS_AND_COLS && col < ROWS_AND_COLS) ||
            (i == UP_LEFT && row < ROWS_AND_COLS && col > 0) ||
            (i == DOWN_RIGHT && row > 0 && col < ROWS_AND_COLS) ||
            (i == DOWN_LEFT && row > 0 && col > 0))
        {
            if (!blocked)
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
            switch (i)
            {
            case UP_RIGHT:
                row++, col++;
                break;
            case UP_LEFT:
                row++, col--;
                break;
            case DOWN_RIGHT:
                row--, col++;
                break;
            case DOWN_LEFT:
                row--, col--;
                break;
            }
        }
    }
    return makeCheck;
}