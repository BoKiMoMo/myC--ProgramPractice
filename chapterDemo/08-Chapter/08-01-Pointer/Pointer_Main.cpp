#include <iostream>

using namespace std;

int main()
{
	int a = 7;
	int* aPtr = &a;

	cout << "The address of a is " << &a;
	cout << "\nThe value of aPtr is " << aPtr;
	cout << "\n\nThe value of *&a is " << *&a;
	cout << "\n\nThe value of a is " << a;
	cout << "\nThe value of *aPtr is " << *aPtr << endl;

}