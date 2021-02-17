#ifndef CLIENTDATA_H
#define CLIENTDATA_H
#include <string>
using std::string;

class ClientData
{
public :
	ClientData(int=0,const string ="",double=0.0);

	//Account Number
	void setAccount(int);
	int getAccount() const { return account; }

	//Phone Number
	void setPhone(int);
	int getPhone() const { return phone; }

	//Name
	void setName(const string&);
	string getName() const { return name; }

	//Address
	void setAddress(const string&);
	string getAddress() const { return address; }

	//DiscountItem
	void setDiscountItem(const string&);
	string getDiscountItem() const { return discountItem; }

	//Balance
	void setBalance(double);
	double getBalance() const { return balance; }

	//Credits
	void setCredits(double);
	double getCredits() const { return credits; }

private:
	int account,phone=0;
	char name[20], address[50] = {}, discountItem[20] = {};
	double balance, credits=0.0;
	};

#endif 