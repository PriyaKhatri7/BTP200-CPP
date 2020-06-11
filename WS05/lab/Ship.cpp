#include <iostream>
#include <iomanip> //setprecision
#include <cstring>
#include "Ship.h"

using namespace std;

namespace sdds
{
	bool Ship::empty() const
	{
		if ((s_objEngine < 0 && s_type[0] == '\0') && (s_numOfEngines == 0) && (s_distance == 0.0))
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
			//Do math here
			sumEngine = float(this->s_objEngine[i].get() * 5);//engine size times 5. also have to create a new function for total output
			outputEngPower += sumEngine; 
		}
		//set return value
		return outputEngPower;
	}

	void Ship::display() const
	{
		if (this->s_type[0] == '\0')
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
		/*for (int i = 0; i < 10; i++)
		{
			s_objEngine[i].setEmpty();
		}*/

		s_type[0] = '\0';
		s_numOfEngines = 0;
		s_distance = 0.0;
	}

	Ship::Ship(const char* type, Engine engine[], int length)
	{
		//if (type != nullptr && strlen(type) <= 6 && length > 0)
		
			strcpy(s_type, type);
			for (int i = 0; i < length; i++)
			{
				s_objEngine[i] = engine[i];
			}
			s_numOfEngines = length;
			s_distance = 0;

		
		//else
		
			//setEmpty();
		
	}

	Ship& Ship::operator+=(const Engine& e)
	{
		//numOfEngines < maximum numOfEngines allowed and shipType is valid
		if (s_numOfEngines <= 10 && this->s_type[0] != '\0')
		{
			s_objEngine[s_numOfEngines] = e;
			s_numOfEngines++;
		}
		else
		{
			cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
		}
		return *this;
	}

	bool operator==(const Ship& s1, const Ship& s2)
	{
		//2 ships have the exact same power
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
