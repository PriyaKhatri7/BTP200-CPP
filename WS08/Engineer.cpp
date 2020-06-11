#include <iostream> //std
#include <iomanip> //setprecision
#include "Engineer.h"
//#include "Employee.h"


using namespace std;

namespace sdds
{
	//set to empty
	Engineer::Engineer()
	{
		m_esalary = 0.0;
		m_ewhours = 0; 
		m_level = 0;
	}

	//3 arg constructor
	Engineer::Engineer(double eSal, int eHours, int eLevel)
	{
		if ((eSal > 0.0) && (eHours > 0) && (eLevel > 0))
		{
			//set the objects
			m_esalary = eSal;
			m_ewhours = eHours;
			m_level = eLevel;
			//set sal of engineer
			setSalary(eSal);
		}
		else //set empty
		{
			m_esalary = 0.0;
			m_ewhours = 0; 
			m_level = 0;

		}
	}

	void Engineer::setSalary(double esal)
	{
		//set level of engineer if it equals max_level
		if (m_level == MAX_LEVEL)
		{
			m_esalary = esal + 3000.00;
		}
		else //set to incoming argument with no change.
		{
			m_esalary = esal;
		}
	}

	bool Engineer::workHours()
	{
		//engineer is working for min_hours
		if(m_ewhours == MIN_HOURS)
		{
			return true;
		}
		else {
			return false;
		}
	}

	void Engineer::bonus()
	{

		if ((m_ewhours >= MIN_HOURS) && (m_level == MAX_LEVEL))
		{
			m_esalary = this->m_esalary + (this->m_esalary * 0.10);
		}
		else
		{
			m_esalary = this->m_esalary + (this->m_esalary * 0.05);
		}

	}

	ostream& Engineer::display(ostream& os) const
	{
		if ((this->m_esalary > 0.0) && (this->m_ewhours > 0))
		{
			os << "Engineer details" << "\n";
			os << "level: " << this->m_level << "\n";
			os << fixed << setprecision(2) << "Salary: " << this->m_esalary << "\n";
			os << "Working hours: " << this->m_ewhours << "\n";
		}
		else
		{
			os << "Engineer is not initiated yet\n";
		}
		return os;
	}




}

