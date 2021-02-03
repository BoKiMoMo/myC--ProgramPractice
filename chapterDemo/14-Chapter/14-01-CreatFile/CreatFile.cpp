#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<iomanip>

using namespace std;

int main()
{
	ofstream outClientFile("clients.txt", ios::out);

	if(!outClientFile)
	{
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}//end if

	cout 	<< "Enter the account, name, and balance." << endl
		<< "Enter end-of-file to end input.\n ? ";

	int account;
	string name;
	double balance;

	while (cin >> account >> name >> balance)
	{
		outClientFile << fixed << setprecision(2) << account << ' ' << name << ' ' << balance << endl;
		cout << " ? ";
	}//end while
}//end main