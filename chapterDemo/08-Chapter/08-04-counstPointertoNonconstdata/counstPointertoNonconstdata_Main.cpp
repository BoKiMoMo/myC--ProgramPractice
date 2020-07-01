#include <iostream>

using namespace std;

int main()
{
	int x, y;

	int* const ptr = &x;
	//int const *x = &y ; => const &y
	//int *const x= &y ; => const x 宣告一個*x指標 並把x設為常數指標


	*ptr = 7; //常數指標為x 故*取直並不影響
	ptr = &y; //Eorro *x被指定為&y故 不可以轉移資料
}