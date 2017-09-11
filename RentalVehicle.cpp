#include "RentalVehicle.h"



RentalVehicle::RentalVehicle()
{
	ID = 0;
	price = 0.0;
	status = Available;

}

RentalVehicle::RentalVehicle(int id, int y, string b, string m, int s, double p) {
	ID = id;
	Vehicle.setYear(y);
	Vehicle.setBrand(b);
	Vehicle.setModel(m);
	Vehicle.setSeats(s);
	price = p;
	status = Available;

}

RentalVehicle::RentalVehicle(RentalVehicle& x) {
	ID = x.ID;
	Vehicle.setYear(x.Vehicle.getYear());
	Vehicle.setBrand(x.Vehicle.getBrand());
	Vehicle.setModel(x.Vehicle.getModel());
	Vehicle.setSeats(x.Vehicle.getSeats());
	price = x.price;
	status = Available;
}



RentalVehicle::~RentalVehicle()
{
}

int RentalVehicle::getID() {
	return ID;
}
void RentalVehicle::setID(int x) {
	ID = x;
}
double RentalVehicle::getPrice() {
	return price;
}
void RentalVehicle::setPrice(double x) {
	price = x;
}
RentalVehicle RentalVehicle::getInfo() {
	int y, s, id;
	string b, m;
	double p;
	string stat;
	cout << "Please enter ID and hit enter. \n";
	cin >> id;
	cout << "Please enter year and hit enter. \n";
	cin >> y;
	cout << "Please enter brand and hit enter. \n";
	cin >> b;
	cout << "Please enter model and hit enter. \n";
	cin >> m;
	cout << "Please enter number of seats and hit enter. \n";
	cin >> s;
	cout << "Please enter price and hit enter. \n";
	cin >> p;
	RentalVehicle x = RentalVehicle(id, y, b, m, s, p);
	return x;

}
void RentalVehicle::display() {
	cout << ID;
	cout << "     [" << Vehicle.getYear() << " " << Vehicle.getBrand() << " " << Vehicle.getModel() << "]\t";

	cout << "(" << Vehicle.getSeats() << " seats)      $";
	cout << price << " ";
	if (status == Available) {
		cout << "Available";
	}
	else {
		cout << "Rented";
	}
	cout << endl;
}
void RentalVehicle::setStatus(string x) {
	if (x == "Available") {
		status = Available;
	}
	else {
		status = Rented;
	}
}
RentalVehicle::VehicleStatus RentalVehicle::getStatus() {
	return status;
}