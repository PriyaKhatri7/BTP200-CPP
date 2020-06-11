#include <iostream>
#include <cstring> //strcpy
#include "Vehicle.h"
#include "ReadWritable.h"

using namespace std;

namespace sdds
{
	//default constructor
	Vehicle::Vehicle()
	{
		v_licenseplate = nullptr;
		v_model = nullptr;
		v_pkspotNum = 0;
	}

	//constructor. values set the properties of the Vehicle
	//and the parking spot is set to zero. else empty
	Vehicle::Vehicle(const char* plate, const char* model)
	{
		//set retrictions for the license plate 1-8 characters. model cannot be null
		if ((plate != nullptr && strlen(plate) < 8 && strlen(plate) > 1) && (model != nullptr) && (strlen(model) > 2))
		{
			v_licenseplate = new char[strlen(plate) + 1];
			strcpy(v_licenseplate, plate);
			v_model = new char[strlen(model) + 1];
			//set values
			strcpy(v_model, model);

			v_pkspotNum = 0;
		}
		else { setEmpty(); }
	}

	Vehicle::~Vehicle()
	{
		delete[] v_model;
		v_model = nullptr;
	}

	//returns parking spot num of V
	int Vehicle::getParkingSpot() const
	{
		return this->v_pkspotNum;
	}

	void Vehicle::setParkingSpot(int newpkspottemp)
	{
		//if it has a value
		if (newpkspottemp >= 0)
		{
			//reset to new values
			v_pkspotNum = -1;
			v_pkspotNum = newpkspottemp;
		}
		else { setEmpty(); }
	}

	//overides read from readwritable class
	std::istream& Vehicle::read(std::istream& read)
	{
		if (this->isCsv() == true)
		{
			//read int for pkspotnum
			read >> v_pkspotNum;
			//then ignore 1 character 
			read.ignore(1, ',');
			//read up to 8 chars for plate 
			read.get(v_licenseplate, 5); //5
			read.ignore(1, ',');

			for (int i = 0; i < 5; i++)
			{
				//store it in plate all UPPER
				v_licenseplate[i] = toupper(v_licenseplate[i]);
			}

			//read up to 60 chars for model and dynamically store it
			read.get(v_model, 60);
			setMakeModel(v_model);
		}

		else
		{
			cout << "Enter Licence Plate Number: ";
			v_licenseplate = new char[60];
			read.get(v_licenseplate, 10);

			//read up to 8 chars. if user enters more then error and try again
			if (strlen(v_licenseplate) > 8)
			{
				read.clear();
				read.ignore(100, '\n');
				cout << "Invalid Licence Plate, try again: ";
				read.get(v_licenseplate, 10);
			}

			cout << "Enter Make and Model: ";
			v_model = new char[8];
			read >> v_model;

			//read 2-60 chars. 
			if (strlen(v_model) < 2 || strlen(v_model) > 60)
			{
				read.clear();
				read.ignore(100, '\n');
				cout << "Invalid Make and model, try again: ";
				read >> v_model;
			}

			//check for istream obj fails while reading. set empty 
			if (read.fail()) { setEmpty(); }

			read.clear();
			read.ignore(100, '\n');
		}
		return read; //return obj
	}

	std::ostream& Vehicle::write(std::ostream& write) const
	{
		if (isEmpty())
		{
			cout << "Invalid Vehicle Object" << endl;
		}
		else if (this->isCsv() == true)
		{
			//else print valpkspot number, plate, and model
			write << v_pkspotNum << "," << v_licenseplate << "," << v_model;
		}
		//if not comma separated mode then print message
		else if (isCsv() == false)
		{
			write << "Parking Spot Number: ";
			if (v_pkspotNum == 0){ write << "N/A" << endl; }
			else { write << v_pkspotNum << endl; }

			write << "Licence Plate: ";
			for (int i = 0; i < 3; i++)
			{
				putchar(toupper(v_licenseplate[i]));
			}
			write << endl;

			write << "Make and Model: ";
			write << v_model << endl;
		}
		return write; //return os object
	}

	void Vehicle::setEmpty()
	{
		v_licenseplate = nullptr;
		v_model = nullptr;
		v_pkspotNum = 0;
	}

	//if state is in a empty state then return true
	bool Vehicle::isEmpty() const
	{
		if (v_licenseplate == nullptr)
		{
			return true;
		}
		else { return false; }
	}

	std::istream& Vehicle::getLicensePlate(std::istream& plate) const
	{
		//returns a read only address of license plate 
		return plate;
	}

	std::istream& Vehicle::getMakeModel(std::istream& model) const
	{
		//returns a read only address of the make and model
		return model;
	}

	//resets the make and model of vehical to new value
	void Vehicle::setMakeModel(const char* newmodeltemp)
	{
		if (newmodeltemp != nullptr)
		{
			v_model = nullptr;
			v_model = new char[strlen(newmodeltemp) + 1];
			strcpy(v_model, newmodeltemp);
		}
		else { setEmpty(); }
	}
	
	//compares license plate of V with license plate value returns true if identical
	//not case senstive. if invalid it's false
	bool operator==(const Vehicle& lp, const char* lpvalue)
	{
		if (strcmp(lp.v_licenseplate, lpvalue))
		{
			return true;
		}
		else { return false; }
	}

	//similar to ^^.compares strings
	bool operator==(const Vehicle& lp, const Vehicle& lpvalue)
	{
		if (strcmp(lp.v_licenseplate, lpvalue.v_licenseplate))
		{
			return true;
		}
		else { return false; }
	}

}