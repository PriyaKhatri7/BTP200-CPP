#include <iostream>
#include <iomanip> //setprecision
#include <cstring>
#include "Ship.h"

using namespace std;

namespace sdds
{
	

	bool Ship::empty() const
	{
		if ((s_objEngine < 0 && s_type == nullptr) && (s_numOfEngines == 0) && (s_distance == 0.0))
		{
			return true; //returns true if object is in a safe empty state
		}
		else
		{
			return false;
		}
	}

	float Ship::calculatePower() const
	{
		float outputEngPower = 0.0;
		float sumEngine = 0.0;
		for (int i = 0; i < s_numOfEngines; i++)
		{
			//Do math here. engine size times 5.
			sumEngine = float(this->s_objEngine[i].get() * 5);
			outputEngPower += sumEngine;
		}
		return outputEngPower;
	}

	void Ship::display() const
	{
		if (this->s_type == nullptr)
		{
			cout << "No available data" << endl;
		}
		else
		{
			cout << fixed;
			cout << setprecision(2);
			cout << s_type << "-" << setw(6) << this->calculatePower() << endl;

		}
		for (int i = 0; i < s_numOfEngines; i++)
		{
			s_objEngine[i].display();
		}
	}



	Ship::Ship()
	{
		s_objEngine = nullptr;
		s_type = nullptr;
		s_numOfEngines = 0;
		s_distance = 0.0;
	}

	Ship::Ship(const char* type, Engine engine[], int length)
	{
		if (type != nullptr && engine > 0)
		{
			s_type = new char[strlen(type) + 1];
			strcpy(s_type, type);
			s_objEngine = new Engine[length];
			for (int i = 0; i < length; i++)
			{
				s_objEngine[i] = engine[i];
			}
			s_numOfEngines = length;
			s_distance = 0;
		}
		else
		{
			s_objEngine = nullptr;
			s_type = nullptr;
			s_numOfEngines = 0;
			s_distance = 0.0;
		}
	}

	Ship::~Ship()
	{
		delete[] s_objEngine;
		s_objEngine = nullptr;

		delete[] s_type;
		s_type = nullptr;
	}

	Ship& Ship::operator+=(const Engine& e)
	{
		//numOfEngines < maximum numOfEngines allowed and shipType is valid
		if (s_numOfEngines != 0 && s_type != nullptr)
		{
			//create new array
			Engine* tmpSize = new Engine[s_numOfEngines + 1];

			for (int i = 0; i < s_numOfEngines; i++)
			{
				tmpSize[i] = s_objEngine[i]; //copying 1 element at a time
			}
			
			tmpSize[s_numOfEngines] = e;
			s_numOfEngines++;//then update the count

			delete[] s_objEngine; //deallocate old memory

			s_objEngine = tmpSize;
		}
		else
		{
			cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
			this->~Ship(); //call destructor and cleanup memory
		}

		return *this;

	}

	bool operator==(const Ship& s1, const Ship& s2)
	{
		//2 ships have the exact same power: return true
		if (s1.calculatePower() == s2.calculatePower())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<(const Ship& s1, double s2)
	{
		//returns true when total power of ship is below the value provided
		if (s1.calculatePower() < s2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}
