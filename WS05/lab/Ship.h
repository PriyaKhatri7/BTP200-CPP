#ifndef SDDS_SHIP_H
#define SDDS_SHIP_H
#include "Engine.h"

namespace sdds
{
	class Ship
	{
		Engine s_objEngine[10]; //up to 10 engines. An index of 1 is 1 engine
		char s_type[7];
		int s_numOfEngines;
		float s_distance;


	public:
		void setEmpty();
		bool empty() const;
		float calculatePower() const;
		void display() const;

		//constructors
		Ship();
		Ship(const char* type, Engine engine[], int length);


		//operators
		Ship& operator+=(const Engine& e);
		friend bool operator==(const Ship&, const Ship&); //friend operator
		
	};
	bool operator<(const Ship&, double); //free helper (outside class)
}


#endif // !SDDS_SHIP_H



