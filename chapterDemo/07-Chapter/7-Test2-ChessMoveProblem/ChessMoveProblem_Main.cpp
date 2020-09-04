#include "ChessMoveProblem.h"

int main()
{
	srand(time(NULL));
	ChessMoveProblem Knight01;

	Knight01.initialization();
	Knight01.userInterface();
}