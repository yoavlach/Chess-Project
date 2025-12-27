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
    else
    {
        legal = isStraight ? Rook("rook", board.getPiece(srcRow, srcCol)->getColor()).checkLegalMove(source, destination, board) :
            Bishop("bishop", board.getPiece(srcRow, srcCol)->getColor()).checkLegalMove(source, destination, board);
    }
    return legal;
}

/*Checks if the queen is checking the enemy king
input: the source coordinates and the board
output: true if the queen is checking the king, false otherwise*/
bool Queen::checkMakeCheck(int source[], const Board& board)
{
    std::string currColor = board.getPiece(source[ROW_INDEX], source[COL_INDEX])->getColor();
    return Bishop("bishop", currColor).checkMakeCheck(source, board) || Rook("rook", currColor).checkMakeCheck(source, board);
}