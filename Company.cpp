#include "Company.h"
#include "RentalVehicle.h"
#include <fstream>
#include <iostream>
using namespace std;
Company::Company(void)
{
	numberOfVeh = 0;
	numberOfCustomers = 0;

}


Company::~Company(void)
{
}
void Company::readVehicleFleet() {
	ifstream inStream;
	inStream.open("VehicleFleet.txt");
	int i = 0;
	int id, year, seats;
	
	string brand, model, status;
	double price;
	while (i <= 19) {
		inStream >> id >> year >> brand;

		inStream >> model >> seats >> price;

		inStream >> status;
	
		
		rental[i].setID(id);
		rental[i].Vehicle.setYear(year);
		rental[i].Vehicle.setBrand(brand);
		rental[i].Vehicle.setModel(model);
		rental[i].Vehicle.setSeats(seats);
		rental[i].setStatus(status);
		rental[i].setPrice(price);
		id = 0;
		
		
		i++;
		if (inStream.eof())
			break;
	}
	numberOfVeh = i;
	inStream.close();
}
void Company::readRentedVehicle() {
	ifstream inStream;
	inStream.open("RentedVehicle.txt");
	int i = 0;
	char ccNum[17];
	while (i <= 19) {

		inStream >> customer[i].customerID >> customer[i].fName
			>> customer[i].lName >> customer[i].vehicleID >> ccNum;
		customer[i].setCreditCardNo(ccNum);
		strcpy_s(ccNum, "");
		i++;
		numberOfCustomers = i;
		if (inStream.eof())
			break;
	}
	inStream.close();
}
void Company::runCompany() {
	readVehicleFleet();
	readRentedVehicle();
	int choice;
	do {
		cout << "Choose 1 to list all the vehicles. \n";
		cout << "Choose 2 to add new vehicles into fleet. \n";
		cout << "Choose 3 to remove a vehicle from the fleet. \n";
		cout << "Choose 4 to list all available vehicles.\n";
		cout << "Choose 5 to list all available vehicles which have a specific number of seats.\n";
		cout << "Choose 6 to list all available vehicles from a specific brand. \n";
		cout << "Choose 7 to list all rented vehicles. \n";
		cout << "Choose 8 to list customer information. \n";
		cout << "Choose 9 to list customer information of a specific rented vehicle. \n";
		cout << "Choose 10 to rent a vehicle. \n";
		cout << "Choose 11 to return a vehicle. \n";
		cout << "Choose 12 to quit the program. \n";
		cin >> choice;
		switch (choice) {
		case 1:
			listInformation();
			break;
		case 2:
			addVehicle(rental,numberOfVeh);
			break;
		case 3:
			removeVehicle();
			break;

		case 4:
			listAvailableVeh();
			break;
		case 5:
			listAvailableVehSeats();
			break;

		case 6:
			listAvailableVehBrand();
			break;
		case 7:
			listRentedVeh();
			break;

		case 8:
			listCustomerInfo();
			break;
		case 9:
			listCustomerInfoVeh();
			break;

		case 10:
			rentVehicle();
			break;
		case 11:
			returnVehicle();
			break;
		case 12:
			quitProgram();
			break;
			default:
			cout << "That was an invalid choice, please try again! \n";
		}


	} while (choice != 12);
}


	void Company::listInformation() {
		int y = 0;
		while (y < 20) {
			if (rental[y].getID() != 0) {
				cout << "ID: " << rental[y].getID() << " Year: " << rental[y].Vehicle.getYear() << " Brand: " << rental[y].Vehicle.getBrand();
				cout << " Model: " << rental[y].Vehicle.getModel() << " Seats: " << rental[y].Vehicle.getSeats() << " Price: " << rental[y].getPrice();
				if (rental[y].getStatus() == RentalVehicle::VehicleStatus::Available) {
					cout << " Status: Available \n";
				}
				else {
					cout << " Status: Rented \n";
				}
			}

			y++;
		}
	}
	void Company::addVehicle(RentalVehicle rental[], int& numberOfVeh) {
		if (numberOfVeh != 20) {
			int year, seats;
			string brand, model;
			double price;
			cout << "Enter Year followed by enter: ";
			cin >> year;
			cout << "Enter Brand followed by enter: ";
			cin >> brand;
			cout << "Enter Model followed by enter: ";
			cin >> model;
			cout << "Enter Number of Seats followed by enter: ";
			cin >> seats;
			cout << "Enter Price followed by enter: ";
			cin >> price;
			rental[numberOfVeh].setID(numberOfVeh + 1);
			rental[numberOfVeh].Vehicle.setYear(year);
			rental[numberOfVeh].Vehicle.setBrand(brand);
			rental[numberOfVeh].Vehicle.setModel(model);
			rental[numberOfVeh].Vehicle.setSeats(seats);
			rental[numberOfVeh].setPrice(price);
			numberOfVeh++;
		}
	}

	void Company::removeVehicle() {
		int vehID;
		int errorCheck = 0;
		
			listAvailableVeh();
			cout << "Enter the Vehicle ID for which vehicle you'd like to remove followed by enter: ";
			cin >> vehID;
			for (int i = 0; i < numberOfVeh; i++) {
				if (vehID == rental[i].getID() && rental[i].getStatus() == RentalVehicle::VehicleStatus::Available) {
					errorCheck = 0;
					rental[i] = rental[numberOfVeh-1];
					rental[numberOfVeh - 1] = RentalVehicle();
					numberOfVeh -= 1;
				}
			}
			
			
		
		cout << "Sorry that Vehicle ID is not valid! \n";
	}
	void Company::listAvailableVeh() {
		int y = 0;
		while (y < 20) {
			if (rental[y].status == RentalVehicle::VehicleStatus::Available && rental[y].getID() != 0) {
				cout << "ID: " << rental[y].getID() << " Year: " << rental[y].Vehicle.getYear() << " Brand: " << rental[y].Vehicle.getBrand();
				cout << " Model: " << rental[y].Vehicle.getModel() << " Seats: " << rental[y].Vehicle.getSeats() << " Price: " << rental[y].getPrice();
				if (rental[y].status == RentalVehicle::VehicleStatus::Available) {
					cout << " Status: Available \n";
				}
			}
			y++;
		}
	}
	void Company::listAvailableVehSeats() {
		int seat;
		cout << "How many seats would you like to have in your vehicle?";
		cin >> seat;
		int y = 0;
		while (y < 20) {
			if (rental[y].status == RentalVehicle::VehicleStatus::Available && rental[y].Vehicle.getSeats() == seat) {
				cout << "ID: " << rental[y].getID() << " Year: " << rental[y].Vehicle.getYear() << " Brand: " << rental[y].Vehicle.getBrand();
				cout << " Model: " << rental[y].Vehicle.getModel() << " Seats: " << rental[y].Vehicle.getSeats() << " Price: " << rental[y].getPrice();
				if (rental[y].status == RentalVehicle::VehicleStatus::Available) {
					cout << " Status: Available \n";
				}
			}
			y++;
		}
	}
	void Company::listAvailableVehBrand() {
		string brand;
		cout << "What brand of vehicle would you like to have?";
		cin >> brand;
		int y = 0;
		while (y < numberOfVeh) {
			if (rental[y].status == RentalVehicle::VehicleStatus::Available && rental[y].Vehicle.getBrand() == brand) {
				cout << "ID: " << rental[y].getID() << " Year: " << rental[y].Vehicle.getYear() << " Brand: " << rental[y].Vehicle.getBrand();
				cout << " Model: " << rental[y].Vehicle.getModel() << " Seats: " << rental[y].Vehicle.getSeats() << " Price: " << rental[y].getPrice();
				if (rental[y].status == RentalVehicle::VehicleStatus::Available) {
					cout << " Status: Available \n";
				}
			}
			y++;
		}
	}
	void Company::listRentedVeh() {
		int y = 0;
		while (y < 20) {
			if (rental[y].status == RentalVehicle::VehicleStatus::Rented) {
				cout << "ID: " << rental[y].getID() << " Year: " << rental[y].Vehicle.getYear() << " Brand: " << rental[y].Vehicle.getBrand();
				cout << " Model: " << rental[y].Vehicle.getModel() << " Seats: " << rental[y].Vehicle.getSeats() << " Price: " << rental[y].getPrice();
				if (rental[y].status == RentalVehicle::VehicleStatus::Rented) {
					cout << " Status: Rented \n";
				}
			}
			y++;
		}
	}
	void Company::listCustomerInfo() {
		string last;
		cout << "Enter last name: ";
		cin >> last;
		for (int i = 0; i < numberOfCustomers; i++) {
			if (last == customer[i].lName)
				cout << customer[i];
		}
	}
	void Company::listCustomerInfoVeh() {
		int vehID;
		cout << "Enter vehicle ID: ";
		cin >> vehID;
		for (int i = 0; i < 20; i++) {
			if (vehID == customer[i].vehicleID)
				cout << customer[i];
		}
	}
	void Company::quitProgram() {
		ofstream outStream;
		ofstream oStream;
		int y = 0;
		outStream.open("VehicleFleet.txt");
		oStream.open("RentedVehicle.txt");
		if (outStream.fail()) {
			cout << "Output file opening failed. \n";
			exit(1);
		}
		if (oStream.fail()) {
			cout << "Output file opening failed. \n";
			exit(1);
		}
		while (y < 20) {
			if (rental[y].getID() != 0) {
				outStream << rental[y].getID() << " " << rental[y].Vehicle.getYear() << " " << rental[y].Vehicle.getBrand();
				outStream << " " << rental[y].Vehicle.getModel() << " " << rental[y].Vehicle.getSeats() << " " << rental[y].getPrice();
				if (rental[y].status == RentalVehicle::VehicleStatus::Available) {
					outStream << "    Available \n";
				}
				else {
					outStream << "    Rented \n";
				}
			}
			y++;
		}

		y = 0;
		while (y < 20) {
			if (customer[y].customerID != "000") {
				oStream << customer[y].customerID << " " << customer[y].fName << " " << customer[y].lName << " " << customer[y].vehicleID
					<< " " << customer[y].getCreditCardNo() << endl;
				}
			y++;
		}
	}
	void Company::rentVehicle() {
		listAvailableVeh();
		int rent = 0;
		int errorCheck = 0;
	
		while (errorCheck == 0) {
			cout << "Please type in an ID for the car you wish to rent followed by the return key. \n";
			cin >> rent;
			for (int i = 0; i < 20; i++) {
				if (rental[i].getID() == rent) {
					rental[i].setStatus("Rented");
					errorCheck = 1;
				}
			}
			if (errorCheck == 0)
				cout << "Sorry. That ID is invalid! Please try again. \n";
		}
		cout << "What is your First Name, Last Name, followed by Credit Card Number? \n";
		cin >> customer[numberOfCustomers];
		customer[numberOfCustomers].vehicleID = rent;
		customer[numberOfCustomers].customerID = "00" + std::to_string(rent);
		numberOfCustomers++;
	}
	void Company::returnVehicle() {
		listRentedVeh();
		int returnVeh = 0;
		int errorCheck = 0;
		int varMem;
		while (errorCheck == 0) {
			cout << "Please type in an ID for the car you wish to return followed by the return key. \n";
			cin >> returnVeh;
			for (int i = 0; i < 20; i++) {
				if (rental[i].getID() == returnVeh) {
					rental[i].setStatus("Available");
					errorCheck = 1;
					varMem = i;
				}
			}
			if (errorCheck == 0)
				cout << "Sorry. That ID is invalid! Please try again. \n";
		}

		customer[varMem] = customer[numberOfCustomers - 1];
		customer[numberOfCustomers - 1] = Customer();
		numberOfCustomers--;
	}