#include <iostream>
#include "bike.h"
using namespace std;
// Default Constructor
bike::bike()
	: vehicle(nullptr, nullptr, 0, 0, nullptr)
{
	height = 0.0;
	selfStart = false;
	discBrake = false;
	numberOfBikes++;
}
// Default & Parameterized Constructor
bike::bike(const char* company, const char* clr, int wheels, int pwrCC, const char* vehicleType, double h, bool start, bool brake)
	: vehicle(company, clr, wheels, pwrCC, vehicleType)
{
	height = h;
	selfStart = start;
	discBrake = brake;
	numberOfBikes++;
}
//Copy Constructor
bike::bike(const bike& obj)
	:vehicle(obj)
{
	height = obj.height;
	selfStart = obj.selfStart;
	discBrake = obj.discBrake;
}
//Assignment Operator
bike& bike::operator = (const bike& obj)
{
	if (this != &obj)
	{
		vehicle::operator=(obj);
		height = obj.height;
		selfStart = obj.selfStart;
		discBrake = obj.discBrake;
	}

	return *this;
}
//Setter
void bike::setHeight(double h)
{
	height = h;
}
void bike::setSelfStart(bool start)
{
	selfStart = start;
}
void bike::setDiscBrake(bool brake)
{
	discBrake = brake;
}
//Getter
double bike::getHeight()const
{
	return height;
}
bool bike::getSelfStart()const
{
	return selfStart;
}
bool bike::getDiscBrake()const
{
	return discBrake;
}
//Get Total Number of Bike
int bike::getTotalBikes()
{
	return numberOfBikes;
}
//Check Type Of Wheel
void bike::checkType()//Override
{
	if (getNumberOfWheels() == 2)
	{
		char* vehicleType = new char[4] {'B', 'i', 'k', 'e'};

		vehicle::setTypeOfVehicle(vehicleType);

		delete[]vehicleType;
	}
	else if (getNumberOfWheels() == 4)
	{
		char* vehicleType = new char[3] {'C', 'a', 'r'};

		vehicle::setTypeOfVehicle(vehicleType);

		delete[]vehicleType;
	}
	else if (getNumberOfWheels() >= 6 || getNumberOfWheels() <= 18)
	{
		if (getNumberOfWheels() % 2 == 0)
		{
			char* vehicleType = new char[4] {'T', 'r', 'u', 'k'};

			vehicle::setTypeOfVehicle(vehicleType);

			delete[]vehicleType;
		}
	}
}
//Display Function
void bike::display()const
{
	vehicle::display();
	cout << "\t " << height << "\t    " << selfStart << "\t\t" << discBrake << endl;
}
//Destructor
bike::~bike()
{
	numberOfBikes--;
}
//Static Variable
int bike::numberOfBikes = 0;
////Ostream / cout Operator Overloading
//ostream& operator << (ostream& output, const bike& obj)
//{
//	output << obj.getCompanyName() << "   \t" << obj.getColor() << "\t   " << obj.getNumberOfWheels() << "\t  "
//		<< obj.getPowerCC() << "\t" << obj.getTypeOfVehicle() << "\t " << obj.getHeight() << "\t    "
//		<< obj.getSelfStart() << "\t\t" << obj.getDiscBrake() << endl;
//	return output;
//}
////Istream / cin Operator Overloading
//istream& operator >> (istream& inPut, bike& obj)
//{
//	double h = 0.0;
//	bool start = false, brake = false;
//
//	cout << "Enter Height ... ";
//	inPut >> h;
//	obj.setHeight(h);
//
//	cout << "Enter Self Start [1 Yes 0 No]... ";
//	inPut >> start;
//	obj.setSelfStart(start);
//
//	cout << "Enter Disc Brake [1 Yes 0 No]... ";
//	inPut >> brake;
//	obj.setDiscBrake(brake);
//}
////Ofstream / fout Operator Overloading
//ofstream& operator << (ofstream& outFile, const bike& obj)
//{
//	outFile << obj.getCompanyName() << "\t\t" << obj.getTypeOfVehicle() << "\t\t"
//		<< obj.getColor() << "\t\t" << obj.getPowerCC() << endl;
//	return outFile;
//}