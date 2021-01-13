#include<iostream>
#include<iomanip>
using namespace std;

int memory[100];
int accumulator = 0, //累加器
instructionCounter = 0, //紀錄正執行的記憶體位址
operationCode = 0, //指令左邊兩位數
operand = 0, //指令右邊兩位數
instructionRegister = 0; //下一步指令
void order();
void welcomeWord();

int main()
{
	welcomeWord();
		while (instructionRegister != -99999)
		{
			cout << setw(2) << instructionCounter << " ? ";
			cin >> memory[instructionCounter];
			instructionRegister = memory[instructionCounter];
			if (instructionRegister == -99999)
				break;
			else
				if (instructionRegister <= 9999 && instructionRegister >= -9999)
					memory[instructionCounter++] = instructionRegister;
				else
					cerr << "*** Attempt to divide by zero ***\n"
						<< "*** Simpletron execution abnormally terminated ***"
						<< endl;
		}
		cout << "\n*** Program loading completoperand ***"
			<< "\n*** Program execution begins ***"
			<< endl;

		for (int items : memory)
		{
			instructionRegister = items;
			if (operationCode != 43)
				order();
			else
				break;
		}
}

void order()
{
	operationCode = instructionRegister / 100;
	operand = instructionRegister % 100;
	switch (operationCode)
	{
		//input & output instrust
	case 10:
		cout << "(?)";
		cin >> memory[operand];
		cout << endl;
		break;

	case 11:
		cout << memory[operand] << endl;
		cout << endl;
		break;

		//read & load instrust
	case 20:
		accumulator = memory[operand];
		break;

	case 21:
		memory[operand] = accumulator;
		accumulator = NULL;
		break;

		//count instrust
	case 30:
		accumulator += memory[operand];
		break;

	case 31:
		accumulator -= memory[operand];
		break;

	case 32:
		accumulator /= memory[operand];
		break;

	case 33:
		accumulator *= memory[operand];
		break;

		//transfer & control instrust
	case 40:
		instructionCounter = operand;
		break;

	case 41:
		if (accumulator < 0)
			instructionCounter = operand;
		break;

	case 42:
		if (accumulator == 0)
			instructionCounter = operand;
		break;

	case 43:
		cout << "\nREGISTERS : " << internal << showpos << setfill(' ')
			<< left << setw(22) << "\naccumulator" << right << setw(6) << accumulator
			<< left << setw(22) << "\ninstructionCounter" << right << setw(6) << instructionCounter
			<< left << setw(22) << "\ninstructionRegister" << right << setw(6) << instructionRegister
			<< left << setw(22) << "\noperationCode" << right << setw(6) << operationCode
			<< left << setw(22) << "\noperand" << right << setw(6) << operand << endl;

		cout << "\nMEMORY :\n"<<setw(2)<<" ";
		for (size_t i = 0; i < 10; i++)
			cout << ' ' << setw(5) << i;
		cout << endl;
		for (size_t x = 0; x <10; x++)
		{
			cout << left << setw(2) << x;
			for (size_t y = 0; y < 10; y++)
				if(memory[10 * x + y]==-99999)
					cout << ' ' << setfill('0') << setw(5) << "  End";
				else
					cout << ' ' << setfill('0') << setw(5) << memory[10 * x + y];
			cout << endl;
		}
		break;
	}
}

void welcomeWord()
{
	cout << "*** Welcome to Simpletron! ***\n"
		<< "\n*** Please enter your program one instruction ***"
		<< "\n*** (or data word) at a time. I will type the ***"
		<< "\n*** loaction number and a question mark (?). ***"
		<< "\n*** You then type the word for that loaction. ***"
		<< "\n*** Type the sentinel -99999 to stop entering ***"
		<< "\n*** your program. ***"
		<< endl;
}
