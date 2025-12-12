#pragma once
#include "ChessPiece.h"
#define ROWS_AND_COLS 8
#define START_STRING "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0"
#define BLACK_ROW 7
#define WHITE_ROW 0
#define BLACK_PAWN_ROW 6
#define WHITE_PAWN_ROW 1
enum PIECES_INDEXES { LEFT_ROOK, LEFT_KNIGHT, LEFT_BISHOP, KING, QUEEN, RIGHT_BISHOP, RIGHT_KNIGHT, RIGHT_ROOK };

class Board
{
public:
	Board();
	~Board();
	void initPlayerSide(const std::string& color);
	bool checkIfMakeCheck(const std::string& source, const std::string& dest);
	bool CheckIfCauseCheck(const std::string& source, const std::string& dest);
	bool checkIfPlayerOfSameColorInSource(const std::string& source, const std::string& color);
	bool checkIfPlayerOfSameColorInDest(const std::string& dest, const std::string& color);
	bool checkIllegalIndexes(const std::string& dest);
	bool checkIndexesSame(const std::string& source, const std::string& dest);
	void translateStringToIndexes(const std::string& str, int indexes[]);

private:
	ChessPiece _board[ROWS_AND_COLS][ROWS_AND_COLS];
	bool turn; //true: white, false: black
};