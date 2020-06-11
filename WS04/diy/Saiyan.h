#ifndef SAIYAN_H
#define SAIYAN_H

#include <iostream>

using namespace std;

namespace sdds
{

	class Saiyan
	{
		//data members
		char* m_name; //
		int m_dob; //year of birth. max year 2020
		int m_power; //stright of Saiyan, more than 0
		bool m_super; //Saiyan's ability. false = not achieved this ability yet
		int m_level = 0; //valid if it's 0 or more

	public:
		//member functions
		bool isSuper() const; // returns the value of super.
		bool isValid()const; //returns true when the object is NOT in a safe empty state.
		void setEmpty(); //sets the object to a safe empty state.
		void display() const; //displays the Saiyan�s name and stats
		void set(const char* name, int dob, int power, int level = 0, bool super = false);
		bool hasLost(Saiyan& other);
		void powerup(); //power Saiyan if it has the abilities


		//2 constructors and a destructor
		Saiyan(); //updated! defining default constructor and a constructor that accepts param
		Saiyan(const char* name, int dob, int power, bool super = false);
		~Saiyan(); //destructor declared then defined in cpp
	};
}

#endif
