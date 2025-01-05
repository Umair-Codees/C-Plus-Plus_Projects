#pragma once
#include <iostream>
#include <fstream>
#include "vehicle.h"
#include "bike.h"
#include "car.h"
#include "truck.h"
//Deep Copy Function
char* deepCopy(const char* arr);
class BilalMotors
{
	static const int maxSize = 10;
	int count = 3;
	vehicle* vehicles[maxSize];
	bool cmpStrings(const char* Arr1, const char* Arr2);

public:
	//Default Constructor
	BilalMotors();
	//Get Count of Total Vehicles
	int getCount()const;
	//Add Vehicle Function
	void addVehicle(vehicle* veh);
	//Search Vehicle
	void searchVehicle(const char* type);
	//Data File Save
	bool saveData(const char* fileName)const;
	//Subscript Operator Overload
	vehicle* operator [](int index)const;
	vehicle* operator [](int index);
	//Destructor
	~BilalMotors();
};