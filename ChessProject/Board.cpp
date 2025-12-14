#include "Board.h"

Board::Board()
{
	int i = 0, j = 0;
	_board = new ChessPiece**[ROWS_AND_COLS];
	for (i = 0; i < ROWS_AND_COLS; i++)
	{
		_board[i] = new ChessPiece * [ROWS_AND_COLS];
	}
	for (int i = 0; i < ROWS_AND_COLS; i++)
	{
		for (int j = 0; j < ROWS_AND_COLS; j++)
		{
			_board[i][j] = new EmptyChessPiece("empty", "empty");
		}
	}
	initPlayerSide("white");
	initPlayerSide("black");
	_turn = true;
}

void Board::initPlayerSide(const std::string& color)
{
	int row = color == "white" ? WHITE_ROW : BLACK_ROW;
	int pawnRow = color == "white" ? WHITE_PAWN_ROW : BLACK_PAWN_ROW;
	int i = 0;
	delete _board[row][LEFT_ROOK];
	_board[row][LEFT_ROOK] = new Rook("rook", color);
	//_board[row][LEFT_KNIGHT] = new Knight("knight", color);
	//_board[row][LEFT_BISHOP] = new Bishop("bishop", color);
	delete _board[row][KING];
	_board[row][KING] = new King("king", color);
	//_board[row][QUEEN] = new Queen("queen", color);
	//_board[row][RIGHT_BISHOP] = new Bishop("bishop", color);
	//_board[row][RIGHT_KNIGHT] = new Knight("knight", color);
	delete _board[row][RIGHT_ROOK];
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
bool Board::checkIfPlayerOfSameColorInDest(const std::string& dest, const std::string& color) const
{
	int* destArr = new int[2];
	translateStringToIndexes(dest, destArr);
	return _board[destArr[ROW_INDEX]][destArr[COL_INDEX]]->getColor() == color;
}
bool Board::checkIfPlayerOfSameColorInSource(const std::string& source, const std::string& color)  const
{
	int* srcArr = new int[2];
	translateStringToIndexes(source, srcArr);
	return _board[srcArr[ROW_INDEX]][srcArr[COL_INDEX]]->getColor() == color;
}
bool Board::checkIllegalIndexes(const std::string& dest) const
{
	int* destArr = new int[2];
	translateStringToIndexes(dest, destArr);
	return dest[ROW_INDEX] > ROWS_AND_COLS || dest[COL_INDEX] > ROWS_AND_COLS || dest[ROW_INDEX] < 0 || dest[COL_INDEX] < 0;
}
bool Board::checkIndexesSame(const std::string& source, const std::string& dest) const
{
	return source == dest;
}
void Board::translateStringToIndexes(const std::string& str, int indexes[]) const
{
	indexes[ROW_INDEX] = str[1] - '1'; // row
	indexes[COL_INDEX] = str[0] - 'a'; // column
}
ChessPiece*** Board::getBoard() const
{
	return _board;
}
void Board::printBoard() const
{
	int i = 0, j = 0;
	for (int i = ROWS_AND_COLS - 1; i >= 0; --i)
	{
		std::cout << i + 1 << " ";
		for (int j = 0; j < ROWS_AND_COLS; ++j)
		{
			ChessPiece* piece = _board[i][j];
			if (piece->getType() == "empty")
				std::cout << ". ";
			else
				std::cout << piece->getType()[0] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "  a b c d e f g h\n";
}
ChessPiece* Board::getPiece(int firstIndex, int secondIndex) const
{
	return _board[firstIndex][secondIndex];
}
void Board::move(const std::string& source, const std::string& destination)
{
	bool isLegal = true;
	int sourceArr[2];
	int destArr[2];
	translateStringToIndexes(source, sourceArr);
	translateStringToIndexes(destination, destArr);
	isLegal = _board[sourceArr[ROW_INDEX]][sourceArr[COL_INDEX]]->checkLegalMove(sourceArr, destArr, *this);
	if (
		//checkIfMakeCheck
		//CheckIfCauseCheck
		checkIfPlayerOfSameColorInSource(source, _turn ? "white" : "black") &&
		!checkIfPlayerOfSameColorInDest(destination, _turn ? "white" : "black") &&
		!checkIllegalIndexes(destination) &&
		!checkIndexesSame(source, destination)
		)
	{
		isLegal = false;
	}
	if (isLegal)
	{
		delete _board[destArr[ROW_INDEX]][destArr[COL_INDEX]];
		_board[destArr[ROW_INDEX]][destArr[COL_INDEX]] = _board[sourceArr[ROW_INDEX]][sourceArr[COL_INDEX]];
		_board[sourceArr[ROW_INDEX]][sourceArr[COL_INDEX]] = new EmptyChessPiece("empty", "empty");
		_turn = !_turn;
	}
}
