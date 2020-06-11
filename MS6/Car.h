#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"
#include "ReadWritable.h"

namespace sdds
{

	//derived class
	class Car : public Vehicle
	{
		bool c_carwashflag; //had carwash or not
		char* v_model;
		char* vc_licenseplate;

	public:
		Car();
		Car(const char*, const char*);
		//prohibited copy and assign to another car
		Car(const Car&) = delete;
		Car& operator=(const Car&) = delete;

		std::istream& read(std::istream& read);
		std::ostream& write(std::ostream& write) const;

		~Car();
	};
}
#endif // !SDDS_CAR_H
