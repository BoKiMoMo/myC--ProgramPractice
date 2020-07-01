#include <iostream>
using namespace std;

int main()
{
	int x = 5, y;

	const int* const ptr = &x;

	cout << *ptr << endl;

	*ptr = 7; //Eorro
	ptr = &y; //Eorro
}