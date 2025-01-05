#pragma once
#include <iostream>
#include <fstream>
//Deep Copy Function
char* deepCopy(const char* arr);
class vehicle
{
	char* companyName;
	char* color;
	int numberOfWheels;
	int powerCC;
	char* typeOfVehicle;
public:
	//Default Constructor
	vehicle();
	//Parameterized Constructor
	vehicle(const char* company, const char* clr, int wheels, int pwrCC, const char* vehicleType);
	//Copy Constructor
	vehicle(const vehicle& obj);
	//Assignment Operator
	vehicle& operator=(const vehicle& obj);
	//Setter
	void setCompanyName(char* companyN);
	void setColor(char* clr);
	void setNumberOfWheels(int wheel);
	void setPowerCC(int pwrCC);
	void setTypeOfVehicle(char* vehicleType);
	//Getter
	char* getCompanyName()const;
	char* getColor()const;
	int getNumberOfWheels()const;
	int getPowerCC()const;
	char* getTypeOfVehicle()const;
	//Virtual Function for Check Vehicle Type
	virtual void checkType() = 0;
	//Virtual Display Function
	virtual void display()const;
	//Destructor
	~vehicle();
};
////Ostream / cout Operator Overloading
//ostream& operator << (ostream& output, const vehicle& obj);
////Istream / cin Operator Overloading
//istream& operator >> (istream& inPut, vehicle& obj);