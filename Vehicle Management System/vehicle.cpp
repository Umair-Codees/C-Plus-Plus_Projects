#include <iostream>
#include <fstream>
#include "vehicle.h"
using namespace std;
//Default Constructor
vehicle::vehicle()
{
	companyName = nullptr;
	color = nullptr;
	numberOfWheels = 0;
	powerCC = 0;
	typeOfVehicle = nullptr;

}
//Default & Parameterized Constructor
vehicle::vehicle(const char* company, const char* clr, int wheels, int pwrCC, const char* vehicleType)
{
	companyName = deepCopy(company);
	color = deepCopy(clr);
	numberOfWheels = wheels;
	powerCC = pwrCC;
	typeOfVehicle = deepCopy(vehicleType);
}
//Copy Constructor
vehicle::vehicle(const vehicle& obj)
{
	companyName = obj.companyName;
	color = obj.color;
	numberOfWheels = obj.numberOfWheels;
	powerCC = obj.powerCC;
	typeOfVehicle = obj.typeOfVehicle;
}
// Assignment Operator
vehicle& vehicle::operator=(const vehicle& obj)
{
	if (this != &obj)
	{
		companyName = obj.companyName;
		color = obj.color;
		numberOfWheels = obj.numberOfWheels;
		powerCC = obj.powerCC;
		typeOfVehicle = obj.typeOfVehicle;

	}

	return *this;
}
//Setter
void vehicle::setCompanyName(char* companyN)
{
	if (companyName)
	{
		delete[] companyName;
	}
	companyName = companyN;
}
void vehicle::setColor(char* clr)
{
	if (companyName)
	{
		delete[] color;
	}
	color = clr;
}
void vehicle::setNumberOfWheels(int wheel)
{
	numberOfWheels = wheel;
}
void vehicle::setPowerCC(int pwrCC)
{
	powerCC = pwrCC;
}
void vehicle::setTypeOfVehicle(char* vehicleType)
{
	if (typeOfVehicle)
	{
		delete[] typeOfVehicle;
	}
	typeOfVehicle = vehicleType;
}
//Getter
char* vehicle::getCompanyName()const
{
	return deepCopy(companyName);
}
char* vehicle::getColor()const
{
	return deepCopy(color);
}
int vehicle::getNumberOfWheels()const
{
	return numberOfWheels;
}
int vehicle::getPowerCC()const
{
	return powerCC;
}
char* vehicle::getTypeOfVehicle()const
{
	return deepCopy(typeOfVehicle);
}
//Virtual Display Function
void vehicle::display()const
{
	cout << companyName << "   \t" << color << "\t   " << numberOfWheels << "\t  "
		<< powerCC << "\t" << typeOfVehicle;
}
//Destructor
vehicle::~vehicle()
{
	delete companyName;
	delete color;
	delete typeOfVehicle;
}
////Ostream / cout Operator Overloading
//ostream& operator << (ostream& outPut, const vehicle& obj)
//{
//	outPut << obj.getCompanyName() << "   \t" << obj.getColor() << "\t   " << obj.getNumberOfWheels() << "\t  "
//		<< obj.getPowerCC() << "\t" << obj.getTypeOfVehicle() << endl;
//	return outPut;
//}
////Istream / cin Operator Overloading
//istream& operator >> (istream& inPut, vehicle& obj)
//{
//	char company[20], color[20], type[20];
//	int wheels, power;
//
//	cout << "Enter company name: ";
//	inPut.getline(company, 19);
//	obj.setCompanyName(company);
//
//	cout << "Enter color: ";
//	inPut.getline(color, 19);
//	obj.setColor(color);
//
//	cout << "Enter number of wheels: ";
//	inPut >> wheels;
//	obj.setNumberOfWheels(wheels);
//
//	cout << "Enter power CC: ";
//	inPut >> power;
//	obj.setPowerCC(power);
//
//	cout << "Enter type of vehicle: ";
//	inPut.getline(type, 19);
//	obj.setTypeOfVehicle(type);
//
//	return inPut;
//}