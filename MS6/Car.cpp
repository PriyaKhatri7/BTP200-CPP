#include <iostream>
#include <cstring> //strlen
#include "Car.h"
#include "Vehicle.h"
#include "ReadWritable.h"
using namespace std;

namespace sdds
{
	//default
	Car::Car() : Vehicle()
	{
		c_carwashflag = false;
		v_model = nullptr;
		vc_licenseplate = nullptr;
	}

	//similar to V
	Car::Car(const char* plate, const char* model) : Car()
	{
		if ((plate != nullptr && strlen(plate) < 8 && strlen(plate) > 1) && (model != nullptr) && (strlen(model) > 2))
		{
			//set values
			vc_licenseplate = new char[strlen(plate) + 1];
			strcpy(vc_licenseplate, plate);
			v_model = new char[strlen(model) + 1];
			strcpy(v_model, model);

			c_carwashflag = false;
		}
	}

	std::istream& Car::read(std::istream& read)
	{
		if (isCsv() == true)
		{
			//calls read from base class (V)
			Vehicle::read(read);
			//reads a bool value (1 or 0) into wash flag
			read >> c_carwashflag;
			//ignore the rest of the chars include newline
			read.ignore(800, '\n');

		}

		else
		{
			bool exitapp = false;
			char select[10];

			//if car is not set to comma separated mode
			cout << "\nCar information entry\n";
			Vehicle::read(read); //read from base class

			cout << "Carwash while parked? (Y)es/(N)o: ";


			//based on user's response set the flag to true or false
			read.getline(select, 3);

			while (exitapp == false)
			{
				if ((select[0] == 'Y' || select[0] == 'y') && (select[1] == '\0'))
				{
					c_carwashflag = true;
					return read;
				}
				else if ((select[0] == 'N' || select[0] == 'n') && (select[1] == '\0'))
				{
					c_carwashflag = false;
					return read;
				}
				else
				{
					read.clear();
					read.ignore(9000, '\n');
					//will keep asking until user is correct answer
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					read.getline(select, 3);
				}
			}
		}
		return read; //return read obj
	}

	std::ostream& Car::write(std::ostream& write) const
	{
		//if invalid output message
		if (Vehicle::isEmpty()) { write << "Invalid Car Object" << endl; }
		//if the car is in comma separated state print message
		else if (isCsv() == true)
		{
			write << "C,";
			//write the base class
			Vehicle::write(write);
			write << c_carwashflag << endl;
		}
		else
		{
			write << "Vehicle type: Car" << endl;
			//write from base class
			Vehicle::write(write);

			if (isCsv() == true) { write << c_carwashflag << endl; }
			else
			{
				//checks if carwash flag is true or false and print message accordingly
				if (c_carwashflag == true) { write << "With Carwash" << endl; }
				else { write << "Without Carwash" << endl; }
			}
		}
		return write; //return ostream obj
	}

	Car::~Car()
	{
		delete[] v_model;
		v_model = nullptr;
	}

}

