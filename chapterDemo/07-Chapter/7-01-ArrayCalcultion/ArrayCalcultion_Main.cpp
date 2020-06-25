#include <iostream>

using namespace std;

int main()
{
	int c[12] = { -45,6,0,72,1543,-89,0,62,-3,1,6453,78 };
	
	for (int i = 0; i <= 11; i++)
	{
		cout << "The couter is : " << i + 1 << " \tThe value is : " << c[i] << endl;
	}

	cout << "\n ==== C [ a + b ] ===== \n" << endl;

	cout << "C [ a + b ] += : " << c[5 + 6] + 2<<endl;
	c[5 + 6] += 2;
	cout << "C [ a + b ] += : " << c[5 + 6] + 2<<endl;

	cout << "\n ==== c [ a ] + c [ b ] + c [ c ] ===== \n" << endl;

	cout << "c [ a ] + c [ b ] + c [ c ] = : " << c[0] + c[1] + c[2] << endl;
	cout << "C [ 6 ] / 2 : " << c[ 6 ] / 2 << endl;

}