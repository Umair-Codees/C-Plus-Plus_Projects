#ifndef BIKE_H
#define BIKE_H
#pragma once
#include <iostream>
#include <fstream>
//Include Base Class
#include "vehicle.h"
using namespace std;
//Derived Class
class bike : public vehicle
{
	double height;
	bool selfStart;
	bool discBrake;
	static int numberOfBikes;
public:
	//Default Constructor
	bike();
	//Parameterized Constructor
	bike(const char* company, const char* clr, int wheels, int pwrCC, const char* vehicleType, double h, bool start, bool brake);
	//Get Total Number of Bike
	static int getTotalBikes();
	//Copy Constructor
	bike(const bike& obj);
	//Assignment Operator
	bike& operator=(const bike& obj);
	//Setter
	void setHeight(double h);
	void setSelfStart(bool start);
	void setDiscBrake(bool brake);
	//Getter
	double getHeight()const;
	bool getSelfStart()const;
	bool getDiscBrake()const;
	//Check Type Of Wheel
	void checkType();//Override Function
	//Display Fucntion
	void display()const;
	//Destructor
	~bike();
};
////Ostream / cout Operator Overloading
//ostream& operator << (ostream& output, const bike& obj);
////Istream / cin Operator Overloading
//istream& operator >> (istream& inPut, bike& obj);
////Ofstream / fout Operator Overloading
//ofstream& operator << (ofstream& outFile, const bike& obj);

#endif BIKE_H