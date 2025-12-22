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
	for (int i = WHITE_PAWN_ROW + 1; i < BLACK_PAWN_ROW; i++)
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
	_board[row][LEFT_ROOK] = new Rook("rook", color);
	_board[row][LEFT_KNIGHT] = new Knight("knight", color);
	_board[row][LEFT_BISHOP] = new Bishop("bishop", color);
	_board[row][KING] = new King("king", color);
	_board[row][QUEEN] = new Queen("queen", color);
	_board[row][RIGHT_BISHOP] = new Bishop("bishop", color);
	_board[row][RIGHT_KNIGHT] = new Knight("knight", color);
	_board[row][RIGHT_ROOK] = new Rook("rook", color);
	for (i = 0; i < ROWS_AND_COLS; i++)
	{
		_board[pawnRow][i] = new Pawn("pawn", color);
	}
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
bool Board::checkIfPlayerOfSameColorInDest(const std::string& dest, const std::string& color) const
{
	bool legal = true;
	int* destArr = new int[BOARD_INDEX_ARR_SIZE];
	translateStringToIndexes(dest, destArr);
	legal = _board[destArr[ROW_INDEX]][destArr[COL_INDEX]]->getColor() == color;
	delete[] destArr;
	return legal;
}

/*Checks if the piece at the source belongs to the current player
input: the source coordinates and the player color
output: none*/
bool Board::checkIfPlayerOfSameColorInSource(const std::string& source, const std::string& color)  const
{
	bool legal = true;
	int* srcArr = new int[BOARD_INDEX_ARR_SIZE];
	translateStringToIndexes(source, srcArr);
	legal = _board[srcArr[ROW_INDEX]][srcArr[COL_INDEX]]->getColor() != color;
	delete[] srcArr;
	return legal;
}

/*Checks if the destination coordinates are valid
input: the destination coordinates
output: none*/
bool Board::checkIllegalIndexes(const std::string& dest) const
{
	bool legal = true;
	int* destArr = new int[BOARD_INDEX_ARR_SIZE];
	translateStringToIndexes(dest, destArr);
	legal = !(destArr[ROW_INDEX] >= 0 && destArr[ROW_INDEX] < ROWS_AND_COLS &&
		destArr[COL_INDEX] >= 0 && destArr[COL_INDEX] < ROWS_AND_COLS);
	delete[] destArr;
	return legal;
}

/*Checks if the source and destination coordinates are the same
input: the source and destination coordinates
output: none*/
bool Board::checkIndexesSame(const std::string& source, const std::string& dest) const
{
	return source == dest;
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
				if (piece->getType() == "knight")
				{
					c = piece->getColor() == "white" ? 'N' : 'n';
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
int Board::move(const std::string& source, const std::string& destination)
{
	std::cout << "Curr turn: " << (_turn ? "white" : "black") << "\n";
	int sourceArr[BOARD_INDEX_ARR_SIZE];
	int destArr[BOARD_INDEX_ARR_SIZE];
	int msgCode = VALID_MOVE;
	translateStringToIndexes(source, sourceArr);
	translateStringToIndexes(destination, destArr);
	if(checkIndexesSame(source, destination)) msgCode = SAME_SOURCE_AND_DEST;
	if(msgCode == VALID_MOVE && checkIllegalIndexes(destination)) msgCode = ILLEGAL_INDEX;
	if(msgCode == VALID_MOVE && checkIfPlayerOfSameColorInSource(source, _turn ? "white" : "black")) msgCode = NO_PIECE_IN_SOURCE;
	if(msgCode == VALID_MOVE && checkIfPlayerOfSameColorInDest(destination, _turn ? "white" : "black")) msgCode = SAME_COLOR_IN_DEST;
	if(msgCode == VALID_MOVE && _board[sourceArr[ROW_INDEX]][sourceArr[COL_INDEX]]->checkLegalMove(sourceArr, destArr, *this)) msgCode = ILLEGAL_PIECE_MOVE;

	if(msgCode == VALID_MOVE && checkIfMakeCheckOnCurrPlayer(source, destination)) msgCode = MOVE_CAUSES_SELF_CHECK;
	if(msgCode == VALID_MOVE) move(sourceArr, destArr);

	if (msgCode == VALID_MOVE && checkIfMakeCheckOnOtherPlayer(source, destination)) msgCode = VALID_MOVE_CHECK;

	if (msgCode == VALID_MOVE || msgCode == VALID_MOVE_CHECK)
	{
		_turn = !_turn;
	}
	return msgCode;
}

/*Checks if a move will result in a check on the current player
input: the source and destination coordinates
output: none*/
bool Board::checkIfMakeCheckOnCurrPlayer(const std::string& source, const std::string& dest)
{
	int sourceArr[BOARD_INDEX_ARR_SIZE];
	int destArr[BOARD_INDEX_ARR_SIZE];
	int attackerPos[BOARD_INDEX_ARR_SIZE];
	translateStringToIndexes(source, sourceArr);
	translateStringToIndexes(dest, destArr);

	ChessPiece* movingPiece = _board[sourceArr[ROW_INDEX]][sourceArr[COL_INDEX]];
	ChessPiece* capturedPiece = _board[destArr[ROW_INDEX]][destArr[COL_INDEX]];

	_board[destArr[ROW_INDEX]][destArr[COL_INDEX]] = movingPiece;
	_board[sourceArr[ROW_INDEX]][sourceArr[COL_INDEX]] = new EmptyChessPiece("empty", "empty");

	std::string currPlayerColor = _turn ? "white" : "black";
	bool isCheck = false;
	int i = 0, j = 0;

	for (i = 0; i < ROWS_AND_COLS && !isCheck; i++)
	{
		for (j = 0; j < ROWS_AND_COLS && !isCheck; j++)
		{
			attackerPos[ROW_INDEX] = i;
			attackerPos[COL_INDEX] = j;
			if (_board[i][j]->getColor() == (currPlayerColor == "white" ? "black" : "white") && _board[i][j]->checkMakeCheck(attackerPos, *this))
			{
				isCheck = true;
			}
		}
	}

	delete _board[sourceArr[ROW_INDEX]][sourceArr[COL_INDEX]];
	_board[sourceArr[ROW_INDEX]][sourceArr[COL_INDEX]] = movingPiece;
	_board[destArr[ROW_INDEX]][destArr[COL_INDEX]] = capturedPiece;

	return isCheck;
}

/*Checks if a move will result in a check on the opponent
input: the source and destination coordinates
output: true if the move causes a check, false otherwise*/
bool Board::checkIfMakeCheckOnOtherPlayer(const std::string& source, const std::string& dest) const
{
	bool makeCheck = false;
	int* sourceArr = new int[BOARD_INDEX_ARR_SIZE];
	int* destArr = new int[BOARD_INDEX_ARR_SIZE];
	int* attackerPos = new int[BOARD_INDEX_ARR_SIZE];
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
	delete[] sourceArr;
	delete[] destArr;
	delete[] attackerPos;
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

