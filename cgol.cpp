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
	initscr();			
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	border(0, 0, 0, 0, 0, 0, 0, 0); // Draw border around screen
	refresh();
}

void Cgol::drawBoard(const vector<string>& board)
{
	size_t window_h, window_w;
	getmaxyx(stdscr, window_h, window_w);
	size_t x_initial{(window_w / 2) - (ncols)};
	size_t y_initial{(window_h / 2) - (nrows / 2)};

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
	move(y_initial, x_initial + 1);
	refresh();
}

void Cgol::run(vector<string>& board) {
	int y, x, ch;
	while(true) {
		getyx(stdscr, y, x);
		switch(ch = getch()) {
			case KEY_DOWN:
				move(y + 1, x);
				break;
			case KEY_UP:
				move(y - 1, x);
				break;
			case KEY_RIGHT:
				move(y, x + 2);
				break;
			default:
				return;
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
