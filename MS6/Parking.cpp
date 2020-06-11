#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "Car.h"
#include "Menu.h"
#include "Motorcycle.h"
#include "Parking.h"
#include "ReadWritable.h"
#include "Vehicle.h"

using namespace std;

namespace sdds
{
	//default. set to empty state
	Parking::Parking()
	{
		p_numofparkingspots = 0;
		
		for (int i = 0; i < MAX_NUM_PARKING_SPOTS; i++)
		{
			p_parkingspots[i] = nullptr;
		}

		p_numofparkedV = 0;
		p_numofavaspots = 0;
		p_datafile = nullptr;
		m_parkingmenu = nullptr;
		m_vehiclemenu = nullptr;


	}

	Parking::Parking(const char* datafile, int noOfSpots)
	{
		if ((datafile != nullptr && strlen(datafile) > 0) && (noOfSpots >= 10 && noOfSpots < MAX_NUM_PARKING_SPOTS))
		{
			//set values
			p_datafile = new char[strlen(datafile) + 1];
			strcpy(p_datafile, datafile);

			p_numofparkingspots = noOfSpots;

			for (int i = 0; i < MAX_NUM_PARKING_SPOTS; i++)
			{
				p_parkingspots[i] = nullptr;
			}
		}
		else { setEmpty(); }

		if (loadDataFile()) //loading menu
		{
			m_parkingmenu = new Menu("Parking Menu, select an action:", 0);
			m_parkingmenu->add("Park Vehicle");
			m_parkingmenu->add("Return Vehicle");
			m_parkingmenu->add("List Parked Vehicles");
			m_parkingmenu->add("Close Parking (End of day)");
			m_parkingmenu->add("Exit Program");

			m_vehiclemenu = new Menu("Select type of the vehicle:", 1);
			m_vehiclemenu->add("Car");
			m_vehiclemenu->add("Motorcycle");
			m_vehiclemenu->add("Cancel");
		}
		else {
			cout << "Error in data file" << endl;
			setEmpty();
		}
	}

	int Parking::run()
	{
		int select;
		bool exitapp = false;

		if (!isEmpty())
		{
			while (exitapp == false)
			{
				this->parkingMenu();

				cin >> select;

				if (select == 1)
				{
					this->parkVehicle();
				}

				if (select == 2)
				{
					this->returnVehicles();
				}

				if (select == 3)
				{
					this->listParkedVehicles();
				}

				if (select == 4)
				{
					if (closeParking() == true)
					{
						return 0;
					}

				}

				if (select == 5)
				{
					if (exitParkingApp() == true)
					{
						cout << "Exiting program!" << endl;
						return 0;
					}

				}
			}
			return 0;
		}

		else{ return 1; }



	}

	Parking::~Parking()
	{
		saveDataFile();
		delete[] p_datafile;
		p_datafile = nullptr;
	}

	//set empty
	void Parking::setEmpty()
	{
		p_datafile = nullptr;

		for (int i = 0; i < MAX_NUM_PARKING_SPOTS; i++)
		{
			p_parkingspots[i] = nullptr;
		}

		m_parkingmenu = nullptr;
		m_vehiclemenu = nullptr;
		p_numofparkedV = 0;
		p_numofparkingspots = 0;
		p_numofavaspots = 0;
	}

	//same as MS2
	bool Parking::isEmpty() const
	{
		if (p_datafile == nullptr) { return true; }
		else { return false; }
	}

	//doesn't receive or return. just print message and format it
	void Parking::parkingStatus() const
	{

		cout << "****** Seneca Valet Parking ******\n";
		cout << "*****  Available spots: ";
		cout.width(4);
		cout << left << (p_numofparkingspots - p_numofparkedV) << " *****" << endl;
		cout.unsetf(ios::left);

		m_parkingmenu->display();
	}

