#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//a
	const size_t SIZE = 5;
	unsigned int values[SIZE] = { 2,4,6,8,10 };

	//b
	unsigned int* vPtr=nullptr;

	//c
	cout << "(c)" << endl;
	for (size_t i = 0; i < SIZE; i++)
		cout << values[i] << ' ';
	cout << endl;

	//d
	vPtr = values;
	//vPtr = &values[0];

	//e
	cout << "\n(e)" << endl;
	for (size_t i = 0; i < SIZE; i++)
		cout << *(vPtr+i) << ' ';
	cout << endl;

	//f
	cout << "\n(f)" << endl;
	for (size_t i = 0; i < SIZE; i++)
		cout << *(values + i) << ' ';
	cout << endl;

	//g
	cout << "\n(g)" << endl;
	for (size_t i = 0; i < SIZE; i++)
		cout << vPtr[i] << ' ';
	cout << endl;

	//h
	cout << "\n(h)_1 : " << *(values + 5) << endl;
	cout << "(h)_2 : " << vPtr[5] << endl;
	cout << "(h)_3 : " << *(vPtr + 5) << endl;

	//i
	cout << "\n(i) vPtr+3 address : " << values + 3 << endl;
	cout << "vPtr+3 value : " << *(values + 3) << endl;

	//j
	vPtr = &values[4];
	vPtr -= 4;
	cout << "\n(j) vPtr-=4 address : " << vPtr << endl;
	cout << "vPtr-=4 value : " << *vPtr << endl;
}