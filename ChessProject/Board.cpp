#include "Board.h"

Board::Board()
{
	int i = 0, j = 0;
	initPlayerSide("white");
	initPlayerSide("black");
	for (i = WHITE_PAWN_ROW + 1; i < BLACK_PAWN_ROW; i++)
	{
		for (j = 0; j < ROWS_AND_COLS; j++)
		{
			_board[i][j] = new EmptyChessPiece("empty", "empty");
		}
	}
}

void Board::initPlayerSide(const std::string& color)
{
	int row = color == "white" ? WHITE_ROW : BLACK_ROW;
	int pawnRow = color == "white" ? WHITE_PAWN_ROW : BLACK_PAWN_ROW;
	int i = 0;
	_board[row][LEFT_ROOK] = new Rook("rook", color);
	_board[row][LEFT_KNIGHT] = new Knight("knight", color);
	_board[row][LEFT_BISHOP] = new Bishop("rook", color);
	_board[row][KING] = new King("rook", color);
	_board[row][QUEEN] = new Queen("rook", color);
	_board[row][RIGHT_BISHOP] = new Bishop("rook", color);
	_board[row][RIGHT_KNIGHT] = new Knight("rook", color);
	_board[row][RIGHT_ROOK] = new Rook("rook", color);
	for (i = 0; i < ROWS_AND_COLS; i++)
	{
		_board[pawnRow][i] = new Pawn("pawn", color);
	}
}
Board::~Board()
{
	int i = 0, j = 0;
	for (i = 0; i < ROWS_AND_COLS; i++)
	{
		for (j = 0; j < ROWS_AND_COLS; j++)
		{
			~_board[i][j];
		}
	}
}
bool Board::checkIfPlayerOfSameColorInDest(const std::string& dest, const std::string& color)
{
	int* destArr = new int[2];
	translateStringToIndexes(dest, destArr);
	return _board[destArr[0]][destArr[1]].getType() != "empty" && _board[destArr[0]][destArr[1]].getColor() == color;
}
//bool checkIfMakeCheck(const std::string& source, const std::string& dest);
//bool CheckIfCauseCheck(const std::string& source, const std::string& dest);
bool Board::checkIfPlayerOfSameColorInSource(const std::string& source, const std::string& color)
{
	int* srcArr = new int[2];
	translateStringToIndexes(source, srcArr);
	return _board[srcArr[0]][srcArr[1]].getType() != "empty" && _board[srcArr[0]][srcArr[1]].getColor() == color;
}
bool Board::checkIllegalIndexes(const std::string& dest)
{
	int* dest = new int[2];
	return dest[0] < ROWS_AND_COLS && dest[1] < ROWS_AND_COLS;
}
bool checkIndexesSame(const std::string& source, const std::string& dest)
{
	return source == dest;
}
void Board::translateStringToIndexes(const std::string& str, int indexes[])
{
	indexes[0] = str[0] - 97;
	indexes[1] = str[1] - 48;
}