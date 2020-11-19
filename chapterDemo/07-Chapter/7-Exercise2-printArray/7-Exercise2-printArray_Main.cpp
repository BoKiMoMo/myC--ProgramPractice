#include <iostream>
#include<string>
#include<vector>

using namespace std;

void inPutVector(vector<string>&,string&);
void outPutVector(vector<string>&);
void testPalindrom(const vector<string>&,int,int);

int main()
{
	int a=0, b = 0;
	string w;
	cout << "Enter the word to check is palindrom or not : ";
	getline(cin,w);
	vector <string> array1(w.size());
	inPutVector(array1,w);
	cout << "\nEnter Strating index and End index : ";
	cin >> a>>b;
	testPalindrom(array1, a, b);
	cout << endl;
}

void inPutVector(vector<string> &items,string &w)
{
	for (size_t i = 0; i < items.size(); i++)
		items[i] = w[i];
}

void outPutVector(vector<string>& items)
{
	for (string& item : items)
		cout << item;

	cout << endl;
}

void testPalindrom(const vector<string>&w,int i, int m)
{
	cout << "Strating search index between " << i << " and " << m << endl;
	i -= 1;
	m -= 1;
	int stop = m;
	if (i != 0)
		for (size_t p = 0; p < i; p++)
			cout << w[i];
	for (i; i < stop; i++,m--)
	{
		cout << w[i];
		if (w[i] != w[m])
		{
			cout << "\nThe char : " << w[i] << " The char : " << w[m] << endl;
			return ;
		}
	}
	cout << "\nFinish!!" << endl;
}