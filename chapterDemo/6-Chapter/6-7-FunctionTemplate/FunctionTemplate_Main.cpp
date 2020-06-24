#include <iostream>
#include "FunctionTemplate.h"

using namespace std;

int main()
{
	//	integer------------------------

	int int1, int2, int3;

	cout << "Input three integer value is :";
	cin >> int1 >> int2 >> int3;

	cout << "The maximum integer value is : "
		<< maximum(int1, int2, int3) << endl;

	//	double--------------------------

	double double1, double2, double3;

	cout << "Input three double value is : ";
	cin >> double1 >> double2 >> double3;

	cout << "The maximum double value is : "
		<< maximum(double1, double2, double3) << endl;

	//	char----------------------------

	char char1, char2, char3;

	cout << "Input three char value : ";
	cin >> char1 >> char2 >> char3;

	cout << "The maximum char is : "
		<< maximum(char1, char2, char3)<<endl;


}