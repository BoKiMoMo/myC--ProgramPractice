#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

int main()
{
	const size_t responseSize = 20 ;
	const size_t frequencySize = 6 ;

	const array<unsigned int, responseSize> responses
		= { 1,2,5,4,3,5,2,1,3,1,4,3,3,3,2,3,3,2,2,5 };

	array<unsigned int, frequencySize> frequency = {};

	for (size_t answer = 0; answer < responseSize; ++answer)
	{
		++frequency[responses[answer]];
	}

	cout << "Rating" << setw(17) << "Frequency" << endl;

	for (unsigned int rating = 1;rating < frequencySize ;rating++)
	{
		cout << setw(6) << rating << setw(17) << frequency[rating] << endl;
	}
}