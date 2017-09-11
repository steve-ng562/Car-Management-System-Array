#pragma once

#include <string>

#include<iostream>

using namespace std;

class Automobile

{

public:

	Automobile();

	Automobile(int y, string b, string m, int seats);

	~Automobile(void);



	void display();
	void getInfo();
	void setYear(int x);
	void setBrand(string x);
	void setModel(string x);
	void setSeats(int x);
	int getYear();
	string getBrand();
	string getModel();
	int getSeats();
private:

	int year;

	string brand;

	string model;

	int numberOfSeats;

};