	void Parking::parkVehicle()
	{
		//if no spots then print function nad exit
		if (p_numofparkedV == p_numofparkingspots) { cout << "Parking is full" << endl; }

		bool avaspots = false;
		if (p_numofparkingspots > p_numofparkedV) { avaspots = true; }
		
		//user input, no spots avaliable
		int select, naSpots = -1; 
		bool pkspot = false; //checking for is the spot if able to park in

		if (avaspots)
		{
			//otherwise display vehicle selection menu
			m_vehiclemenu->display();
			cin >> select;

			for (int i = 0; i < p_numofparkingspots; i++)
			{
				if (p_parkingspots[i] == nullptr)
				{
					naSpots = i;
					break;
				}
			}

			//if user selects option 1
			if (select == 1)
			{
				//dynamically create an instance of car
				Vehicle* tmp = new Car;
				tmp->setCsv(false);
				tmp->read(cin);

				//if it's not set to be in comma separated mode then print can't park message
				//after getting this info it will search the parking spots array and 
				//find the first available spot. set that to Vehicle pointer.
				for (int i = 0; i < p_numofparkingspots; i++)
				{
					if (p_parkingspots[i] == tmp)
					{
						pkspot = true;
						break;
					}
				}
				if (pkspot)
				{
					cout << "Can not park; license plate already in the system!" << endl;
					delete tmp;
				}
				else
				{
					//also set the vehicle spot num and print it with the message
					//then print the vehicle
					p_parkingspots[naSpots] = tmp;
					p_parkingspots[naSpots]->setParkingSpot(naSpots + 1);
					cout << endl;
					cout << "Parking Ticket" << endl;
					cout << *p_parkingspots[naSpots];
					cout << endl;
					p_numofparkedV++;
				}
			}

			//same for option 2 

			//next selection for user if selected
			if (select == 2)
			{
				//dynamically create an instance of motorcycle pointer
				Vehicle* tmp = new Motorcycle;

				//if it's not set to be in comma separated mode then print can't park message
				tmp->setCsv(false);
				tmp->read(cin);

				for (int i = 0; i < p_numofparkingspots; i++)
				{
					if (p_parkingspots[i] == tmp)
					{
						pkspot = true;
						break;
					}
				}

				if (pkspot)
				{
					cout << "Can not park; license plate already in the system!" << endl;
					delete tmp;
				}
				else
				{
					p_parkingspots[naSpots] = tmp;
					p_parkingspots[naSpots]->setParkingSpot(naSpots + 1);
					cout << endl;
					cout << "Parking Ticket" << endl;
					cout << *p_parkingspots[naSpots];
					cout << endl;
					p_numofparkedV++;
				}
			}
			//selection 3 is cancelled parking. print message
			if (select == 3)
			{
				cout << "Parking cancelled" << endl;
			}
		}
	}

	void Parking::returnVehicles()
	{
		cin.clear(); //clear before
		cin.ignore(100, '\n');
		cout << "Return Vehicle" << endl;

		char tmpLicense[10]; //user input for license

		//ask user for license plate
		cout << "Enter Licence Plate Number: ";
		cin.get(tmpLicense, 10, '\n');

		//if the lenght of the license plate is more than 8 then it will not print
		//saying invalid message below
		while (strlen(tmpLicense) > 8)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid Licence Plate, try again: ";
			cin.get(tmpLicense, 10, '\n');
		}
		//and should try to repeat to ask the user until a valid input is entered

		for (unsigned int i = 0; i < strlen(tmpLicense); i++)
		{
			tmpLicense[i] = toupper(tmpLicense[i]);
		}

