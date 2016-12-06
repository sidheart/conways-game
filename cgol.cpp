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

void Cgol::print(vector<string> board)
{
	for(string s : board) {
		cout << s << endl;
	}
}

void Cgol::simulate()
{
	print(getBoard());
}
