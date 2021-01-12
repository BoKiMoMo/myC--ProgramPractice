#include<iostream>
#include<random>
#include <ctime>
#include <iomanip>
#include <cmath>
#include<string>

using namespace std;

default_random_engine engine(static_cast<unsigned int>(time(0)));
uniform_int_distribution<unsigned int>randomInt(1, 10);

int Tortoise = 1, Hare = 1;

void moveTortoise(int);
void moveHare(int);
void printRaceWay();

int main()
{
	cout << "BANG ! ! ! ! !" << "\nAND THEY'RE OFF ! ! ! ! !" << endl;
	while (Tortoise < 70 && Hare <70)
	{
		moveTortoise(randomInt(engine));
		moveHare(randomInt(engine));
		cerr << "\nTortoise : " << Tortoise << "\nHare : " << Hare << endl;
		printRaceWay();
		if (Tortoise == Hare && Hare==70)
		{
			cout << "It's a tie !!! " << endl;
			Tortoise = 1, Hare = 1;
		}
		else
		{
			if (Hare == 70)
				cout << "HARE WINS !!! YAY !!!" << endl;
			if (Tortoise == 70)
				cout << "TORTOISE WINS !!! YAY !!!" << endl;
		}
	}

	}

void moveTortoise(int n)
{
	if (1 <= n && n <= 5)
		Tortoise += 3;
	if (6 <= n && n <= 7)
		Tortoise -= 6;
	if (8 <= n && n <= 10)
		Tortoise += 1;
	if (Tortoise >= 70)
		Tortoise = 70;
	if (Tortoise <= 1)
		Tortoise = 1;
}

void moveHare(int n)
{
	if (3 <= n && n <= 4)
		Hare += 9;
	if (5 == n)
		Hare -= 12;
	if (6 <= n && n <= 8)
		Hare += 1;
	if (9 <= n && n <= 10)
		Hare -= 2;
	if (Hare >= 70)
		Hare = 70;
	if (Hare <= 1)
		Hare = 1;
}

void printRaceWay()
{
	cout << "StartLine | ";
	for (size_t i = 1; i <= 70; i++)
	{
		if (Tortoise == Hare && Tortoise ==i)
			cout << "OUCH!!!" << ' ';
		else
		{
			if (i == Tortoise)
				cout << 'T' << ' ';
			else
			{
				if (i == Hare)
					cout << 'H' << ' ';
				else
					cout << '-' << ' ';
			}
		}
	}
	cout << endl;
}
