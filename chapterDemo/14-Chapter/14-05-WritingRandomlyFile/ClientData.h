#include<string>

class ClientData
{
public:
	ClientData(int = 0, const std::string & = "", const std::string & = "", double = 0.0);

	//Account Number
	void setAccountNumber(int);
	int getAccountNumber() const;

	//Last Name
	void setLastName(const std::string&);
	std::string getLastName() const;

	//First Name
	void setFirstName(const std::string&);
	std::string getFirstName() const;

	//Balance
	void setBalance(double);
	double getBalance() const;

private:
	int accountNumber;
	char lastName[15];
	char firstName[10];
	double balance;
};//end class
