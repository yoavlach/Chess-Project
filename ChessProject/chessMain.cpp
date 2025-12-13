#include "Board.h"
int main()
{
	Board* board = new Board();
	board->move("a0", "a2");
	board->printBoard();
}