#include "ChessMoveProblem.h"


void ChessMoveProblem::initialization()
{
	cout << "Welcome to KnightMove" << endl;
	cout << "You can type a number to move Knight, each number have different direction :" << endl;
	howToMove();
	checkBoard[currentRow][currentColumn]++;
	cout << "\nYou Knight location is :" << endl;
	getKnightLocation();
	print(checkBoard);

}

void ChessMoveProblem::userInterface()
{
	int counter = 0;
	int MoveNumber = -5;
	cout << "\nNumber 0~7 to move"
		"\n-1 to quit"
		"\n-2 to check you Knight location"
		"\n-3 to print the Checkboard"
		"\n-4 to see the help "
		"\n-5 to reset"
		"\n8 to atuo move"
		"\n\nEnter the new movenumber : ";
	while (MoveNumber != -1)
	{
		cin >> MoveNumber;
		int step = 0;
		if (MoveNumber < -5 || MoveNumber>8)
			cerr << "\nYou are out of range, please enter a new number : ";
		else
		{

			switch (MoveNumber)
			{
			case 8:
				cout << "Enter the step count : ";

				cin >> step;
				for (size_t i = 0; i <= step; i++)
				{
					if (atuoMove() != -1)
					{
						move(atuoMove());
						counter++;
						if (counter == 63)
						{
							winTime++;
							endgame();
							counter = 0;
						}

					}
					else
					{
						endgame();
						cout << "Step : " << counter << endl;
						counter = 0;
					}
				}
				break;

			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
				move(MoveNumber);
				break;

			case -2:
				getKnightLocation();
				break;

			case -3:
				print(checkBoard);
				break;

			case -4:
				cout << "\nNumber 0~7 to move"
					"\n-1 to quit"
					"\n-2 to check you Knight location"
					"\n-3 to print the Checkboard"
					"\n-4 to see the help "
					"\n-5 to reset"
					"\n8 to atuo move" << endl;
				break;

			case -5:
				moveNumber = 0,
					currentRow = 3, currentColumn = 5;
				checkBoard = {};
				checkBoard[currentRow][currentColumn]++;
				break;

			}
		}
		cout << "\nEnter the new movenumber : ";
	}
}

void ChessMoveProblem::move(int m)
{
	if (checkMove(m) == 0)
		cerr << "\nYou had be there before, please enter a new movenumber : ";
	else
	{
		currentRow += vecrtical[m];
		currentColumn += horizontal[m];
		checkBoard[currentRow][currentColumn]++;
	}

}

int ChessMoveProblem::checkMove(int m)
{
	currentRow += vecrtical[m];
	currentColumn += horizontal[m];

	if (currentRow >= 0 && currentRow <= 7)
	{
		if (currentColumn >= 0 && currentColumn <= 7)
		{
			if (checkBoard[currentRow][currentColumn] == 1)
			{
				currentRow -= vecrtical[m];
				currentColumn -= horizontal[m];
				return 0;
			}
			else
			{
				currentRow -= vecrtical[m];
				currentColumn -= horizontal[m];
				return 1;
			}

		}
		else
		{
			currentRow -= vecrtical[m];
			currentColumn -= horizontal[m];
			return 0;
		}
	}
	else
	{
		currentRow -= vecrtical[m];
		currentColumn -= horizontal[m];
		return 0;
	}

}
void ChessMoveProblem::print(const array<array<int, columns>, rows>& a)
{
	cout << endl;
	cout << "\tcolnum[¡÷]" << endl;
	cout << "row[¡õ] ";
	for (auto& row : a)
	{
		for (auto& col : row)
			cout << col << " ";
		cout << endl;
		cout << "\t";
	}
}

void ChessMoveProblem::getKnightLocation()
{
	cout << endl;
	cout << "\tRow : " << currentRow + 1 << " Column :  " << currentColumn + 1 << endl;
}

void ChessMoveProblem::howToMove()
{
	array<array<char, 5>, 5> howToMove =
	{ '-','2','-','1','-'
	,'3','-','-','-','0'
	,'-','-','K','-','-'
	,'4','-','-','-','7',
	'-', '5','-','6','-' };

	cout << endl;
	cout << "\t";
	for (size_t i = 0; i < howToMove.size(); i++)
	{
		for (size_t j = 0; j < howToMove[i].size(); j++)
			cout << howToMove[i][j] << " ";
		cout << endl;
		cout << "\t";
	}
}

int ChessMoveProblem::atuoMove()
{
	int counter = 0;
	int Minimum = 9;
	int r = rand() % 8;
	array<int, 8> checkLocat_1 = {};
	array<int, 8> checkLocat_2 = {};

	for (size_t i = 0; i < 8; i++)
	{
		checkLocat_1[i] = checkMove(i);
		if (checkLocat_1[i] == 0)
			counter++;
	}

	for (size_t i = 0; i < 8; i++)
	{
		if (checkLocat_1[i] == 1)
			checkLocat_2[i] = hardDegree[currentRow + vecrtical[i]][currentColumn + horizontal[i]];
		else
			checkLocat_2[i] = 9;
	}

	for (size_t i = 0; i < 8; i++)
	{
		if (checkLocat_2[i] < Minimum)
			Minimum = checkLocat_2[i];
	}

	if (counter == 8)
		return -1;

	while (r != -1)
	{
		if (checkLocat_1[r] == 1)
			return r;
		else
			r = rand() % 8;
	}
}

void ChessMoveProblem::endgame()
{
	gameTime++;
	cout << "\n\n\tGameTime is : " << gameTime;
	cout << "\n\tWinTime is : " << winTime;
	getKnightLocation();
	print(checkBoard);
	moveNumber = 0,
		currentRow = 3, currentColumn = 5;
	checkBoard = {};
	checkBoard[currentRow][currentColumn]++;
}
