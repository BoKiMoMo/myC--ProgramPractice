#include<iostream>
#include<iomanip>
using namespace std;

int memory[100];
int accumulator;
bool work = true;
void order(const int);
void welcomeWord();

int main()
{
	size_t c = 0;
	welcomeWord();
			for (int items : memory)
		{

			if (work == 1)
			{
				cout << setfill('0') << setw(2) << c++ << " ? ";
				cin >> items;
				order(items);
			}
			else
			{
				cout << "\n*** Program loading completed ***" 
					<<"\n*** Program execution begins ***"
					<< endl;;
				break;
			}
		}
}

void order(const int od)
{
	int fr = od/100,ed = od%100;
	if (od == -99999)
		work = false;
	else
		switch (fr)
		{
		//input & output instrust
		case 10 :
			cout << "\nEnter a number to memory[" << ed << "] : ";
			cin >> memory[ed];
			cout << endl;
			break;

		case 11:
			cout << memory[ed] << endl;
			break;

		//read & load instrust
		case 20:
			accumulator = memory[ed];
			break;

		case 21:
			memory[ed] = accumulator;
			accumulator = NULL;
			break;

		//count instrust
		case 30:
			accumulator += memory[ed];
			break;

		case 31:
			accumulator -= memory[ed];
			break;

		case 32:
			accumulator /= memory[ed];
			break;

		case 33:
			accumulator *= memory[ed];
			break;

		//transfer & control instrust
		case 40:
			order(memory[ed]);
			break;

		case 41:
			if (accumulator < 0)
				order(memory[ed]);
			break;
	
		case 42:
			if (accumulator == 0)
				order(memory[ed]);
			break;

		case 43:
			break;
		}
}

void welcomeWord()
{
	cout << "*** Welcome to Simpletron! ***\n"
		<< "\n*** Please enter your program one instruction ***"
		<< "\n*** (or data word) at a time. I will type the ***"
		<< "\n*** loaction number and a question mark (?). ***"
		<<"\n*** You then type the word for that loaction. ***"
		<< "\n*** Type the sentinel -99999 to stop entering ***"
		<< "\n*** your program. ***" 
		<< endl;
}
