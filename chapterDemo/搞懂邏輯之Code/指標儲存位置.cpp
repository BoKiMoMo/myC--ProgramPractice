#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a[5];
	int *Ptr;
	Ptr = a;
	cout<<"Ptr = "<<Ptr<<"\t a = "<<a<<"\t&a = "<<&a<<"\t&a[0] = "<<&a[0];
}
