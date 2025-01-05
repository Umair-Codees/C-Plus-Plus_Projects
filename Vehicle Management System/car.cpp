#include <iostream>
#include <fstream>
#include "car.h"
using namespace std;
//Default Constructor
car::car()
	: vehicle(nullptr, nullptr, 0, 0, nullptr)
{
	noOfDoors = 0;
	trasmission = nullptr;
	noOfSeats = 0;
	numberOfCars++;
}
//Parameterized Constructor
car::car(const char* company, const char* clr, int wheels, int pwrCC, const char* vehicleType, int door, const char* trans, int seat)
	:vehicle(company, clr, wheels, pwrCC, vehicleType)
{
	noOfDoors = door;
	trasmission = deepCopy(trans);
	noOfSeats = seat;
	numberOfCars++;
}
//Get Total Number of Bike
int car::getTotalCars()
{
	return numberOfCars;
}
//Copy Constructor
car::car(const car& obj)
	:vehicle(obj)
{
	noOfDoors = obj.noOfDoors;
	trasmission = deepCopy(obj.trasmission);
	noOfSeats = obj.noOfSeats;
}
//Assignment Operator Overloading
car& car::operator=(const car& obj)
{
	if (this != &obj)
	{
		vehicle::operator=(obj);
		noOfDoors = obj.noOfDoors;
		trasmission = deepCopy(obj.trasmission);
		noOfSeats = obj.noOfSeats;
	}

	return *this;
}
//Setter
void car::setNoOfDoors(int door)
{
	noOfDoors = door;
}
void car::setTransmission(char* trans)
{
	trasmission = deepCopy(trans);
}
void car::setNoOfSeats(int seat)
{
	noOfSeats = seat;
}
//Getter
int car::getNoOfDoors()const
{
	return noOfDoors;
}
char* car::getTransmission()const
{
	return deepCopy(trasmission);
}
int car::getNoOfSeats()const
{
	return noOfSeats;
}
//Check Type Of Wheel
void car::checkType()//Override
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
void car::display()const
{
	vehicle::display();
	cout << "\t " << noOfDoors << "\t  " << trasmission << "\t" << noOfSeats << endl;
}
//Destructor
car::~car()
{
	delete[]trasmission;
	numberOfCars--;
}
//Static Variable
int car::numberOfCars = 0;
////Ostream / cout Operator Overloading
//std::ostream& operator<<(std::ostream& output, const car& obj)
//{
//	output << obj.getCompanyName() << "   \t" << obj.getColor() << "\t   " << obj.getNumberOfWheels() << "\t  "
//		<< obj.getPowerCC() << "\t" << obj.getTypeOfVehicle() << "\t " << obj.getNoOfDoors() << "\t  " <<
//		obj.getTrasmission() << "\t" << obj.getNoOfSeats() << endl;
//	return output;
//}
////Istream / cin Operator Overloading
//istream& operator >> (istream& inPut, car& obj)
//{
//	int noOfDoors, noOfSeats;
//	char transmission[20];
//
//	cout << "Enter number of doors: ";
//	inPut >> noOfDoors;
//	obj.setNoOfDoors(noOfDoors);
//
//	cout << "Enter transmission (automatic or manual): ";
//	inPut >> transmission;
//	obj.setTransmission(transmission);
//
//	cout << "Enter number of seats: ";
//	inPut >> noOfSeats;
//	obj.setNoOfSeats(noOfSeats);
//
//	return inPut;
//}
////OFstream / fout Operator Overloading
//std::ofstream& operator<<(std::ofstream& outFile, const car& obj)
//{
//	outFile << obj.getCompanyName() << "\t\t" << obj.getTypeOfVehicle() << "\t\t"
//		<< obj.getColor() << "\t\t" << obj.getPowerCC() << endl;
//	return outFile;
//}