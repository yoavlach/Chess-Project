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
void King::checkLegalMove(int source[], int destination[], const Board& board)
{
    int srcRow = source[0];
    int srcCol = source[1];

    int destRow = destination[0];
    int destCol = destination[1];

    int rowDiff = std::abs(srcRow - destRow);
    int colDiff = std::abs(srcCol - destCol);

    if (rowDiff > 1 || colDiff > 1)
    {
        throw std::string("Piece can't move that way");
    }

    ChessPiece* targetPiece = board.getPiece(destRow, destCol);
}

/*Checks if the king is checking the enemy king
input: the source coordinates and the board
output: true if the king is checking the king, false otherwise*/
bool King::checkMakeCheck(int source[], const Board& board)
{
    int srcRow = source[ROW_INDEX];
    int srcCol = source[COL_INDEX];
    std::string sourceColor = board.getPiece(srcRow, srcCol)->getColor();
    // for each check we are checking if the indexes we check are in range and if there is a king of the opposite color there
    return (srcRow + 1 < ROWS_AND_COLS && board.getPiece(srcRow + 1, srcCol)->getType() == "king" && board.getPiece(srcRow + 1, srcCol)->getColor() != sourceColor) || // up
        (srcRow + 1 < ROWS_AND_COLS && srcCol + 1 < ROWS_AND_COLS && board.getPiece(srcRow + 1, srcCol + 1)->getType() == "king" && board.getPiece(srcRow + 1, srcCol + 1)->getColor() != sourceColor) || // up-right
        (srcCol + 1 < ROWS_AND_COLS && board.getPiece(srcRow, srcCol + 1)->getType() == "king" && board.getPiece(srcRow, srcCol + 1)->getColor() != sourceColor) || // right
        (srcRow - 1 >= 0 && srcCol + 1 < ROWS_AND_COLS && board.getPiece(srcRow - 1, srcCol + 1)->getType() == "king" && board.getPiece(srcRow - 1, srcCol + 1)->getColor() != sourceColor) || // down-right
        (srcRow - 1 >= 0 && board.getPiece(srcRow - 1, srcCol)->getType() == "king" && board.getPiece(srcRow - 1, srcCol)->getColor() != sourceColor) || // down
        (srcRow - 1 >= 0 && srcCol - 1 >= 0 && board.getPiece(srcRow - 1, srcCol - 1)->getType() == "king" && board.getPiece(srcRow - 1, srcCol - 1)->getColor() != sourceColor) || // down-left
        (srcCol - 1 >= 0 && board.getPiece(srcRow, srcCol - 1)->getType() == "king" && board.getPiece(srcRow, srcCol - 1)->getColor() != sourceColor) || // left
        (srcRow + 1 < ROWS_AND_COLS && srcCol - 1 >= 0 && board.getPiece(srcRow + 1, srcCol - 1)->getType() == "king" && board.getPiece(srcRow + 1, srcCol - 1)->getColor() != sourceColor); // up-left
}