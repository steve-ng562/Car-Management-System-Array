#pragma once
#include "Automobile.h"
class RentalVehicle
{
public:
	enum VehicleStatus { Available, Rented };
	RentalVehicle();
	RentalVehicle(int id, int y, string b, string m, int s, double p);
	RentalVehicle(RentalVehicle& x);
	RentalVehicle getInfo();
	void display();

	~RentalVehicle();
	Automobile Vehicle;
	VehicleStatus status;
	int getID();
	void setID(int x);
	double getPrice();
	RentalVehicle::VehicleStatus getStatus();
	void setPrice(double x);
	void setStatus(string x);
private:
	int ID;
	double price;

};

