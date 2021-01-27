#include "Exercise01_10_7.h"

using namespace std;

int main()
{
	DoubleSubscriptedArray a(3, 5);
	DoubleSubscriptedArray b;

	cout << "\nRow of DoubleArray a is " << a.getRow()
		<< "\nColumn of DoubleArray a is " << a.getColumn();

	cout << "\nRow of DoubleArray b is " << b.getRow()
		<< "\nColumn of DoubleArray b is " << b.getColumn();

	cout << "\nEnter " << a.getRow() * a.getColumn() + b.getRow() * b.getColumn() << " integers:" << endl;
	cin >> a >> b ;

	cout << "\nAfter input, the Arrays contain:\n"  << "a:\n" << a;
	cout << "\na(2,4) : " << a(1, 3) << endl;

	if (a != b)
		cout << "\na and b are not equal" << endl;

	DoubleSubscriptedArray c (a);
	cout << "\nAfter input, the Arrays contain:\n" << "a:\n" << a
	 << "b:\n" << b
	 << "c:\n" << c;

	b = a;
	cout << "\n\nAfter copy, the Arrays contain:\n" << "a:\n" << a;
	cout << "\nAfter copy, the Arrays contain:\n" << "b:\n" << b;

	if (a == b)
		cout << "\na and b are equal" << endl;

	a(0, 0) = 99;
	cout << "\nSet a(1,1) = 99 :\n" << a << endl;
}