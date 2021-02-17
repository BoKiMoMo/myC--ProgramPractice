#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include"ClientData.h"

using namespace std;

int enterChoice();
void createTextFile(fstream&);
void updateRecord(fstream&);
void newRecord(fstream&);
void deleteRecord(fstream&);
void outputLine(ostream&, const ClientData&);
int getAccount(const char* const);

enum Choice{ PRINT = 1, UPDATE, NEW, DELETE, END };

int main()
{

}

int enterChoice()
{
	cout << "\nEnter your choice" << endl
		<< "1 - store a formatted text file of accounts" << endl
		<< "    called \"print.txt\" for printing" << endl
		<< "2 - update an account" << endl
		<< "3 - add a new account" << endl
		<< "4 - delete an account" << endl
		<< "5 - end program\n? ";

	int menuChoice;
	cin >> menuChoice;
	return menuChoice;
}

void createTextFile(fstream& readFromFile)
{
	ofstream outPrintFile("print.txt", ios::out);

	if(!outPrintFile)
	{
		cerr << "File could not be created." << endl;
		exit(EXIT_FAILURE);
	} // end if

	outPrintFile << left << setw(10) << "Account" << setw(21) << "Name"
		<< setw(11) << "Balance" << setw(11) << "Credits"
		<< setw(51) << "Address" << setw(11) << "Phone"
		<< setw(20) << "DiscountItem" << endl;

		readFromFile.seekg(0);

		ClientData client;
		readFromFile.read(reinterpret_cast<char*>(&client),
			sizeof(ClientData));

		while (!readFromFile.eof())
		{
			if (client.getAccount() != 0)
				outputLine(outPrintFile, client);

			readFromFile.read(reinterpret_cast<char*>(&client),
				sizeof(ClientData));
		} // end while
} // end function createTextFile

void updateRecord(fstream& updateFile)
{
	int accountNumber = getAccount("Enter account to update");

	updateFile.seekg((accountNumber - 1) * sizeof(ClientData));

	ClientData client;
	updateFile.read(reinterpret_cast<char*>(&client),
		sizeof(ClientData));

	if (client.getAccount() != 0)
	{
		outputLine(cout, client);

		cout << "\nEnter charge (+) or payment (-): ";
		double transaction;
		cin >> transaction;

		double oldBalance = client.getBalance();
		client.setBalance(oldBalance + transaction);
		outputLine(cout, client);

		updateFile.seekp((accountNumber - 1) * sizeof(ClientData));

		updateFile.write(reinterpret_cast<const char*>(&client),
			sizeof(ClientData));
	} // end if
	else
		cerr << "Account #" << accountNumber
		<< " has no information." << endl;
} // end function updateRecord

void newRecord(fstream& insertInFile)
{
	int accountNumber = getAccount("Enter new account number");

	insertInFile.seekg((accountNumber - 1) * sizeof(ClientData));

	ClientData client;
	insertInFile.read(reinterpret_cast<char*>(&client),
		sizeof(ClientData));

	if (client.getAccount() == 0)
	{
		string Name;
		double balance;

		cout << "Enter name, balance\n? ";
		cin >> Name;
		cin >> balance;

		client.setName(Name);
		client.setBalance(balance);
		client.setAccount(accountNumber);

		insertInFile.seekp((accountNumber - 1) * sizeof(ClientData));

		insertInFile.write(reinterpret_cast<const char*>(&client),
			sizeof(ClientData));
	} // end if
	else
		cerr << "Account #" << accountNumber
		<< " already contains information." << endl;
} // end function newRecord

void deleteRecord(fstream& deleteFromFile)
{
	int accountNumber = getAccount("Enter account to delete");

	deleteFromFile.seekg((accountNumber - 1) * sizeof(ClientData));

	ClientData client;
	deleteFromFile.read(reinterpret_cast<char*>(&client),
		sizeof(ClientData));

	if (client.getAccount() != 0)
	{
		ClientData blankClient;

		deleteFromFile.seekp((accountNumber - 1) *
			sizeof(ClientData));

		deleteFromFile.write(
			reinterpret_cast<const char*>(&blankClient),
			sizeof(ClientData));

		cout << "Account #" << accountNumber << " deleted.\n";
	} // end if
	else
		cerr << "Account #" << accountNumber << " is empty.\n";
} // end deleteRecord

void outputLine(ostream& output, const ClientData& record)
{

	output << left << setw(10) << record.getAccount()
		<< setw(21) << record.getName()
		<< setw(10) << setprecision(2) << right << fixed
		<< showpoint << record.getBalance() <<' '
		<< setw(10) << setprecision(2) << right << fixed
		<< showpoint << record.getCredits()<<' '
		<< setw(51)  << left  << record.getAddress()
		<< setw(11) << record.getPhone()
		<< setw(20) << record.getDiscountItem()
		<< endl;
} // end function outputLine

int getAccount(const char* const prompt)
{
	int accountNumber;

	do
	{
		cout << prompt << " (1 - 100): ";
		cin >> accountNumber;
	} while (accountNumber < 1 || accountNumber > 100);

	return accountNumber;
}
