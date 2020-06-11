#ifndef SAIYAN_H
#define SAIYAN_H

#include <iostream>

using namespace std;

namespace sdds
{

	class Saiyan
	{
		//data members
		char m_name[30]; //holds name of Saiyan
		int m_dob; //year of birth. max year 2020
		int m_power; //stright of Saiyan, more than 0
		bool m_super; //Saiyan's ability. false = not achieved this ability yet

	public:
		//member functions
		bool isSuper() const; // returns the value of super.
		bool isValid()const; //returns true when the object is NOT in a safe empty state.
		void setEmpty(); //sets the object to a safe empty state.
		void display() const; //displays the Saiyan’s name and stats
		void set(const char* name, int dob, int power, bool super = false);
		bool hasLost(const Saiyan& other) const;

		//2 constructors
		Saiyan();
		Saiyan(const char* name, int dob, int power, bool super = false);
	};
}

#endif