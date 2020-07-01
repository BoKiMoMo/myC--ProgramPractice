#include<iostream>

using namespace std;

int cubeByValue(int);
void cubeByReference(int*);
int main()
{
	int number = 5;

	cout << "The original value of number is " << number;
	cout << "\nTHe value of function is " << cubeByValue(number);
	cout << "\nTHe new value of number is " << number << endl;

	cout << "----------Reference----------" << endl;

	cout << "The original value of number is " << number;
	cubeByReference(&number);
	cout << "\nTHe new value of number is " << number << endl;
}

int cubeByValue(int n)
{
	return n * n * n;
}

void cubeByReference(int* nPtr)
{
	*nPtr = *nPtr * *nPtr * *nPtr;
}
