#pragma once
#include "RentalVehicle.h"
#include "Customer.h"
class Company
{
public:
	int numberOfVeh;
	int numberOfCustomers;
	Company();
	~Company();
	void readVehicleFleet();
	void readRentedVehicle();
	void runCompany();
	void addVehicle(RentalVehicle rental[], int& numberOfVeh);
	void listInformation();
	void removeVehicle();
	void listAvailableVeh();
	void listAvailableVehSeats();
	void listAvailableVehBrand();
	void listRentedVeh();
	void listCustomerInfo();
	void listCustomerInfoVeh();
	void quitProgram();
	void rentVehicle();
	void returnVehicle();
private:
	RentalVehicle rental[20];
	Customer customer[20];
};

