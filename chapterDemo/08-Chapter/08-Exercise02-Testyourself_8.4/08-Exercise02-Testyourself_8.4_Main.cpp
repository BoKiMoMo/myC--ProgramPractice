#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int var1, var2 = 10;
	
	//a
	int* iPtr = nullptr;

	//b
	iPtr = &var2;

	//c
	cout <<"(C)\niPtr : "<< *iPtr << endl;

	//d
	var1 = *iPtr * 2;

	//e
	cout << "\n(e)\nvar1 value : " << var1 << endl;

	//f
	cout << "\n(f)\nvar2 address : " << &var2 << endl;

	//g
	cout << "\n(g)\niPtr address : " << iPtr << endl;
}