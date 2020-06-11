#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H

#include "ReadWritable.h"
#include "Vehicle.h"

namespace sdds
{
	//derive class from Vehicle
	class Motorcycle : public Vehicle
	{
		bool m_sidecarFlag; //if it has a sidecar attached or not
		char* vm_licenseplate;
		char* vm_model;

	public:
		Motorcycle();
		Motorcycle(const char*, const char*); //const char* because we're using license plate and model
		~Motorcycle();

		//cannot copy or assign to another Motorcycle. prohibted 
		Motorcycle(const Motorcycle&) = delete;
		Motorcycle& operator=(const Motorcycle&) = delete;

		std::istream& read(std::istream& read);
		std::ostream& write(std::ostream& write) const;

		
	};



}

#endif // !SDDS_MOTORCYCLE_H
