//#include <iostream>
//#include <string>
//#include "Board.h"
//
//using namespace std;
//
//void tryMove(Board& board, string source, string dest);
//void play(Board& board);
//
//int main()
//{
//	Board board;
//	cout << "Original board:\n";
//	board.printBoard();
//	//while (true)
//	//{
//	//	play(board);
//	//}
//	cout << "\n";
//
//	/* White pawn tries to stay in place – exception expected */
//	tryMove(board, "e2", "e2");
//	board.printBoard();
//	cout << "\n";
//
//	/* White pawn tries to move three squares forward – exception expected */
//	tryMove(board, "e2", "e5");
//	board.printBoard();
//	cout << "\n";
//
//	/* White pawn tries to move diagonally without capture – exception expected */
//	tryMove(board, "e2", "d3");
//	board.printBoard();
//	cout << "\n";
//
//	/* Rook tries to jump over pawn – exception expected */
//	tryMove(board, "a1", "a3");
//	board.printBoard();
//	cout << "\n";
//
//	/* Rook tries diagonal move – exception expected */
//	tryMove(board, "a1", "b2");
//	board.printBoard();
//	cout << "\n";
//
//	/* Knight tries illegal straight move – exception expected */
//	tryMove(board, "b1", "b3");
//	board.printBoard();
//	cout << "\n";
//
//	/* Knight tries illegal horizontal move – exception expected */
//	tryMove(board, "b1", "c1");
//	board.printBoard();
//	cout << "\n";
//
//	/* Bishop tries non-diagonal move – exception expected */
//	tryMove(board, "c1", "c3");
//	board.printBoard();
//	cout << "\n";
//
//	/* Bishop tries diagonal but blocked by pawn – exception expected */
//	tryMove(board, "f1", "b5");
//	board.printBoard();
//	cout << "\n";
//
//	/* King tries to move two squares – exception expected */
//	tryMove(board, "e1", "e3");
//	board.printBoard();
//	cout << "\n";
//
//	/* King tries to move onto own piece – exception expected */
//	tryMove(board, "e1", "f1");
//	board.printBoard();
//	cout << "\n";
//
//	/* Legal white pawn move – no exception expected */
//	tryMove(board, "e2", "e4");
//	board.printBoard();
//	cout << "\n";
//
//	/* Legal black pawn move – no exception expected */
//	tryMove(board, "e7", "e6");
//	board.printBoard();
//	cout << "\n";
//
//	/* White pawn tries illegal capture (empty diagonal) – exception expected */
//	tryMove(board, "a2", "b3");
//	cout << "\n";
//
//	/* Legal knight move – no exception expected */
//	tryMove(board, "g1", "f3");
//	board.printBoard();
//	cout << "\n";
//
//	/* Legal bishop move – no exception expected */
//	tryMove(board, "c1", "f4");
//	board.printBoard();
//	cout << "\n";
//
//	/* Legal rook move – no exception expected */
//	tryMove(board, "h1", "h3");
//	board.printBoard();
//	cout << "\n";
//
//	/* Legal king move – no exception expected */
//	tryMove(board, "e1", "e2");
//	board.printBoard();
//	cout << "\n";
//
//	/* Knight moves causing check – no exception expected */
//	tryMove(board, "b8", "c6");
//	tryMove(board, "f3", "g5"); // filler white move
//	tryMove(board, "c6", "d4");
//	board.printBoard();
//	cout << "\n";
//
//	/* White tries to move a pawn – no exception expected */
//	tryMove(board, "b2", "b3");
//	board.printBoard();
//	cout << "\n";
//
//	/* Attempt to move from empty square – exception expected */
//	tryMove(board, "d4", "d5");
//	board.printBoard();
//	cout << "\n";
//
//	/* Queen illegal move – moving like a knight – exception expected */
//	tryMove(board, "d1", "e3");
//	board.printBoard();
//	cout << "\n";
//
//	/* Queen illegal move – blocked by pawn – exception expected */
//	tryMove(board, "d1", "d5");
//	board.printBoard();
//	cout << "\n";
//
//	/* Queen legal move – diagonally after pawn moved – no exception expected */
//	tryMove(board, "d1", "h5");
//	board.printBoard();
//	cout << "\n";
//
//	/* Queen legal move – straight after pawn moved – no exception expected */
//	tryMove(board, "d1", "d3");
//	board.printBoard();
//	cout << "\n";
//
//	return 0;
//}
//
///*Attempts to move a piece and handles any exceptions
//input: the board, the source coordinates and the destination coordinates
//output: none*/
//void tryMove(Board& board, string source, string dest)
//{
//	cout << "Move " << source << " to " << dest << "\n";
//	std::cout << board.move(source, dest) << "\n";
//}
//
///*Gets move input from the user in the form "a2a4"
//and performs the move
//input: the board
//output: none*/
//void play(Board& board)
//{
//	string input;
//	cin >> input;
//	string source = "";
//	string dest = "";
//
//	source += input[0];
//	source += input[1];
//	dest += input[2];
//	dest += input[3];
//
//	tryMove(board, source, dest);
//	board.printBoard();
//}