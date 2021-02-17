#include "ClientData.h"

ClientData::ClientData(int accountValue, const string nameValue,double balanceValue)
	:account(accountValue),balance(balanceValue)
{
	setName(nameValue);
}

void ClientData::setAccount(int A)
{
	account = A;
}

void ClientData::setPhone(int P)
{
	phone = P;
}

void ClientData::setName(const string& N)
{
	int length = N.size();
	length = (length < 20 ? length : 19);
	N.copy(name, length);
	name[length] = '\0';
}

void ClientData::setAddress(const string& A)
{
	int length = A.size();
	length = (length < 50 ? length : 49);
	A.copy(name, length);
	address[length] = '\0';
}

void ClientData::setDiscountItem(const string& DI)
{
	int length = DI.size();
	length = (length < 20 ? length : 19);
	DI.copy(name, length);
	discountItem[length] = '\0';
}

void ClientData::setBalance(double B)
{
	balance = B;
}

void ClientData::setCredits(double C)
{
	credits = C;
}
