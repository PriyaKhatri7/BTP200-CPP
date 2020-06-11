#ifndef PARKING_H
#define PARKING_H
#include "Menu.h"
#include "Vehicle.h"

namespace sdds
{
	const int MAX_NUM_PARKING_SPOTS = 100;

	class Parking
	{
		int p_numofparkingspots; //value is always less than MAX_NUM_PARKING_SPOTS const val. number of spots
		Vehicle* p_parkingspots[MAX_NUM_PARKING_SPOTS]; //acts like a parking spots in parking
		int p_numofparkedV; //parked vehicles in parking. Always less then number of spots
		char* p_datafile;
		Menu* m_parkingmenu;
		Menu* m_vehiclemenu;
		int p_numofavaspots;


		//members
		void setEmpty();
		bool isEmpty() const;
		void parkingStatus() const;
		void parkVehicle();
		void returnVehicles();
		void listParkedVehicles() const;
		bool closeParking();
		bool loadDataFile();
		void saveDataFile() const;
		bool exitParkingApp() const;
		void parkingMenu() const;
		Parking& operator=(const Parking&) = delete;
		Parking(const Parking&) = delete;

	public:
		Parking();
		Parking(const char*, int);
		int run();
		~Parking();
		

	};
}

#endif // !PARKING_H

