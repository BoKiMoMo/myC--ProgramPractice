#include<iostream>
#include<iomanip>
using namespace std;

//8.17 a~e完成 f~i未完成

float memory[1000] = {0x0000};
float accumulator = 0x0000; //累加器
int instructionCounter = 0, //紀錄正執行的記憶體位址
operationCode = 0x0000, //指令左邊兩位數
operand = 0x0000, //指令右邊兩位數
instructionRegister = 0x0000; //下一步指令
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
			if (instructionRegister <= 0xFFFF && instructionRegister >= -0xFFFF)
				memory[instructionCounter++] = instructionRegister;
			else
				cerr << "*** Attempt to divide by zero ***\n"
				<< "*** Simpletron execution abnormally terminated ***"
				<< endl;
	}
	cout << "\n*** Program loading completoperand ***"
		<< "\n*** Program execution begins ***"
		<< endl;

	for (float items : memory)
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
	operationCode = instructionRegister / 0x64;
	operand = instructionRegister % 0x64;
	switch (operationCode)
	{
		//input & output instrust
	case 0xA:
		cout << "(?)";
		cin >> memory[operand];
		cout << endl;
		break;

	case 0xB:
		cout << memory[operand] << endl;
		cout << endl;
		break;

		//read & load instrust
	case 0x14:
		accumulator = memory[operand];
		break;

	case 0x15:
		memory[operand] = accumulator;
		accumulator = NULL;
		break;

		//calculate instrust
	case 0x1E:
		accumulator += memory[operand];
		break;

	case 0x1F:
		accumulator -= memory[operand];
		break;

	case 0x20:
		accumulator /= memory[operand];
		break;

	case 0x21:
		accumulator *= memory[operand];
		break;

	case 0x22:
		int a = static_cast<int>(accumulator);
		accumulator = a%static_cast<int>(memory[operand]);
		break;

	case 0x23:
		if (memory[operand] == 0)
			accumulator = 1;
		for (size_t i = 1; i < memory[operand]; i++)
			accumulator *= accumulator;
		break;

		//transfer & control instrust
	case 0x28:
		instructionCounter = operand;
		break;

	case 0x29:
		if (accumulator < 0)
			instructionCounter = operand;
		break;

	case 0x2A:
		if (accumulator == 0)
			instructionCounter = operand;
		break;

	case 0x2B:
		cout << "\nREGISTERS : " << internal << showpos << setfill(' ')
			<< left << setw(22) << "\naccumulator" << right << setw(6) << accumulator
			<< left << setw(22) << "\ninstructionCounter" << right << setw(6) << instructionCounter
			<< left << setw(22) << "\ninstructionRegister" << right << setw(6) << instructionRegister
			<< left << setw(22) << "\noperationCode" << right << setw(6) << operationCode
			<< left << setw(22) << "\noperand" << right << setw(6) << operand << endl;

		cout << "\nMEMORY :\n" << setw(2) << " ";
		for (size_t i = 0; i < 10; i++)
			cout << ' ' << setw(5) << i;
		cout << endl;
		for (size_t x = 0; x < 10; x++)
		{
			cout << left << setw(2) << x;
			for (size_t y = 0; y < 10; y++)
				if (memory[10 * x + y] == -99999)
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
