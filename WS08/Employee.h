#include <iostream>
#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

namespace sdds
{
	class Employee {
		public:
			virtual void setSalary(double) = 0;
			virtual void bonus() = 0; //calc bous for each emp
			virtual bool workHours() = 0; // true is employee is working for min hours
			virtual std::ostream& display(std::ostream& os) const = 0; 

			virtual ~Employee() = default;
	};

}

#endif

/*
Notes:
- abstract only based class
- only public pure virtual functions (keyword: virtual)
- only header, no implementation

*/
