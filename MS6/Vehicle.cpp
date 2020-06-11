#include <iostream>
#include <cstring> //strcpy
#include <cctype>
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



	bool Vehicle::operator==(const char* plate) const
	{
		if (strncmp(v_licenseplate, plate, 8) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Vehicle::operator==(const Vehicle& n) const
	{
		if (strcmp(n.v_licenseplate, this->v_licenseplate))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//overides read from readwritable class
	std::istream& Vehicle::read(std::istream& read)
	{
		//for mod 6. add temp variables
		char tempLicence[100] = "\0";
		char tempModel[100] = "\0";

		if (this->isCsv() == true)
		{
			read.ignore(1, ',');
			//read int for pkspotnum
			read >> v_pkspotNum;
			//then ignore 1 character 
			read.ignore(1, ',');
			//read up to 8 chars for plate 
			//read.get(v_licenseplate, 10, ',');
			read.getline(tempLicence, 10, ',');

			for (unsigned int i = 0; i < strlen(tempLicence); i++)
			{
				//store it in plate all UPPER
				tempLicence[i] = toupper(v_licenseplate[i]);
			}

			if (read.fail())
			{
				delete[] v_licenseplate;
				v_licenseplate = nullptr;
			}
			else
			{
				delete[] v_licenseplate;
				v_licenseplate = nullptr;
				v_licenseplate = new char[strlen(tempLicence) + 1];
				strcpy(v_licenseplate, tempLicence);
			}

			read.getline(tempModel, 60, ',');

			//read.ignore(1, ',');

			//read up to 60 chars for model and dynamically store it
			//read.getline(v_model, 60, ',');
			read.getline(tempModel, 60, ',');

			if (read.fail())
			{
				delete[] v_model;
				v_model = nullptr;
			}

			else
			{
				delete[] v_model;
				v_model = nullptr;

				v_model = new char[strlen(tempModel) + 1];
				strcpy(v_model, tempModel);
			}

			//setMakeModel(v_model);
		}

		else
		{
			cout << "Enter Licence Plate Number: ";
			do
			{
				read.clear();
				read.ignore(100, '\n');
				read.getline(tempLicence, 10, '\n');

				for (unsigned int i = 0; i < strlen(tempLicence); i++)
				{
					tempLicence[i] = toupper(tempLicence[i]);
				}
				//v_licenseplate = new char[60];
				//read.get(v_licenseplate, 10);
				//read >> v_licenseplate;

				//deallocate
				delete v_licenseplate;
				v_licenseplate = nullptr;

				//dynamically allocate new memory
				v_licenseplate = new char[strlen(tempLicence) + 1];
				strcpy(v_licenseplate, tempLicence);

				//if (strlen(v_licenseplate) > 8)
				while (strlen(v_licenseplate) > 8 || strcmp(v_licenseplate, "") == 0 || read.fail())
				{
					read.clear();
					cout << "Invalid Licence Plate, try again: ";
					//read.ignore(100, '\n');
					read.getline(tempLicence, 10, '\n');

					delete[] v_licenseplate;
					v_licenseplate = nullptr;
					v_licenseplate = new char[strlen(tempLicence) + 1];
					strcpy(v_licenseplate, tempLicence);
					//read.getline(v_licenseplate, 10);
				}
			}
				while (strlen(v_licenseplate) > 8);

				cout << "Enter Make and Model: ";

				//v_model = new char[60];
				//read.clear();
				//read.ignore(100, '\n');

				do
				{
					read.getline(tempModel, 60, '\n');

					if (read.fail())
					{
						delete[] v_model;
						v_model = nullptr;
					}
					else
					{
						delete[] v_model;
						v_model = nullptr;
						v_model = new char[strlen(tempModel) + 1];
						strcpy(v_model, tempModel);
					}
					//read 2-60 chars. 
					if (strlen(v_model) < 2 || strlen(v_model) > 60)
					{
						//read.clear();
						//read.ignore(100, '\n');
						cout << "Invalid Make and model, try again: ";
						//read >> v_model;
					}
					
				}
				while (strlen(v_model) < 2 || strlen(v_model) > 60);
			
		}
		//check for istream obj fails while reading. set empty 
		if (read.fail()) { setEmpty(); }
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
			//write << v_pkspotNum << "," << v_licenseplate << "," << v_model;
			//updating
			write << v_pkspotNum << ",";
			write << v_licenseplate << ",";
			write << v_model << ",";
		}
		//if not comma separated mode then print message
		else if (this->isCsv() == false)
		{
			write << "Parking Spot Number: ";
			if (v_pkspotNum == 0) { write << "N/A" << endl; }
			else { write << v_pkspotNum << endl; }

			write << "Licence Plate: ";
			//for (int i = 0; i < 3; i++)
			for (unsigned int i = 0; i < strlen(v_licenseplate); i++)
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



}