#include <vector>
#include <string>

class Cgol 
{
	public:
		Cgol(int nrows, int ncols);
		void simulate();
		void update(std::vector<std::string> board);
		void print(std::vector<std::string> board);
		std::vector<std::string> getBoard() { return board; }
	private:
		std::vector<std::string> board;	
};
