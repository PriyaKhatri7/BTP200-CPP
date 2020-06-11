// Name: Priya Khatri, student number: 110149176, email: pkhatri4@myseneca.ca

#include <iostream>
#include <cstring>
#include "Saiyan.h"

using namespace std;

namespace sdds
{


	//multiple power by level only if they have super saiyan abilities
	void Saiyan::powerup() {
		if (m_level > 0)
		{
			this->m_power *= m_level + 1; 
		}
	}

	bool Saiyan::isSuper() const
	{
		if (m_super == true)
		{
			cout << "Super Saiyan Ability: Super Saiyan." << endl;
			cout << "Super Saiyan level is: " << this->m_level;
			
		}
		else
		{
			cout << "Super Saiyan Ability: Not super Saiyan." << endl;
			
		}
		return m_super;
	}

	bool Saiyan::isValid() const
	{
		if (m_name == nullptr || m_name[0] == '\0' || m_dob > 2020 || m_power < 0 )
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void Saiyan::setEmpty()
	{
		m_name = nullptr;
		m_dob = 0;
		m_power = 0;
		m_super = false;
		
	}

	void Saiyan::display() const
	{
		if (!isValid())
		{
			cout << "Invalid Saiyan!" << endl;
		}
		else
		{
			cout << this->m_name << endl;
			cout << "DOB: " << this->m_dob << " Power: " << this->m_power << endl;
			this->isSuper();
			cout << endl;
		}
	}

	void Saiyan::set(const char* name, int dob, int power, int level, bool super)
	{

		if (name != nullptr && name[0] != '\0' && dob < 2020 && power > 0)
		{
			m_name = new char[strlen(name)+1]; //allocates dynamic memory

			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
			m_level = level;
		}
		else
		{
			setEmpty();
		}
	}

	bool Saiyan::hasLost(Saiyan& other)
	{
		this->powerup();
		other.powerup();

		if (this->m_power > other.m_power || !isValid())
		{
			return false;
		}
		else
		{
			
			return true;
		}

	}

	//constructor
	Saiyan::Saiyan()
	{
		setEmpty(); //default constructor should be an empty state
	}

	Saiyan::Saiyan(const char* name, int dob, int power, bool super)
	{
		set(name, dob, power, super);
	}

	Saiyan::~Saiyan() //destructor
	{
		delete[] m_name;

	}
}
