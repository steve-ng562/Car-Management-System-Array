#include "Customer.h"
Customer::Customer()
{
	customerID = "000";
	fName = "None";
	lName = "None";
	vehicleID = 0;
	char ccNumber[17] = "0";
	strcpy_s(creditCardNo, ccNumber);
}
Customer::Customer(string cID, string f, string l, char ccNumber[]) {
	customerID = cID;
	fName = f;
	lName = l;
	strcpy_s(creditCardNo, ccNumber);
}
Customer::Customer(Customer& x) {
	customerID = x.customerID;
	fName = x.fName;
	lName = x.lName;
	strcpy_s(creditCardNo, x.getCreditCardNo());
}
istream &operator >>(istream &input, Customer &c) {
	input >> c.fName >> c.lName >> c.creditCardNo;
	return input;
}
ostream &operator <<(ostream &output, Customer &c) {
	output << "Customer ID: " << c.customerID << " First Name: " << c.fName;
	output << " Last Name: " << c.lName << " " << c.creditCardNo << endl;
	return output;
}
Customer::~Customer()
{
}
char* Customer::getCreditCardNo()
{
	return creditCardNo;
}

void Customer::setCreditCardNo(char ccNumber[]) {
	strcpy_s(creditCardNo, ccNumber);
}