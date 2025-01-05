#include <iostream>
#include <fstream>
#include "truck.h"
using namespace std;
//Default Constructor
truck::truck()
	: vehicle(nullptr, nullptr, 0, 0, nullptr)
{
	containerSize = 0.0;
	category = nullptr;
	fourWheelDrive = 0;
	numberOfTrucks++;
}
//Parameterized Constructor
truck::truck(const char* company, const char* clr, int wheels, int pwrCC, const char* vehicleType, double Size, const char* cate, bool fourWheelD)
	:vehicle(company, clr, wheels, pwrCC, vehicleType)
{
	containerSize = Size;
	category = deepCopy(cate);
	fourWheelDrive = fourWheelD;
	numberOfTrucks++;
}
//Get Total Number of Bike
int truck::getTotalTrucks()
{
	return numberOfTrucks;
}
//Copy Constructor
truck::truck(const truck& obj)
	:vehicle(obj)
{
	containerSize = obj.containerSize;
	category = deepCopy(obj.category);
	fourWheelDrive = obj.fourWheelDrive;
}
//Assignment Operator Overloading
truck& truck::operator=(const truck& obj)
{
	if (this != &obj)
	{
		vehicle::operator=(obj);
		containerSize = obj.containerSize;
		category = deepCopy(obj.category);
		fourWheelDrive = obj.fourWheelDrive;
	}
	return *this;
}
//Setter
void truck::setContainerSize(int size)
{
	containerSize = size;
}
void truck::setCategory(char* cate)
{
	category = deepCopy(cate);
}
void truck::setFourWheelDrive(bool wheel)
{
	fourWheelDrive = wheel;
}
//Getter
double truck::getContainerSize()const
{
	return containerSize;
}
char* truck::getCategory()const
{
	return deepCopy(category);
}
bool truck::getFourWheelDrive()const
{
	return fourWheelDrive;
}
//Check Type Of Wheel
void truck::checkType()//Override
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
void truck::display()const
{
	vehicle::display();
	cout << "\t" << containerSize << " \t" << category << "\t" << fourWheelDrive << endl;
}
//Destructor
truck::~truck()
{
	delete[]category;
}
//Static Variable
int truck::numberOfTrucks = 0;
////Ostream / cout Operator Overloading
//ostream& operator<<(ostream& output, const truck& obj)
//{
//	output << obj.getCompanyName() << "   \t" << obj.getColor() << "\t   " << obj.getNumberOfWheels() << "\t  "
//		<< obj.getPowerCC() << "\t" << obj.getTypeOfVehicle() << "\t" << obj.getContainerSize() << " \t" <<
//		obj.getCategory() << "\t" << obj.getFourWheelDrive() << endl;
//	return output;
//}
////Istream / cin Operator Overloading
//istream& operator >> (istream& inPut, truck& obj)
//{
//	double containerSize;
//	char category[100];
//	bool fourWheelDrive;
//
//	cout << "Enter container size: ";
//	inPut >> containerSize;
//	obj.setContainerSize(containerSize);
//
//	cout << "Enter category (double-cabin or single-cabin): ";
//	inPut >> category;
//	obj.setCategory(category);
//
//	cout << "Does it have four wheel drive? (1 for yes, 0 for no): ";
//	inPut >> fourWheelDrive;
//	obj.setFourWheelDrive(fourWheelDrive);
//
//	return inPut;
//}
////Ofstream / fout Operator Overloading
//ofstream& operator<<(ofstream& outFile, const truck& obj)
//{
//	outFile << obj.getCompanyName() << "\t\t" << obj.getTypeOfVehicle() << "\t\t"
//		<< obj.getColor() << "\t\t" << obj.getPowerCC() << endl;
//	return outFile;
//}