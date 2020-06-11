#include <iostream>
#include <cstring>
#include "Motorcycle.h"
#include "Vehicle.h"
#include "ReadWritable.h"
using namespace std;

namespace sdds
{
	//default 
	Motorcycle::Motorcycle() : Vehicle()
	{
		m_sidecarFlag = false;
		vm_licenseplate = nullptr;
		vm_model = nullptr;

	}

	Motorcycle::Motorcycle(const char* plate, const char* model) : Motorcycle()
	{
		if ((plate != nullptr && strlen(plate) < 8 && strlen(plate) > 1) && (model != nullptr) && (strlen(model) > 2))
		{
			//set new values
			vm_licenseplate = new char[strlen(plate) + 1];
			strcpy(vm_licenseplate, plate);

			vm_model = new char[strlen(model) + 1];
			strcpy(vm_model, model);

			m_sidecarFlag = false;
		}
	}

	Motorcycle::~Motorcycle()
	{
		delete[] vm_model;
		vm_model = nullptr;
	}

	//overrides the read of Vehicle class
	std::istream& Motorcycle::read(std::istream& read)
	{
		//if comma separated mode is true
		if (isCsv() == true)
		{
			//read the base class Vehicle
			Vehicle::read(read);
			//reads a bool value (1 or 0) into sidecarFlag
			read >> m_sidecarFlag;
			//ignores leftovers chars
			read.ignore(800, '\n');
		}
		else
		{
			cout << "\nMotorcycle information entry" << endl;
			//read base class Vehicle
			Vehicle::read(read);

			//then prompt user. Based on this answer it will set to true and false
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";

			char select[10]; //input user value
			read.getline(select, 3);

			bool exitapp = false;
			while (exitapp == false)
			{
				if ((select[0] == 'Y' || select[0] == 'y') && (select[1] == '\0'))
				{
					m_sidecarFlag = true;
					return read;
				}
				else if ((select[0] == 'N' || select[0] == 'n') && (select[1] == '\0'))
				{
					m_sidecarFlag = false;
					return read;
				}
				else
				{
					read.clear();
					read.ignore(9000, '\n');
					//keep printing this if the user inputs anything else
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					read.getline(select, 3);
				}
			}
		}
		return read; //return istream obj 
	}

	std::ostream& Motorcycle::write(std::ostream& write) const
	{
		//if invalid then write message using ostream object and return ostream object
		if (isEmpty())
		{
			write << "Invalid Motorcycle Object" << endl;
		}

		//if mode if true
		else if (isCsv() == true)
		{
			write << "M,";
			//write the base class
			Vehicle::write(write);
			//print sidecarFlag. true
			write << m_sidecarFlag << endl;
		}
		else
		{
			//otherwise print this message
			write << "Vehicle type: Motorcycle" << endl;
			Vehicle::write(write); //write base class

			if (isCsv() == true)
			{
				write << m_sidecarFlag << endl;
			}
			else
			{
				//if true print message
				if (m_sidecarFlag == true)
				{
					write << "With Sidecar" << endl;
				}
			}
		}
		return write; //return ostream obj
	}

}