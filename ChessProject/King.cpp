#include "King.h"
#include <cmath>

King::King(const std::string& type, const std::string& color) : ChessPiece(color, type)
{
}

King::~King()
{
}

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