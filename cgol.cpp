#include <ncurses.h>
#include <iostream>
#include <vector>
#include <string>
#include "cgol.h"

using namespace std;

Cgol::Cgol(size_t nrows, size_t ncols) 
	: nrows{nrows}, ncols{ncols}
{
	string s;
	for(size_t i = 0; i < ncols; i++) {
		s += ' ';
	}
	for(size_t i = 0; i < nrows; i++) {
		board.push_back(s);
	}
}

void Cgol::update(vector<string>& board)
{
}

void Cgol::init()
{
	/* Initialize the screen and set NCurses options */
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	border(0, 0, 0, 0, 0, 0, 0, 0); /* Draw border around screen */

	/* Calculate the coordinate pair for the top left corner of the game board */
	size_t window_h, window_w;
	getmaxyx(stdscr, window_h, window_w);
	x_initial = (window_w / 2) - (ncols);
	y_initial = (window_h / 2) - (nrows / 2);

	move(y_initial, x_initial + 1);
	refresh();
}

void Cgol::drawBoard(const vector<string>& board)
{
	/* Calculate the coordinate pair for the top left corner of the game board
	   This needs to be redone each time we draw the board, as the screen size
	   might have changed */
	size_t window_h, window_w;
	getmaxyx(stdscr, window_h, window_w);
	x_initial = (window_w / 2) - (ncols);
	y_initial = (window_h / 2) - (nrows / 2);

	/* Record original x and y position before drawing board */
	unsigned int y_orig, x_orig;
	getyx(stdscr, y_orig, x_orig);

	/* Draw top border of game board */
	move(y_initial - 1, x_initial);
	addch(ACS_ULCORNER);
	for(size_t j = 0; j < ncols * 2 - 1; j++) {
			addch(ACS_HLINE);
	}
	addch(ACS_URCORNER);

	/* Draw interior contents of game board */
	for(size_t i = 0; i < nrows; i++) {
		move(y_initial + i, x_initial);
		addch(ACS_VLINE);
		for(size_t j = 0; j < ncols; j++) {
				if(board[i][j] == ' ')
					addch(ACS_BULLET);
				else
					addch(ACS_DIAMOND);
				addch(ACS_VLINE);
		}
	}

	/* Draw bottom border of game board */
	move(y_initial + nrows, x_initial);
	addch(ACS_LLCORNER);
	for(size_t j = 0; j < ncols * 2 - 1; j++) {
			addch(ACS_HLINE);
	}
	addch(ACS_LRCORNER);
	move(y_orig, x_orig);
	refresh();
}

void Cgol::run(vector<string>& board) {
	unsigned int y, x, ch;
	while(true) {
		drawBoard(board);
		getyx(stdscr, y, x);
		switch(ch = getch()) {
			case KEY_DOWN:
				if(y < y_initial + nrows - 1)
					move(y + 1, x);
				break;
			case KEY_UP:
				if(y > y_initial)
					move(y - 1, x);
				break;
			case KEY_RIGHT:
				if(x < x_initial + 2 * ncols - 1)
					move(y, x + 2);
				break;
			case KEY_LEFT:
				if(x > x_initial + 1)
					move(y, x - 2);
				break;
			case KEY_ENTER:
			case KEY_ENTER_ALT:
				if(board[y - y_initial][(x / 2) - (x_initial / 2) - 1] == ' ')
					board[y - y_initial][(x / 2) - (x_initial / 2) - 1] = '*';
				else
					board[y - y_initial][(x / 2) - (x_initial / 2) - 1] = ' ';
				break;
			case 'q':
				return;
			default:
				break;
		}
	}
}

void Cgol::simulate()
{
	init();
	drawBoard(getBoard());
	run(board);
	endwin();	
}
