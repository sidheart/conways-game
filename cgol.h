#include <vector>
#include <string>
#include <ncurses.h>

#define KEY_ENTER_ALT 10

class Cgol 
{
	public:
		Cgol(size_t nrows, size_t ncols);
		void init();
		void update(std::vector<std::string>& board);
		void drawBoard(const std::vector<std::string>& board);
		void run(std::vector<std::string>& board);
		void simulate();
		std::vector<std::string> getBoard() { return board; }
	private:
		WINDOW* win;
		std::vector<std::string> board;	
		size_t nrows, ncols, x_initial, y_initial;
};
