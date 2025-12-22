#pragma once
#include <iostream>

#include "Bishop.h"
#include "EmptyChessPiece.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

#define ROWS_AND_COLS 8
#define START_STRING "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0"
#define BLACK_ROW 7
#define WHITE_ROW 0
#define BLACK_PAWN_ROW 6
#define WHITE_PAWN_ROW 1
#define ROW_INDEX 0
#define COL_INDEX 1
#define BOARD_INDEX_ARR_SIZE 2
enum PIECES_INDEXES { LEFT_ROOK, LEFT_KNIGHT, LEFT_BISHOP, QUEEN, KING, RIGHT_BISHOP, RIGHT_KNIGHT, RIGHT_ROOK };
enum MSG_CODES { VALID_MOVE, VALID_MOVE_CHECK, NO_PIECE_IN_SOURCE, SAME_COLOR_IN_DEST, MOVE_CAUSES_SELF_CHECK, ILLEGAL_INDEX, ILLEGAL_PIECE_MOVE, SAME_SOURCE_AND_DEST, VALID_MOVE_CHECKMATE };

class ChessPiece;

class Board
{
public:
	Board();
	~Board();
	void initPlayerSide(const std::string& color);
	bool checkIfMakeCheckOnCurrPlayer(const std::string& source, const std::string& dest);
	bool checkIfMakeCheckOnOtherPlayer(const std::string& source, const std::string& dest) const;
	bool checkIfPlayerOfSameColorInSource(const std::string& source, const std::string& color) const;
	bool checkIfPlayerOfSameColorInDest(const std::string& dest, const std::string& color) const;
	bool checkIllegalIndexes(const std::string& dest) const;
	bool checkIndexesSame(const std::string& source, const std::string& dest) const;
	int move(const std::string& source, const std::string& destination);
	void move(int src[], int dest[]);
	void translateStringToIndexes(const std::string& str, int indexes[]) const;
	ChessPiece*** getBoard() const;
	void printBoard() const;
	ChessPiece* getPiece(int firstIndex, int secondIndex) const;
private:
	ChessPiece*** _board; //a 2d array of pointer to chess pieces
	bool _turn; //true: white, false: black
};