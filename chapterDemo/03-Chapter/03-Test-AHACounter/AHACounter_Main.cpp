#include "AHACounter.h"

using namespace std;

int main()
{
	HeartRate Customer1("Name");
	int n1,n2,n3;
	string s="";
	cout << "Welcome to AHACounter \nPleast enter your Name : ";
	cin >> s;
	Customer1.setName(s);
	cout << "\nEnter your Birthday (month/day/year) : ";
	cin >> n1 >> n2 >> n3;
	Customer1.setBirthday(n1, n2, n3);
	cout << "\nToday is (Only enter year) : ";
	cin >> n1;
	Customer1.setDate(n1);
	Customer1.print();
	
}
