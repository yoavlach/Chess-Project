#include "Board.h"
int main()
{
	Board* board = new Board();
	board->move("a1", "a2");
	board->printBoard();
}