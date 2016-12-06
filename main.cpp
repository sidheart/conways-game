#include <iostream>
#include "cgol.h"

using namespace std;

int main(int argc, char* argv[]) {
	Cgol game(10, 10);
	game.simulate();
	return 0;
}
