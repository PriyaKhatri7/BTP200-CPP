#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include "Employee.h"



namespace sdds
{

	const int MIN_W_HOURS = 6; //check min working hrs
	const int MAX_CHAR = 20; //max length for doc's type (excluding nullbyte)

	class Doctor : public Employee
	{
		char m_type[MAX_CHAR + 1]; //type of doc
		double m_salary;
		int m_whours; //working hr of doc
		bool m_specialist = false; //optional. no val = false

	public:
		Doctor();
		Doctor(const char*, double, int, bool special = false);

		//have to redefine because in employee.h it is a pure virtual function
		void setSalary(double);
		bool workHours();
		void bonus();
		std::ostream& display(std::ostream& os) const;
	};

}


#endif // !DOCTOR_H





