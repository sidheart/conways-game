#include <ncurses.h>
#include <iostream>
#include <vector>
#include <string>
#include "cgol.h"

using namespace std;

Cgol::Cgol(int nrows, int ncols) {
	string s;
	for(int i = 0; i < (2 * ncols) - 1; i++) {
		if(i % 2 == 0) {
			s += '*';
		} else {
			s += '|';
		}
	}
	for(int i = 0; i < nrows; i++) {
		board.push_back(s);
	}
}

void Cgol::update(vector<string> board)
{
}

void Cgol::init()
{
	initscr();			/* Start curses mode 		  */
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	printw("Hello World !!!");	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
}

void Cgol::simulate()
{
	init();
}
