#include <iostream>

using namespace std;

int main()
{
	int x, y;

	int* const ptr = &x;
	//int const *x = &y ; => const &y
	//int *const x= &y ; => const x �ŧi�@��*x���� �ç�x�]���`�ƫ���


	*ptr = 7; //�`�ƫ��Ь�x �G*�����ä��v�T
	ptr = &y; //Eorro *x�Q���w��&y�G ���i�H�ಾ���
}