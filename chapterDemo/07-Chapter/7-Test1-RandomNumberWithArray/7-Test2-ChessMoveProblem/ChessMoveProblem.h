#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;

static int gameTime = 0,winTime = 0;
const size_t rows=8
			,columns = 8;

class ChessMoveProblem
{
public:
	void initialization();
	void userInterface();
	void move(int);
	int checkMove(int);
	void print(const array<array<int,columns>,rows> &);
	void getKnightLocation();
	void howToMove();
	int atuoMove();
	void endgame();
private:
	bool end = 0;
	int moveNumber = 0,
		currentRow = 3, currentColumn = 4;
	array<array<int, columns>, rows> checkBoard = {};
	array<int, 8> horizontal = { 2,1,-1,-2,-2,-1,1,2 };
	array<int, 8> vecrtical = { -1,-2,-2,-1,1,2,2,1 };
	array<array<int, columns>, rows> hardDegree= 
	{2,3,4,4,4,4,3,2
	,3,4,6,6,6,6,4,3
	,4,6,8,8,8,8,6,4
	,4,6,8,8,8,8,6,4
	,4,6,8,8,8,8,6,4
	,4,6,8,8,8,8,6,4
	,3,4,6,6,6,6,4,3
	,2,3,4,4,4,4,3,2};


};

