#include <iostream>
#include<string>
#include<vector>

using namespace std;
void print(const string&);
void stringReserve(const string &,int);

int main()
{
	int a = 0, b = 0;
	string w;
	cout << "Enter the string : ";
	getline(cin, w);
	cout << "\nEnter Strating index : ";
	cin >> a ;
	stringReserve(w, a);
	cout << endl;
}

void stringReserve(const string& w, int st)
{
	for (size_t i = w.size()-1; i >=st-1 ; i--)
		cout << w[i];
	return;
}
