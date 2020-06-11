#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

#include <iostream>
#include "ReadWritable.h"

namespace sdds
{
	//deriving class
	class Vehicle : public ReadWritable
	{
		char* v_licenseplate;
		char* v_model;
		int v_pkspotNum;

	public:
		Vehicle();
		Vehicle(const char*, const char*);
		//cannot copy or assign to another vehicle. prohibted 
		Vehicle(const Vehicle&) = delete;
		Vehicle& operator=(const Vehicle&) = delete;
		~Vehicle();

		int getParkingSpot() const;
		void setParkingSpot(int);
		bool operator==(const char*) const;
		bool operator==(const Vehicle&) const;
		std::istream& read(std::istream& read);
		std::ostream& write(std::ostream& write) const;

	protected:
		void setEmpty();
		bool isEmpty() const;
		std::istream& getLicensePlate(std::istream&) const;
		std::istream& getMakeModel(std::istream&) const;
		void setMakeModel(const char*);

	};

}


#endif // !SDDS_VEHICLE_H

