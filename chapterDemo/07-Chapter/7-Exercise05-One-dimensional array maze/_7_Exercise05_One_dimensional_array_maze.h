#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;

static int playerColumn=0, playerRow=0, direct = 5,stepCounter = 0;;

class maze
{
public:
	void printMapChar(const array<array < char, 12>, 12>&);
	void setPlayerlocation(int, int);
	void initiinitialization();
	int check(int);
	void move(int);
	char getLocation(int);
private:
	char player = 'O';
	array<array<char, 12>, 12>	mazeChar
		= {
		'#','#','#','#','#','#','#','#','#','#','#','#',
		'#','.','.','.','#','.','.','.','.','.','.','#',
		'.','.','#','.','#','.','#','#','#','#','.','#',
		'#','#','#','.','#','.','.','.','.','#','.','#',
		'#','.','.','.','.','#','#','#','.','#','.','.',
		'#','#','#','#','.','#','.','#','.','#','.','#',
		'#','.','.','#','.','#','.','#','.','#','.','#',
		'#','#','.','#','.','#','.','#','.','#','.','#',
		'#','.','.','.','.','.','.','.','.','#','.','#',
		'#','#','#','#','#','#','.','#','#','#','.','#',
		'#','.','.','.','.','.','.','#','.','.','.','#',
		'#','#','#','#','#','#','#','#','#','#','#','#'
	};
};

