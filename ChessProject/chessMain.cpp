#include <iostream>
#include <string>
#include "Board.h"

using namespace std;

/*Attempts to move a piece and handles any exceptions
input: the board, the source coordinates and the destination coordinates
output: none*/
void tryMove(Board& board, string source, string dest)
{
	cout << "Move " << source << " to " << dest << "\n";
	try
	{
		board.move(source, dest);
	}
	catch (const string& e)
	{
		cout << e << endl;
	}
}

int main()
{
	Board board;
	std::cout << "Original board:\n";
	board.printBoard();
	std::cout << "\n";

	// white rook moves forward
	// valid move no exception expected
	tryMove(board, "a1", "a5");
	board.printBoard();
	std::cout << "\n";

	// black tries to move on white turn
	// should throw exception piece in source doesn't belong to current player
	tryMove(board, "h1", "h3");
	std::cout << "\n";

	// black rook moves forward
	// valid move no exception expected
	tryMove(board, "h8", "h5");
	board.printBoard();
	std::cout << "\n";

	// white rook tries to move diagonal
	// should throw exception piece can't move that way
	tryMove(board, "a5", "b6");
	std::cout << "\n";

	// white king moves forward
	// valid move no exception expected
	tryMove(board, "e1", "e2");
	board.printBoard();
	std::cout << "\n";

	// black rook checks white king
	// valid move no exception expected
	tryMove(board, "h5", "e5");
	board.printBoard();
	std::cout << "\n";

	// white tries to ignore check
	// should throw exception this move makes a check on the current player
	tryMove(board, "a5", "a6");
	std::cout << "\n";

	// white rook captures the checking rook
	// valid move no exception expected (FIXED: using rook at a5 instead of king)
	tryMove(board, "a5", "e5");
	board.printBoard();

	return 0;
}