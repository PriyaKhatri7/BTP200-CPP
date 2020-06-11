#ifndef ENGINEER_H
#define ENGINEER_H

#include "Doctor.h"
#include "Employee.h"


namespace sdds
{
	const int MIN_HOURS = 5; //check min working hrs
	const int MAX_LEVEL = 4; //check max level of engineer

	class Engineer : public Employee
	{
		double m_esalary; //sal of engineer
		int m_ewhours; //working hours of engineer
		int m_level; //level of engineer

	public:
		Engineer();
		Engineer(double, int, int);

		//redefine
		void setSalary(double);
		bool workHours();
		void bonus();
		std::ostream& display(std::ostream& os) const;
	};
}

#endif // !ENGINEER_H




