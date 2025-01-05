#ifndef TRUCK_H
#define TRUCK_H
#pragma once
#include "vehicle.h"
class truck : public vehicle
{
	double containerSize;
	char* category;
	bool fourWheelDrive;
	static int numberOfTrucks;
public:
	//Default Constructor
	truck();
	//Parameterized Constructor
	truck(const char* company, const char* clr, int wheels, int pwrCC, const char* vehicleType, double Size, const char* cate, bool fourWheelD);
	//Get Total Number of Bike
	static int getTotalTrucks();
	//Copy Constructor
	truck(const truck& obj);
	//Assignment Operator Overloading
	truck& operator=(const truck& obj);
	//Setter
	void setContainerSize(int size);
	void setCategory(char* cate);
	void setFourWheelDrive(bool wheel);
	//Getter
	double getContainerSize()const;
	char* getCategory()const;
	bool getFourWheelDrive()const;
	//Check Type Of Wheel
	void checkType();//Override
	//Display Function
	void display()const;
	//Destructor
	~truck();
};
////Ostream / cout Operator Overloading
//ostream& operator << (ostream& output, const truck& obj);
////Ostream / cout Operator Overloading
//istream& operator >> (istream& output, truck& obj);
////OFstream / fout Operator Overloading
//ofstream& operator<<(ofstream& outFile, const truck& obj);

#endif TRUCK_H