		bool equal = false;
		//search for parked vehicles for matching licence plate
		for (int i = 0; i < p_numofparkedV; i++)
		{
			//if license plate is found then it will print the vehicle
			if (*p_parkingspots[i] == tmpLicense)
			{
				p_parkingspots[i]->setCsv(false);
				cout << "\nReturning: " << endl;
				cout << *p_parkingspots[i] << endl;

				//then delete vehicle from memory
				delete p_parkingspots[i];

				//set parking spot to null
				p_parkingspots[i] = nullptr;
				p_numofparkedV--;

				equal = true;
			}
		}
		if (equal == false)
		{
			cout << "License plate " << tmpLicense << " Not found" << endl;
			equal = true;
		}
	}

	void Parking::listParkedVehicles() const
	{
		cout << "*** List of parked vehicles ***" << endl;

		//checks throug all parking spot elements of parking and print that they are 
		//not empty. format.
		for (int i = 0; i < p_numofparkingspots; i++)
		{
			if (p_parkingspots[i] != nullptr)
			{
				this->p_parkingspots[i]->setCsv(false);
				this->p_parkingspots[i]->write(cout);
				cout << "-------------------------------" << endl;
			}
		}
	}

	bool Parking::closeParking()
	{
		//if parking is empty return true
		if (isEmpty()) //
		{
			cout << "Closing Parking" << endl;
			return true;
		}
		else
		{
			char select = '\0';
			bool exitapp = false;
			//otherwise print ,essage for user and wait for reply
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			cin >> select;

			while (exitapp == false)
			{

				if ((select == 'Y' || select == 'y'))
				{
					cout << "Closing Parking" << endl;
					cout << endl;

					for (int i = 0; i < p_numofparkingspots; i++)
					{
						if (p_parkingspots[i] != nullptr)
						{
							//print the towing ticket
							cout << "Towing request" << endl;
							cout << "*********************" << endl;

							//prints the vehicle and skips a line
							p_parkingspots[i]->setCsv(false);
							p_parkingspots[i]->write(cout);

							//deletes the vehicle and sets the parking spot to null
							delete p_parkingspots[i];
							p_parkingspots[i] = nullptr;
							
							//removed from parking
							p_numofparkedV--;
						}
						if (p_parkingspots[i + 1] != nullptr)
						{
							cout << endl;
						}

					}
					exitapp = true;
					return true;
				}
				//user said no. return false and exit function
				else if ((select == 'N' || select == 'n'))
				{
					cout << "Aborted!" << endl;
					exitapp = true;
					return false;
				}
				else
				{
					//if the user has invalid response. ask again until it meets requirements
					cin.clear();
					cin.ignore(9000, '\n');
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					cin >> select;
				}

			}

			cin.clear();
			return false;

		}
	}

	bool Parking::loadDataFile()
	{
		p_numofavaspots = 10;
		p_numofparkedV = 0;
		bool quit = true;
		//if it's not invalid then use an instance of ifstream class. open file
		//named in the Filename member variable
		if (!isEmpty())
		{
			//if ifstream is in a good state, then have a pointer of type vehicle...
			std::ifstream f;
			f.open(p_datafile, ios::in);

			if (f.is_open())
			{
				
				do
				{
					//read 1 char from file and ignore the next
					Vehicle* tmp = nullptr;

					char type = '0';
					f >> type;

					if (type == 'M')
					{
						//create dynamic instance of motorcycle
						tmp = new Motorcycle;
					}
					else if (type == 'C')
					{
						//dynamic for car
						tmp = new Car;
					}

					type = '0';

					if (tmp != nullptr && p_numofparkedV < p_numofparkingspots)
					{

						tmp->setCsv(true);
						tmp->read(f);

						if (f.fail())
						{
							f.clear();
							delete tmp;
							tmp = nullptr;
							quit = false;
						}
						else
						{
							p_parkingspots[tmp->getParkingSpot() - 1] = tmp;
							p_numofparkedV++;
							p_numofparkedV++;
							p_numofavaspots--;
						}
					}
				} 
				while (quit == true && !f.eof());
			}
		}
		return quit;
	}

	void Parking::saveDataFile() const
	{
		if (!isEmpty())
		{
			std::fstream fOut;
			fOut.open(p_datafile, ios::out);
			fOut.seekp(ios::beg);

			if (fOut.is_open())
			{
				for (int i = 0; i < p_numofparkedV; i++)
				{
					if (p_parkingspots[i] != nullptr)
					{
						p_parkingspots[i]->setCsv(true);
						p_parkingspots[i]->write(fOut);
					}
				}

				fOut.close();
			}
		}
		cin.ignore(100, '\n');
		cin.clear();
	}

	//Same as MS2
	bool Parking::exitParkingApp() const
	{
		bool exitapp = false; 
		bool check = false;
		char select = '\0';

		cout << "This will terminate the program!\n";
		cout << "Are you sure? (Y)es/(N)o: ";
		cin >> select;

		while (exitapp == false)
		{

			if ((select == 'Y' || select == 'y'))
			{
				exitapp = true;
				check = true;
			}
			else if ((select == 'N' || select == 'n'))
			{
				exitapp = true;
				check = false;
			}
			else
			{
				cin.clear();
				cin.ignore(9000, '\n');
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				cin >> select;
			}
		}
		cin.clear();
		return check;
	}

	void Parking::parkingMenu() const
	{
		parkingStatus();
	}

}