#ifndef CAR_H
#define CAR_H
#pragma once
#include <fstream>
#include <iostream>
//Include Base Class
#include "vehicle.h"
//Deep Copy Function
char* deepCopy(const char* arr);
//Derived Class
class car : public vehicle
{
	int noOfDoors;
	char* trasmission;
	int noOfSeats;
	static int numberOfCars;
public:
	//Default Constructor
	car();
	//Parameterized Constructor
	car(const char* company, const char* clr, int wheels, int pwrCC, const char* vehicleType, int door, const char* trans, int seat);
	//Get Total Number of Bike
	static int getTotalCars();
	//Copy Constructor
	car(const car& obj);
	//Assignment Operator Overloading
	car& operator=(const car& obj);
	//Setter
	void setNoOfDoors(int door);
	void setTransmission(char* trans);
	void setNoOfSeats(int seat);
	//Getter
	int getNoOfDoors()const;
	char* getTransmission()const;
	int getNoOfSeats()const;
	//Check Type Of Wheel
	void checkType();//Override
	//Display Function
	void display()const;
	//Destructor
	~car();
};
////Ostream / cout Operator Overloading
//std::ostream& operator << (std::ostream& output, const car& obj);
////Istream / cin Operator Overloading
//istream& operator >> (istream& in, car& obj);
////Ofstream / fout Operator Overloading
//std::ofstream& operator << (std::ofstream& outFile, const car& obj);

#endif CAR_H