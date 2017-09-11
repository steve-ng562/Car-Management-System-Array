#include "Automobile.h"



Automobile::Automobile(void)
{

	year = 1900;

	brand = "N/A";

	model = "N/A";

	numberOfSeats = 0;

}

Automobile::Automobile(int y, string b, string m, int seats) {

	year = y;

	brand = b;

	model = m;

	numberOfSeats = seats;

}
Automobile::~Automobile(void)
{
}

void Automobile::getInfo() {
	int y, s;
	string b, m;

	cout << "Please enter year and hit enter. \n";
	cin >> y;
	cout << "Please enter brand and hit enter. \n";
	cin >> b;
	cout << "Please enter model and hit enter. \n";
	cin >> m;
	cout << "Please enter number of seats and hit enter. \n";
	cin >> s;

}

void Automobile::display()
{

	cout << "[" << year << " " << brand << " " << model << "]\t";

	cout << "(" << numberOfSeats << " seats)\n";

}
void Automobile::setYear(int x) {
	year = x;
}
void Automobile::setBrand(string x) {
	brand = x;
}
void Automobile::setModel(string x) {
	model = x;
}
void Automobile::setSeats(int x) {
	numberOfSeats = x;
}


int Automobile::getYear() {
	return year;
}
string Automobile::getBrand() {
	return brand;
}
string Automobile::getModel() {
	return model;
}
int Automobile::getSeats() {
	return numberOfSeats;

}