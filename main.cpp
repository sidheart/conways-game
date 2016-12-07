#include <iostream>
#include "cgol.h"

using namespace std;

int main(int argc, char* argv[]) {
	Cgol game(30, 30);
	game.simulate();
	return 0;
}
