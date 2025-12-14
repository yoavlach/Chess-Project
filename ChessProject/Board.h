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

class ChessPiece;

class Board
{
public:
	Board();
	~Board();
	void initPlayerSide(const std::string& color);
	void checkIfMakeCheckOnCurrPlayer(const std::string& source, const std::string& dest);
	bool checkIfMakeCheckOnOtherPlayer(const std::string& source, const std::string& dest) const;
	void checkIfPlayerOfSameColorInSource(const std::string& source, const std::string& color) const;
	void checkIfPlayerOfSameColorInDest(const std::string& dest, const std::string& color) const;
	void checkIllegalIndexes(const std::string& dest) const;
	void checkIndexesSame(const std::string& source, const std::string& dest) const;
	void move(const std::string& source, const std::string& destination);
	void move(int src[], int dest[]);
	void translateStringToIndexes(const std::string& str, int indexes[]) const;
	ChessPiece*** getBoard() const;
	void printBoard() const;
	ChessPiece* getPiece(int firstIndex, int secondIndex) const;
private:
	ChessPiece*** _board; //a 2d array of pointer to chess pieces
	bool _turn; //true: white, false: black
};