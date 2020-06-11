#include <iostream>
#include <iomanip> //setprecision
#include <cstring> //strcpy
#include "Doctor.h"
#include "Employee.h"

using namespace std;

namespace sdds
{

	//Default. Set safe empty
	Doctor::Doctor()
	{
		m_type[MAX_CHAR] = '\0';
		m_salary = 0.0;
		m_whours = 0;
		m_specialist = false;
	}

	//4-arg constructor
	Doctor::Doctor(const char* type, double sal, int whrs, bool special) : Doctor()
	{
		if ((sal > 0.0) && (whrs > 0))
		{
			//set member variables except m_salary
			//m_type = new char[strlen(type) + 1];
			strcpy(this->m_type, type);
			this->m_whours = whrs;
			this->m_specialist = special;

			//use setSalary() to set the value of m_salary
			setSalary(sal);
		}
		else //if (m_whours <= 0 || m_salary <= 0)
		{
			this->m_whours = 0;
			this->m_salary = 0.0;
		}
	}

	//public members
	//sets salary based on type of doc
	void Doctor::setSalary(double dsal)
	{
		//making this true means doc is a specialist
		if (m_specialist == true)
		{
			m_salary = dsal + 2000.00;
		
		}
		else
		{
			m_salary = dsal;
		}
		
	}

	//returns true if a doc is working for min_w_hours
	bool Doctor::workHours() 
	{
		if (m_whours >= MIN_W_HOURS)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//calcs bonus and adds to sal
	void Doctor::bonus()
	{

		if (m_whours > MIN_W_HOURS)
		{
			m_salary = this->m_salary + (this->m_salary * 0.10);
		}
		else
		{
			m_salary = this->m_salary + (this->m_salary * 0.05);
		}
	}

	//display all details
	std::ostream& Doctor::display(std::ostream& os) const
	{
		if ((this->m_salary > 0.0) && (this->m_whours > 0))
		{
			os << "Doctor details\n";
			os << "Doctor Type: " << this->m_type << "\n";
			os << fixed << setprecision(2) << "Salary: " << this->m_salary << "\n";
			os << "Working Hours: " << this->m_whours << "\n";
		}
		//if (Doctor())
		if((this->m_type[MAX_CHAR] == '\0') && (this->m_salary == 0.0) && (this->m_whours == 0) && (this->m_specialist == false))
		{
			os << "Doctor is not initiated yet\n";
			
		}
		return os;
	}

}
