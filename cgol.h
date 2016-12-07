#include <vector>
#include <string>
#include <ncurses.h>

#define KEY_ENTER_ALT 10
#define KEY_SPACE 32

class Cgol 
{
	public:
		Cgol(size_t nrows, size_t ncols);
		void simulate();
		std::vector<std::string> getBoard() { return board; }
	private:
		void init();
		void update(std::vector<std::string>& board);
		bool isAlive(const std::vector<std::string>& board, size_t row, size_t col);
		int countNeighbors(const std::vector<std::string>& board, size_t row, size_t col);
		void drawBoard(const std::vector<std::string>& board);
		void run(std::vector<std::string>& board);
		WINDOW* win;
		std::vector<std::string> board;	
		size_t nrows, ncols, x_initial, y_initial;
};
