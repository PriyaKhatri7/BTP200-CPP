#include <iostream>
#include <cstring> //strcpy
#include "Parking.h"
#include "Menu.h"

using namespace std;

namespace sdds
{
	//default constructor
	Parking::Parking()
	{
		p_filename = nullptr;
		p_menu = nullptr;
		vp_menu = nullptr;
	}

	Parking::Parking(const char* file)
	{
		if (file != nullptr && strlen(file) > 0)
		{
			p_filename = new char[strlen(file) + 1];
			strcpy(p_filename, file);
		}
		else {
			setEmpty();
		}


		if (LoadDataFile()) //loading menu
		{
			p_menu = new Menu("Parking Menu, select an action:", 0);
			p_menu->add("Park Vehicle");
			p_menu->add("Return Vehicle");
			p_menu->add("List Parked Vehicles");
			p_menu->add("Close Parking (End of day)");
			p_menu->add("Exit Program");

			vp_menu = new Menu("Select type of the vehicle:", 1);
			vp_menu->add("Car");
			vp_menu->add("Motorcycle");
			vp_menu->add("Cancel");
		}
		else {
			cout << "Error in data file" << endl;
			setEmpty();
		}
	}

	Parking::~Parking()
	{
		SaveDataFile();
		delete[] p_filename;
		p_filename = nullptr;
	}

	//runs the whole Parking Application 
	int Parking::run()
	{
		int select; bool exitapp = false; //set to use in this function

		if (!isEmpty())
		{
			while (exitapp == false)
			{
				ParkingMenu();
				cin >> select; //user

				//just because it takes up less lines /shrug
				if (select == 1) { ParkVehicles(); }
				if (select == 2) { ReturnVehicles(); }
				if (select == 3) { ListParkedVehicles(); }
				if (select == 4)
				{
					CloseParking();
					break;
				}
				if (select == 5)
				{
					if (ExitParking() == true)
					{
						cout << "Exiting program!" << endl;
						return 0;
					}
				}
			} return 0; //return statement
		}
		else { return 1; }
	}

	//set empty state
	bool Parking::isEmpty() const
	{
		if (p_filename == nullptr) //&& p_menu == nullptr && vp_menu == nullptr)
		{
			return true;
		}
		else {
			return false;
		}

	}
	//returns nothing and only prints message
	void Parking::ParkingStatus() const
	{
		cout << "****** Seneca Valet Parking ******" << endl;
		p_menu->display(); //
	}

	void Parking::ParkVehicles() const
	{
		int select = 0;
		vp_menu->display();
		cin >> select;

		if (select == 1)
		{
			cout << "Parking Car" << endl;
		}

		if (select == 2)
		{
			cout << "Parking Motorcycle" << endl;
		}

		if (select == 3)
		{
			cout << "Cancelled parking" << endl;
		}
	}

	//only prints message
	void Parking::ReturnVehicles() const
	{
		cout << "Returning Vehicle" << endl;
	}

	//only prints message
	void Parking::ListParkedVehicles() const
	{
		cout << "Listing Parked Vehicles" << endl;
	}

	//only returns message
	bool Parking::CloseParking() const
	{
		cout << "Closing Parking" << endl;
		return true;
	}

	//return true if user's res is yes and false is user's says no
	bool Parking::ExitParking() const
	{
		bool userinput, exitapp = false;
		char select[10]; //supports arr 10 

		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		cin.getline(select, 3);

		while (exitapp == false)
		{
			//if user enters y. not case sensitive
			if ((select[0] == 'y' || select[0] == 'Y') && (select[1] == '\0'))
			{
				exitapp = true;
				userinput = true;
			}
			//if user enters n. not case sensitive
			else if ((select[0] == 'n' || select[0] == 'N') && (select[1] == '\0'))
			{
				exitapp = true;
				userinput = false;
			}
			else { //repeats asking user if invalid response
				cin.clear();
				cin.ignore(9000, '\n');
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				cin >> select;
			}
		}
		return userinput; //returns user input
	}

	bool Parking::LoadDataFile() const
	{
		//if not invalid then print message and data file
		if (!isEmpty())
		{
			cout << "loading data from " << p_filename << endl;
			return true;
		}
		else
			return false;
	}

	void Parking::SaveDataFile() const
	{
		//invalid state prints message and the name of data file
		if (!isEmpty())
		{
			cout << "Saving data into " << p_filename << endl;
		}
	}

	void Parking::ParkingMenu() const
	{
		ParkingStatus();
	}

	void Parking::setEmpty()
	{
		p_filename = nullptr;
		p_menu = nullptr;
		vp_menu = nullptr;
	}
}