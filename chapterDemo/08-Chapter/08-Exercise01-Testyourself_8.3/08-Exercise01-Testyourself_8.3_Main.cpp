#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
	const size_t size = 10;
	//a
	double number[size] = { 0.0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9 };
	//b
	double* nPtr = NULL;
	cout << fixed << showpoint << setprecision(1);

	//v
	cout << "\n(c)\n number[i] : " << endl;
	for (size_t i = 0; i < size; i++)
		cout << number[i] << ' ';
	cout << endl;

	//d
	nPtr = number;
	//nPtr = &number[0];

	//e
	cout << "\n(e)\n nPtr + i : " << endl;
	for (size_t i = 0; i < size; i++)
		cout << *(nPtr + i) << ' ';
	cout << endl;

	//f
	cout << "\n(f)\n number + i : " << endl;
	for (size_t i = 0; i < size; i++)
		cout << *(number + i) << ' ';
	cout << endl;

	//g
	cout << "\n(g)\n nPtr + i : " << endl;
	for (size_t i = 0; i < size; i++)
		cout << nPtr[i] << ' ';
	cout << endl;

	//h
	cout << "\n(h)_1 number[4] : " << number[4] << endl;
	cout << "(h)_2 *(number + 4) : " << *(number + 4) << endl;
	cout << "(h)_3 nPtr[4] : " << nPtr[4] << endl;
	cout << "(h)_4 *(nPtr + 4) : " << *(nPtr + 4) << endl;

	//i
	cout << "\n(i)\naddress of nPtr : " << nPtr << "\naddress of nPtr+8 : " << nPtr + 8 << endl;

	//j
	nPtr = number + 5;
	cout << "\n(j)\n*nPtr address : " << nPtr << "\nvalue : " << *nPtr << endl;
	nPtr -= 4;
	cout << "nPtr -=4 address : " << nPtr << "\nvalue : " << *nPtr << endl;
}