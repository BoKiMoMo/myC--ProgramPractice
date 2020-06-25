#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

int main() 
{
	const size_t arraySize = 11;
	array<unsigned int, arraySize > n =
	{ 0,0,0,0,0,0,1,2,4,2,1 };

	cout << "Frade distribution : " << endl;

	for (size_t  i = 0; i < n.size(); i++)
	{


		if (i == 10)
			cout << setw(12) << "100 : ";
		else
			cout << setw(3) << i * 10 << " - " << setw(3) << (i * 10) + 9<<" : ";
	
		for (unsigned int stars = 0; stars < n[i]; ++stars)
		{
			cout << "*";
		}

		cout << endl;

	
	}
}