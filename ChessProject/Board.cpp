#include "Board.h"

/*Initializes the board
input: none
output: none*/
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

/*Initializes a player's side of the board
input: the color of the player
output: none*/
void Board::initPlayerSide(const std::string& color)
{
	// left the other pieces commented for now
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

/*Clears the board
input: none
output: none*/
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
/*Checks if there is a piece of the same color at the destination
input: the destination coordinates and the player color
output: none*/
void Board::checkIfPlayerOfSameColorInDest(const std::string& dest, const std::string& color) const
{
	int* destArr = new int[BOARD_INDEX_ARR_SIZE];
	translateStringToIndexes(dest, destArr);
	if (_board[destArr[ROW_INDEX]][destArr[COL_INDEX]]->getColor() == color)
	{
		throw std::string("Piece in destination belongs to current player");
	}
}

/*Checks if the piece at the source belongs to the current player
input: the source coordinates and the player color
output: none*/
void Board::checkIfPlayerOfSameColorInSource(const std::string& source, const std::string& color)  const
{
	int* srcArr = new int[BOARD_INDEX_ARR_SIZE];
	translateStringToIndexes(source, srcArr);
	if (_board[srcArr[ROW_INDEX]][srcArr[COL_INDEX]]->getColor() != color)
	{
		throw std::string("Piece in source doesn't belong to current player");
	}
}

/*Checks if the destination coordinates are valid
input: the destination coordinates
output: none*/
void Board::checkIllegalIndexes(const std::string& dest) const
{
	int* destArr = new int[BOARD_INDEX_ARR_SIZE];
	translateStringToIndexes(dest, destArr);
	if (!(destArr[ROW_INDEX] >= 0 && destArr[ROW_INDEX] < ROWS_AND_COLS &&
		destArr[COL_INDEX] >= 0 && destArr[COL_INDEX] < ROWS_AND_COLS))
	{
		throw std::string("Illegal indexes");
	}
}

/*Checks if the source and destination coordinates are the same
input: the source and destination coordinates
output: none*/
void Board::checkIndexesSame(const std::string& source, const std::string& dest) const
{
	if (source == dest)
	{
		throw std::string("Source and destination are the same");
	}
}

/*Converts string coordinates to array indexes
input: the string coordinates and the array to store the indexes
output: none*/
void Board::translateStringToIndexes(const std::string& str, int indexes[]) const
{
	indexes[ROW_INDEX] = str[1] - '1'; // row
	indexes[COL_INDEX] = str[0] - 'a'; // column
}

/*Gets the board array
input: none
output: the board array*/
ChessPiece*** Board::getBoard() const
{
	return _board;
}

/*Prints the board to the console
input: none
output: none*/
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
			{
				std::cout << ". ";
			}
			else
			{
				char c = piece->getType()[0];
				if (piece->getColor() == "white")
				{
					c = c - 32;
				}
				std::cout << c << " ";
			}
		}
		std::cout << "\n";
	}
	std::cout << "  a b c d e f g h\n";
}

/*Gets the piece at the specified indexes
input: the row index and the column index
output: the chess piece*/
ChessPiece* Board::getPiece(int firstIndex, int secondIndex) const
{
	return _board[firstIndex][secondIndex];
}

/*Moves a piece from the source to the destination
input: the source and destination coordinates
output: none*/
void Board::move(const std::string& source, const std::string& destination)
{
	int sourceArr[BOARD_INDEX_ARR_SIZE];
	int destArr[BOARD_INDEX_ARR_SIZE];
	translateStringToIndexes(source, sourceArr);
	translateStringToIndexes(destination, destArr);

	checkIndexesSame(source, destination);
	checkIllegalIndexes(destination);
	checkIfPlayerOfSameColorInSource(source, _turn ? "white" : "black");
	checkIfPlayerOfSameColorInDest(destination, _turn ? "white" : "black");
	_board[sourceArr[ROW_INDEX]][sourceArr[COL_INDEX]]->checkLegalMove(sourceArr, destArr, *this);

	checkIfMakeCheckOnCurrPlayer(source, destination);

	move(sourceArr, destArr);

	if (checkIfMakeCheckOnOtherPlayer(source, destination))
	{
		std::cout << "There is a check on " << (_turn ? "black" : "white") << "\n";
	}

	_turn = !_turn;
}

/*Checks if a move will result in a check on the current player
input: the source and destination coordinates
output: none*/
void Board::checkIfMakeCheckOnCurrPlayer(const std::string& source, const std::string& dest)
{
	int sourceArr[BOARD_INDEX_ARR_SIZE];
	int destArr[BOARD_INDEX_ARR_SIZE];
	translateStringToIndexes(source, sourceArr);
	translateStringToIndexes(dest, destArr);
	std::string currPlayerColor = _turn ? "white" : "black";
	int i = 0, j = 0;
	int attackerPos[BOARD_INDEX_ARR_SIZE] = { 0 };
	move(sourceArr, destArr);
	for (i = 0; i < ROWS_AND_COLS; i++)
	{
		for (j = 0; j < ROWS_AND_COLS; j++)
		{
			attackerPos[ROW_INDEX] = i;
			attackerPos[COL_INDEX] = j;
			if (_board[i][j]->getColor() == (currPlayerColor == "white" ? "black" : "white") && _board[i][j]->checkMakeCheck(attackerPos, *this))
			{
				move(destArr, sourceArr);
				throw std::string("This move makes a check on the current player");
			}
		}
	}
	move(destArr, sourceArr);
}

/*Checks if a move will result in a check on the opponent
input: the source and destination coordinates
output: true if the move causes a check, false otherwise*/
bool Board::checkIfMakeCheckOnOtherPlayer(const std::string& source, const std::string& dest) const
{
	bool makeCheck = false;
	int sourceArr[BOARD_INDEX_ARR_SIZE];
	int destArr[BOARD_INDEX_ARR_SIZE];
	int attackerPos[BOARD_INDEX_ARR_SIZE] = { 0 };
	translateStringToIndexes(source, sourceArr);
	translateStringToIndexes(dest, destArr);
	std::string currPlayerColor = _turn ? "white" : "black";
	int i = 0, j = 0;
	for (i = 0; i < ROWS_AND_COLS && !makeCheck; i++)
	{
		for (j = 0; j < ROWS_AND_COLS && !makeCheck; j++)
		{
			attackerPos[ROW_INDEX] = i;
			attackerPos[COL_INDEX] = j;
			makeCheck = _board[i][j]->getColor() == currPlayerColor && _board[i][j]->checkMakeCheck(attackerPos, *this);
		}
	}
	return makeCheck;
}

/*Moves a piece using array indexes
input: the source indexes array and the destination indexes array
output: none*/
void Board::move(int src[], int dest[])
{
	delete _board[dest[ROW_INDEX]][dest[COL_INDEX]];
	_board[dest[ROW_INDEX]][dest[COL_INDEX]] = _board[src[ROW_INDEX]][src[COL_INDEX]];
	_board[src[ROW_INDEX]][src[COL_INDEX]] = new EmptyChessPiece("empty", "empty");
}

