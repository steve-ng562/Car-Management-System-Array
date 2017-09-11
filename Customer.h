#pragma once
using namespace std;
#include<string>
class Customer
{
public:
	Customer();
	Customer(string cID, string f, string l, char ccNumber[]);
	Customer(Customer& x);
	~Customer();
	string customerID;
	string fName;
	string lName;
	int vehicleID;
	friend istream &operator >>(istream &input, Customer &c);
	friend ostream &operator <<(ostream &output, Customer &c);
	char* getCreditCardNo();
	void setCreditCardNo(char ccNumber[]);

private:
	char creditCardNo[17];

};
