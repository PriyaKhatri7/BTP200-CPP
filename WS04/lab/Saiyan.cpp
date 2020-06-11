// Name: Priya Khatri, student number: 110149176, email: pkhatri4@myseneca.ca

#include <iostream>
#include <cstring>
#include "Saiyan.h"

using namespace std;

namespace sdds
{

	bool Saiyan::isSuper() const
	{
		if (m_super == true)
		{
			cout << "Super Saiyan Ability: Super Saiyan." << endl;
			
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
		m_name[0] = '\0';
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

	void Saiyan::set(const char* name, int dob, int power, bool super)
	{

		if (name != nullptr && name[0] != '\0' && dob < 2020 && power > 0)
		{
			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
		}
		else
		{
			setEmpty();
		}
	}

	bool Saiyan::hasLost(const Saiyan& other) const
	{
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
		setEmpty();
	}

	Saiyan::Saiyan(const char* name, int dob, int power, bool super)
	{
		set(name, dob, power, super);
	}
}
