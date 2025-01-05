#include <iostream>
#include <fstream>
#include "vehicle.h"
#include "bike.h"
#include "car.h"
#include "truck.h"
#include "bilalMotors.h"
using namespace std;

//Find String length
int length(const char* arr);
//Deep Copy Function
char* deepCopy(const char* arr);
//Main Menu Function
void menu(BilalMotors& obj);
//Add Vehicle Menu Function
void menuAddVehicle(BilalMotors& obj);
//Vehicle Display Function
void showVehicle(const BilalMotors& obj);

int main()
{
	BilalMotors obj;

	menu(obj);

	return 0;
}
//Find String length
int length(const char* arr)
{
	int l = 0;
	while (arr[l] != '\0')
	{
		l++;
	}
	return l;
}
//Deep Copy Function
char* deepCopy(const char* arr)
{
	int size = length(arr);
	char* temp = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = '\0';
	return temp;
}
//Main Menu Function
void menu(BilalMotors& obj)
{
	system("cls");

	int count = 0;
	char choice;

	cout << "\n\n\t    *** BILAL MOTORS ***\n\n";
	cout << "\tS -> Show vehicles list (brief)\n";
	cout << "\tE -> Create a data file (output file)\n";
	cout << "\tA -> Add new vehicle\n";
	cout << "\tF -> Find Vehicle by Type\n";
	cout << "\tQ -> Quit Program\n";

	while (true)
	{
		cout << "\n\tEnter Choice :) ";
		cin >> choice;

		if (choice == 'S' || choice == 's')
		{
			system("cls");
			showVehicle(obj);

			break;
		}
		else if (choice == 'E' || choice == 'e')
		{
			char* fileName = new char[20];

			system("cls");

			cout << "\n\n\t\tCreate a File to Store All Data";
			cout << "\n\n\t\tEnter File Name ... ) ";
			cin.ignore();
			cin.getline(fileName, 19);

			if (obj.saveData(fileName) == 1)
			{
				cout << "\n\t\tData Successfully Save in " << fileName << endl;
			}
			else
			{
				cout << "\n\t\tSome Error in Your File " << fileName << endl;
			}

			while (true)
			{
				char more = '\0';

				cout << "\n\t\tM -> Main Menu";
				cout << "\n\t\tQ -> Quit Program";
				cout << "\n\n\t\tEnter Your Choice ... ) ";
				cin >> more;

				if (more == 'M' || more == 'm')
				{
					system("cls");
					menu(obj);
					break;
				}
				else if (more == 'Q' || more == 'q')
				{
					system("cls");
					cout << "\n\t\tProgram Is Quiting ..... ";
					break;
				}
				else
				{
					cout << "\n\t\tInvalid Choice!";
				}
			}

			delete[]fileName;

			break;
		}
		else if (choice == 'A' || choice == 'a')
		{
			system("cls");
			menuAddVehicle(obj);

			break;
		}
		else if (choice == 'F' || choice == 'f')
		{
			char* searchVehicle = new char[20];

			system("cls");

			cout << "\n\t *** Find Vehicle by Type ***\n\n";
			cin.ignore();
			cout << "\tEnter Vehicle Type [Bike/Car/Truck] ... ) ";
			cin.getline(searchVehicle, 19);

			obj.searchVehicle(searchVehicle);

			break;
		}
		else if (choice == 'Q' || choice == 'q')
		{
			system("cls");
			cout << "\n\n\t  ******  Your  Program  is  Quit!  ******";
			cout << "\n\n\t\t   ***  GOOD  BYE!  ***  ";

			break;
		}
		else if (count == 5)
		{
			system("cls");
			menu(obj);

			break;
		}
		else
		{
			cout << "\n\t*You Enter Invalid Choice";
			count++;
		}
	}
}
//Add Vehicle Menu Function
void menuAddVehicle(BilalMotors& obj)
{
	char* cmpny = new char[15];
	char* clr = new char[15];
	int pwr = 0;
	char type;

	system("cls");
	cout << "\n\n\t   *** ADD NEW VEHICLE ***\n";
	cout << "\n\tB -> Bike";
	cout << "\n\tC -> Car";
	cout << "\n\tT -> Truck";
	cout << "\n\tE -> Exit Main Menu";

	while (true)
	{
		cout << "\n\n\tEnter Type Of Vehicle :) ";
		cin >> type;

		if (type == 'B' || type == 'b')
		{
			double h = 0.0;
			bool start = false, brake = false;

			system("cls");

			cout << "\n\n\t*** ADD BIKE INFORMATION ***\n";
			cin.ignore();
			cout << "\nEnter Company Name ... ";
			cin.getline(cmpny, 14);

			cout << "Enter Color  ... ";
			cin.getline(clr, 14);

			cout << "Enter PowerCC... ";
			cin >> pwr;

			cout << "Enter Height ... ";
			cin >> h;

			cout << "Enter Self Start [1 Yes 0 No]... ";
			cin >> start;

			cout << "Enter Disc Brake [1 Yes 0 No]... ";
			cin >> brake;

			vehicle* mybike = new bike(cmpny, clr, 2, pwr, "Bike", h, start, brake);
			obj.addVehicle(mybike);

			while (true)
			{
				char more = '\0';
				cout << "\n\t\tDo You Want Add More Vehicle [Y/N] ... ) ";
				cin >> more;

				if (more == 'Y' || more == 'y')
				{
					system("cls");
					menuAddVehicle(obj);
					break;
				}
				else if (more == 'N' || more == 'n')
				{
					system("cls");
					menu(obj);
					break;
				}
				else
				{
					cout << "\n\t\tInvalid Input!!";
				}
			}

			delete mybike;

			break;
		}
		else if (type == 'C' || type == 'c')
		{
			int door = 0, seat = 0;
			char* transmition = new char[15];

			system("cls");

			cout << "\n\n\t*** ADD CAR INFORMATION ***\n";
			cout << "\nEnter Company Name ... ";
			cin.ignore();
			cin.getline(cmpny, 14);

			cout << "Enter Color  ... ";
			cin.getline(clr, 14);

			cout << "Enter PowerCC... ";
			cin >> pwr;

			cout << "Enter Number Of Doors ... ";
			cin >> door;

			cout << "Enter Number Of Seats ... ";
			cin >> seat;

			cout << "Enter Transmition( Auto/Manual ) ... ";
			cin.ignore();
			cin.getline(transmition, 14);

			vehicle* mycar = new car(cmpny, clr, 4, pwr, "Car", door, transmition, seat);
			obj.addVehicle(mycar);

			while (true)
			{
				char more = '\0';
				cout << "\n\t\tDo You Want Add More Vehicle [Y/N] ... ) ";
				cin >> more;

				if (more == 'Y' || more == 'y')
				{
					system("cls");
					menuAddVehicle(obj);
					break;
				}
				else if (more == 'N' || more == 'n')
				{
					system("cls");
					menu(obj);
					break;
				}
				else
				{
					cout << "\n\t\tInvalid Input!!";
				}
			}

			delete mycar;
			delete[]transmition;
			break;
		}
		else if (type == 'T' || type == 't')
		{
			bool wheelDrive = 0;
			double containerSize = 0.0;
			char* category = new char[20];

			system("cls");

			cout << "\n\n\t*** ADD Truck INFORMATION ***\n";
			cin.ignore();
			cout << "\nEnter Company Name ... ";
			cin.getline(cmpny, 14);

			cout << "Enter Color  ... ";
			cin.getline(clr, 14);

			cout << "Enter PowerCC... ";
			cin >> pwr;

			cout << "Enter Four Wheel Drive [1 Yes 0 No]... ";
			cin >> wheelDrive;

			cout << "Enter Container Size ... ";
			cin >> containerSize;

			cout << "Enter Category( Single/Double Cabin) ... ";
			cin.ignore();
			cin.getline(category, 14);

			vehicle* mytruck = new truck(cmpny, clr, 8, pwr, "Truck", containerSize, category, wheelDrive);
			obj.addVehicle(mytruck);

			while (true)
			{
				char more = '\0';
				cout << "\n\t\tDo You Want Add More Vehicle [Y/N] ... ) ";
				cin >> more;

				if (more == 'Y' || more == 'y')
				{
					system("cls");
					menuAddVehicle(obj);
					break;
				}
				else if (more == 'N' || more == 'n')
				{
					system("cls");
					menu(obj);
					break;
				}
				else
				{
					cout << "\n\t\tInvalid Input!!";
				}
			}

			delete mytruck;
			delete[]category;
			break;
		}
		else if (type == 'E' || type == 'e')
		{
			menu(obj);
			break;
		}
		else
		{
			cout << "\n\t*You Enter Invalid Vehicle Type";
		}
	}

	delete[]cmpny;
	delete[]clr;
}
//Vehicle Display Function
void showVehicle(const BilalMotors& obj)
{
	cout << "\n\n\t\t   *** VEHICLE  INFORMATION ***\n\n";
	cout << "\t\t------------------------------------\n";
	cout << "\t\t   Total Number Of Vehicles :: " << obj.getCount();
	cout << "\n\t\t------------------------------------\n\n";

	cout << "---------------------------------------------------------------------------------\n";
	cout << "Company Name\tColor\tWheels\t Power\tType\tHeight\tSelf-Start  Disc-Brake\n";
	for (int i = 0; i < obj.getCount(); i++)
	{
		if (obj[i]->getNumberOfWheels() == 2)
		{
			obj[i]->display();
		}
	}
	cout << "\nCompany Name\tColor\tWheels\t Power\tType\tDoors\tTransmission   Seats\n";
	for (int i = 0; i < obj.getCount(); i++)
	{
		if (obj[i]->getNumberOfWheels() == 4)
		{
			obj[i]->display();
		}
	}
	cout << "\nCompany Name\tColor\t Wheels\t Power\tType\tSize\tCategory  FourWheelDrive\n";
	for (int i = 0; i < obj.getCount(); i++)
	{
		if (obj[i]->getNumberOfWheels() > 4 && obj[i]->getNumberOfWheels() < 18)
		{
			obj[i]->display();
		}
	}
	cout << "\n\n---------------------------------------------------------------------------------\n";

}