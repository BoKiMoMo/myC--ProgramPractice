#include<iostream>

using namespace std;

void f(const int*);

int main()
{
	int y = 0;

	f(&y);
}

void f(const int* xPtr) //const int *xPtr = &y; const �O��y�]���`�Ƹ�� ���O��*xPtr�]���`�ƫ���
{
	*xPtr = 100;//Eorro
}