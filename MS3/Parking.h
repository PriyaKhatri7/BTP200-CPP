#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H
#include "Menu.h"

namespace sdds
{
	class Parking
	{
		char* p_filename; //hold data file name of app
		Menu* p_menu; //Menu type. show type of parking menu
		Menu* vp_menu; //Menu type. Will show type of vehicle 


		bool isEmpty() const; //true if parking is invalid. false is parking is valid
		void ParkingStatus() const; //only prints message
		void ParkVehicles() const;
		void ReturnVehicles() const; //only prints message
		void ListParkedVehicles() const;
		bool CloseParking() const;
		bool ExitParking() const;
		bool LoadDataFile() const;
		void SaveDataFile() const;
		void ParkingMenu() const;
		void setEmpty();
		Parking& operator=(const Parking&) = delete; //copying prohibited
		Parking(const Parking&) = delete; //copying prohibited

	public:
		Parking();
		Parking(const char*);
		~Parking();
		int run();

	};
}
#endif // !SDDS_PARKING_H