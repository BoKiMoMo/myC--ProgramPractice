#include<iostream>

using namespace std;

void f(const int*);

int main()
{
	int y = 0;

	f(&y);
}

void f(const int* xPtr) //const int *xPtr = &y; const 是把y設為常數資料 不是把*xPtr設為常數指標
{
	*xPtr = 100;//Eorro
}