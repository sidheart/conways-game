#include <iostream>
#include <ncurses.h>
#include "cgol.h"

using namespace std;

int main(int argc, char* argv[]) {
	Cgol game(10, 10);
	initscr();			/* Start curses mode 		  */
	printw("Hello World !!!");	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
	//game.simulate();
	return 0;
}
