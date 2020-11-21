#include <iostream>
#include<string>
#include<vector>

using namespace std;
char recursiveMinimum(const string&, int, int);
bool testPalindrom(const string&, int, int);

int main()
{
	int a, b;
	string w;
	cout << "Enter the string to compare the value : ";
	getline(cin, w);
	cout << "\nEnter Strating index and End index : ";
	cin >> a >> b;
	cout << "\nThe minimun is : " << recursiveMinimum(w,a,b) ;

	return 0;
}

char recursiveMinimum(const string& w, int st, int ed)
{
	st -= 1; ed -= 1;
	int stop = ed;
	char min = w[st];
	for ( int i = st; i <= stop; i++,ed--)
		if (testPalindrom(w, i, ed))
		{
			if (min > w[i])
				min = w[i];
		}
		else
			return min;
	return min;
}

bool testPalindrom(const string& w, int a, int b)
{
	if (w[a] == w[b])
		return false;
	return true;
}
