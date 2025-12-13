#include "Board.h"

Board::Board()
{
	int i = 0, j = 0;
	_board = new ChessPiece**[ROWS_AND_COLS];
	for (i = 0; i < ROWS_AND_COLS; i++)
	{
		_board[i] = new ChessPiece * [ROWS_AND_COLS];
	}
	initPlayerSide("white");
	initPlayerSide("black");
	for (i = 0; i < ROWS_AND_COLS; i++)
	{
		if (i != LEFT_ROOK && i != RIGHT_ROOK && i != KING)
		{
			_board[WHITE_ROW][i] = new EmptyChessPiece("empty", "empty");
		}
	}
	for (i = 0; i < ROWS_AND_COLS; i++)
	{
		if (i != LEFT_ROOK && i != RIGHT_ROOK && i != KING)
		{
			_board[BLACK_ROW][i] = new EmptyChessPiece("empty", "empty");
		}
	}
	for (i = WHITE_PAWN_ROW; i <= BLACK_PAWN_ROW; i++)
	{
		for (j = 0; j < ROWS_AND_COLS; j++)
		{
			_board[i][j] = new EmptyChessPiece("empty", "empty");
		}
	}
	_turn = true;
}

void Board::initPlayerSide(const std::string& color)
{
	int row = color == "white" ? WHITE_ROW : BLACK_ROW;
	int pawnRow = color == "white" ? WHITE_PAWN_ROW : BLACK_PAWN_ROW;
	int i = 0;
	_board[row][LEFT_ROOK] = new Rook("rook", color);
	//_board[row][LEFT_KNIGHT] = new Knight("knight", color);
	//_board[row][LEFT_BISHOP] = new Bishop("bishop", color);
	_board[row][KING] = new King("king", color);
	//_board[row][QUEEN] = new Queen("queen", color);
	//_board[row][RIGHT_BISHOP] = new Bishop("bishop", color);
	//_board[row][RIGHT_KNIGHT] = new Knight("knight", color);
	_board[row][RIGHT_ROOK] = new Rook("rook", color);
	//for (i = 0; i < ROWS_AND_COLS; i++)
	//{
	//	_board[pawnRow][i] = new Pawn("pawn", color);
	//}
}
Board::~Board()
{
	int i = 0, j = 0;
	for (i = 0; i < ROWS_AND_COLS; i++)
	{
		for (j = 0; j < ROWS_AND_COLS; j++)
		{
			delete _board[i][j];
		}
	}
}
bool Board::checkIfPlayerOfSameColorInDest(const std::string& dest, const std::string& color)
{
	int* destArr = new int[2];
	translateStringToIndexes(dest, destArr);
	return _board[destArr[0]][destArr[1]]->getType() != "empty" && _board[destArr[0]][destArr[1]]->getColor() == color;
}
//bool Board::checkIfMakeCheck(const std::string& source, const std::string& dest)
//{
//	int i = 0, j = 0;
//	bool makeCheck = false;
//	std::string currColor = _turn ? "white" : "black";
//	for (i = 0; i < ROWS_AND_COLS; i++)
//	{
//		for (j = 0; j < ROWS_AND_COLS; j++)
//		{
//			if (_board[i][j]->getColor() == currColor && _board[i][j]->checkMakeCheck())
//			{
//				makeCheck = true;
//			}
//		}
//	}
//	return makeCheck;
//}
//bool Board::CheckIfCauseCheck(const std::string& source, const std::string& dest)
//{
//	int i = 0, j = 0;
//	bool causeCheck = false;
//	std::string currColor = _turn ? "white" : "black";
//	for (i = 0; i < ROWS_AND_COLS; i++)
//	{
//		for (j = 0; j < ROWS_AND_COLS; j++)
//		{
//			if (_board[i][j]->getColor() != currColor && _board[i][j]->checkMakeCheck())
//			{
//				causeCheck = true;
//			}
//		}
//	}
//	return causeCheck;
//}
bool Board::checkIfPlayerOfSameColorInSource(const std::string& source, const std::string& color)
{
	int* srcArr = new int[2];
	translateStringToIndexes(source, srcArr);
	return _board[srcArr[0]][srcArr[1]]->getType() != "empty" && _board[srcArr[0]][srcArr[1]]->getColor() == color;
}
bool Board::checkIllegalIndexes(const std::string& dest)
{
	int* destArr = new int[2];
	translateStringToIndexes(dest, destArr);
	return dest[0] < ROWS_AND_COLS && dest[1] < ROWS_AND_COLS;
}
bool Board::checkIndexesSame(const std::string& source, const std::string& dest)
{
	return source == dest;
}
void Board::translateStringToIndexes(const std::string& str, int indexes[])
{
	indexes[0] = str[0] - 97;
	indexes[1] = str[1] - 48;
}
ChessPiece*** Board::getBoard()
{
	return _board;
}
void Board::printBoard()
{
	int i = 0, j = 0;
	for (i = 0; i < ROWS_AND_COLS; i++)
	{
		for (j = 0; j < ROWS_AND_COLS; j++)
		{
			std::cout << _board[i][j]->getType() << " ";
		}
		std::cout << "\n";
	}
}
ChessPiece* Board::getPiece(int firstIndex, int secondIndex)
{
	return _board[firstIndex][secondIndex];
}
void Board::move(const std::string& source, const std::string& destination)
{
	int* sourceArr = new int[2];
	int* destArr = new int[2];
	translateStringToIndexes(source, sourceArr);
	translateStringToIndexes(destination, destArr);
	std::cout << _board[sourceArr[0]][sourceArr[1]]->checkLegalMove(sourceArr, destArr, *this);
}