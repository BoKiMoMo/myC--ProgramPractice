#include "_7_Exercise05_One_dimensional_array_maze.h"

void maze::printMapChar(const array<array<char, 12>,12>&maze)
{
	for (auto const& playerRow : maze)
	{
		for (auto const& element : playerRow)
			cout << element << " ";
		cout << endl;
	}
	cout << endl;
}

void maze::setPlayerlocation(int c, int r)
{
	mazeChar[c][r] = player;
}

void maze::initiinitialization()
{
	cout << "Enter the straing location : \nColumn and Row : " << endl;
	cin >> playerRow >> playerColumn;
	while (mazeChar[playerRow][ playerColumn] == '#')
	{
			cerr << "Please enter an effective number : " << endl;
			cin >> playerRow >> playerColumn;
	}
	setPlayerlocation(playerRow, playerColumn);


	cerr << "\nStraing !!" << endl;
	printMapChar(mazeChar);
	while (check(direct) != -1)
	{
		move(direct);
		stepCounter++;
		cout << stepCounter << endl;
		printMapChar(mazeChar);
	};
}

void maze::move(int d)
{
	switch (d % 4)
	{
	case 0:
			mazeChar[playerRow][playerColumn] = 'x';
			mazeChar[playerRow--][playerColumn];
			setPlayerlocation(playerRow, playerColumn);
			break;
		
	case 1:
			mazeChar[playerRow][playerColumn] = 'x';
			mazeChar[playerRow][playerColumn++];
			setPlayerlocation(playerRow, playerColumn);
			break;

	case 2:
			mazeChar[playerRow][playerColumn] = 'x';
			mazeChar[playerRow++][playerColumn];
			setPlayerlocation(playerRow, playerColumn);
			break;

	case 3:
			mazeChar[playerRow][playerColumn] = 'x';
			mazeChar[playerRow][playerColumn--];
			setPlayerlocation(playerRow, playerColumn);
			break;
	}
}

char maze::getLocation(int n)
{
	switch (n%4)
	{
	case 0:
		return mazeChar[playerRow-1][playerColumn];
		break;

	case 1:
		return mazeChar[playerRow][playerColumn+1];
		break;

	case 2:
		return mazeChar[playerRow+1][playerColumn];
		break;

	case 3:
		return mazeChar[playerRow][playerColumn-1];
		break;
	}
}

int maze::check(int d)
{
	int checkForward = 0;
	if (playerColumn == 11 && playerRow == 4)
	{
		cerr << "You find exit in "<<stepCounter <<" step !!!"<< endl;
		return -1;
	}

	if (getLocation(direct) == '#' && getLocation(direct+1) == '#')
	{
		if (getLocation(direct - 1) == '#')
			direct+=2;
		else
			direct--;
			}

	if (getLocation(direct) != '#' && getLocation(direct+1) != '#')
		direct++;

	if (getLocation(direct) == '#' && getLocation(direct + 1) != '#')
		direct++;

	if (getLocation(direct) != '#' && getLocation(direct + 1) == '#')
		direct;
}
