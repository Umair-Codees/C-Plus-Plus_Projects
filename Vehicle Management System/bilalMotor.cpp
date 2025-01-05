#include <iostream>
#include <fstream>
#include "bilalMotors.h"
#include "car.h"
#include "bike.h"
#include "truck.h"
using namespace std;
//Check Both String Index by Index
bool BilalMotors::cmpStrings(const char* Arr1, const char* Arr2)
{
	for (int i = 0; Arr1[i] && Arr2[i]; ++i)
	{
		if (Arr1[i] != Arr2[i])
		{
			return false;
		}
	}
	// Check if both strings have reached the end ('\0')
	return (Arr1[0] == '\0' && Arr2[0] == '\0');
}
//Default Constructor
BilalMotors::BilalMotors()
{
	vehicles[0] = new bike("Honda CD-70", "Black", 2, 150, "Bike", 22.3, 1, 1);;
	vehicles[1] = new car("Honda Civic", "Gray", 4, 1300, "Car", 4, "Manual", 4);
	vehicles[2] = new truck("Land-Cruiser", "Black", 8, 2300, "Truck", 18.5, "Double-C", 1);
}
//Get Count of Total Vehicles
int BilalMotors::getCount()const
{
	return count;
}
//Add Vehicle Function
void BilalMotors::addVehicle(vehicle* veh)
{
	if (count < maxSize)
	{
		cout << "\n\t\tVehicle Add Successfully!\n";
		vehicles[count] = veh;
		count++;
	}
	else
	{
		cout << "Vehicle Menu Full. Cannot Add More Items.\n";
	}
}
//Search Vehicle
void BilalMotors::searchVehicle(const char* type)
{
	for (int i = 0; i < count; ++i)
	{
		if (cmpStrings(vehicles[i]->getTypeOfVehicle(), type) == 1)
		{
			cout << "\t" << type << " is Available\n";
			vehicles[i]->display();
		}
		else
		{
			cout << "\n\t\tVehicle Not Found!!";
		}
	}
}
//Data File Function
bool BilalMotors::saveData(const char* fileName)const
{
	ofstream fout;
	fout.open(fileName);

	if (!fout.is_open())
	{
		cout << "Error: Unable to Open File " << fileName << endl;
		return false;
	}
	else
	{
		fout << "Vehicle Information\n";
		fout << "---------------------\n\n";

		fout << "Number of Bikes: " << bike::getTotalBikes() << endl;
		fout << "Number of Cars: " << car::getTotalCars() << endl;
		fout << "Number of Trucks: " << truck::getTotalTrucks() << endl;

		fout << "----------------------------------------------------------------------\n";
		fout << "\nCompany Name\t\tType\t\tColor\t\tPower\n";
		fout << "----------------------------------------------------------------------\n";

		for (int i = 0; i < count; i++)
		{
			fout << vehicles[i]->getCompanyName() << "\t\t" << vehicles[i]->getTypeOfVehicle() << "\t\t"
				<< vehicles[i]->getColor() << "\t\t" << vehicles[i]->getPowerCC() << endl;
		}
		fout << "----------------------------------------------------------------------\n";
		
		fout.close();
		return true;
	}
}
//Subscript Operator Overload
vehicle* BilalMotors::operator[](int index) const
{
	if (index >= 0 && index < count)
	{
		return vehicles[index];
	}
	return nullptr;
}
vehicle* BilalMotors::operator[](int index)
{
	if (index >= 0 && index < count)
	{
		return vehicles[index];
	}
	return nullptr;
}
//Destructor
BilalMotors::~BilalMotors()
{
	for (int i = 0; i < maxSize; i++)
	{
		delete vehicles[i];
	}
}