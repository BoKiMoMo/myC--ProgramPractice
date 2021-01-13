#include<iostream>

using namespace std;

int main()
{
	char var1, var2 = 'a';

	//a
	char* charPtr = NULL;

	//b
	charPtr = &var2;

	//c
	cout << "charPtr : " << *charPtr << endl;

	//d
	var1 = *charPtr;

	//e
	cout << "\nvar1 : " << var1 << endl;

	//f
	cout << "\nvar2 : " << &var2 << endl;

	//g
	cout << "\ncharPtr address : " << charPtr << endl;
	cout << "\nvar1 address : " << &var1 << endl;

}