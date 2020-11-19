#include <iostream>
#include<string>

using namespace std;

bool testPalindrom(string);

int main()
{
	string w;
	cout << "Enter the word to check is palindrom or not : ";
	getline(cin,w);
	cout << endl;

	if(testPalindrom(w)!=0)
		cout << "The word is palidrome !!" << endl;
	else
		cout << "The word isn't palidrome !!" << endl;
}

bool testPalindrom(string w)
{
	for (size_t i = 0; i < w.size(); i++ )
	{
		size_t m = w.size() - (i+1);
		if (w[i] != w[m])
		{
			cout << "The char : " << w[i] << " The char : " << w[m] << endl;
			return 0;
		}
	}
	return 1;
}