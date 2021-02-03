#include "ClientData.h"
using namespace std;
//using  std::string;

ClientData::ClientData(int accountNumberValue, const string& lastName, const string& firstName, double balanceValue)
	:accountNumber(accountNumberValue),balance(balanceValue)
{
	setLastName(lastName);
	setFirstName(firstName);
}

void ClientData::setAccountNumber(int accountNumberValue)
{
	accountNumber = accountNumberValue;
}

int ClientData::getAccountNumber() const
{
	return accountNumber;
}

void ClientData::setLastName(const string& lastNameString)
{
	int lenght = lastNameString.size();
	lenght = (lenght < 15 ? lenght : 14);
	lastNameString.copy(lastName, lenght);
	lastName[lenght] = '\0';
}

string ClientData::getLastName() const
{
	return lastName;
}

void ClientData::setFirstName(const string& firstNameString)
{
	int lenght = firstNameString.size();
	lenght = (lenght < 10 ? lenght : 9);
	firstNameString.copy(firstName, lenght);
	firstName[lenght] = '\0';
}

std::string ClientData::getFirstName() const
{
	return firstName;
}

void ClientData::setBalance(double balanceValue)
{
	balance = balanceValue;
}

double ClientData::getBalance() const
{
	return balance;
}
