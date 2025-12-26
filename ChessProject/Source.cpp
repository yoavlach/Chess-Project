/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include "Board.h"
#include <iostream>
#include <thread>
#include <stdlib.h>
#include <string.h>
#include <thread>
#include <chrono>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

int main()
{
	srand(time_t(NULL));
	Board* b = new Board();
	Pipe p;
	bool isConnect = p.connect();
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return 0;
		}
	}
	char msgToGraphics[1024];
	#ifdef _WIN32
	strcpy_s(msgToGraphics, "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0"); // just example...
	p.sendMessageToGraphics(msgToGraphics);   // send the board string
	#endif
	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();
	while (msgFromGraphics != "quit")
	{
		int msg = b->move({msgFromGraphics[0], msgFromGraphics[1]}, { msgFromGraphics[2], msgFromGraphics[3] });
		char chMsg = msg + '0';
		char strMsg[BOARD_INDEX_ARR_SIZE] = { chMsg, 0 };
		p.sendMessageToGraphics(strMsg);
		msgFromGraphics = p.getMessageFromGraphics();
	}
	p.close();
	return 0;
}