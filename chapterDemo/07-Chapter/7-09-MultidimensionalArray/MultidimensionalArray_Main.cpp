#include <iostream>
#include <array>

using namespace std;

const size_t rows = 2;
const size_t columnos = 3;
void printArray(const array<array<int, columnos>, rows>&);

int main()
{
	array<array<int, columnos>, rows> array1 = { 1,2,3,4,5,6 };
	array<array<int, columnos>, rows> array2 = { 1,2,3,4,5 };

	cout << "Value is array1 by now are : " << endl;
	printArray(array1);

	cout << "Value is array2 by now are : " << endl;
	printArray(array2);
}

void printArray(const array<array<int, columnos>, rows> &a)
{
	for (auto const& row : a)
	{
		for (auto const& element : row)
			cout << element << ' ';

		cout << endl;
	}
	
	/*
	for(size_t row = 0 ; row < a.size() ; ++row )
	{
		for(size_t column = 0 ;  column < a[ row ].size() ; ++column)
			cout << a[ row ][ column ] << ' ';
		
		cout << endl;
	}
	*/
}
