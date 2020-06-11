/*WS02 - In Lab
Name: Priya Khatri
Email: pkhatri4@myseneca.ca
Student number: 110149176
*/
#include <iostream>
#include <cstring>
#include "Gift.h"

using namespace std;

namespace sdds
{
	
	void gifting(char* acc_descrip)
	{
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> acc_descrip;
	}

	void gifting(double& acc_price)
	{
		acc_price = -1;
		while (acc_price == -1)
		{
			cout << "Enter gift price: ";
			cin >> acc_price;

			//if input is outside these parameters, output error message
			if (acc_price < 0 || acc_price > MAX_PRICE)
			{
				cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
				acc_price = -1;
			}
		}
	}

	void gifting(int& acc_units)
	{
		acc_units = 0;
		while (acc_units == 0)
		{
			cout << "Enter gift units: ";
			cin >> acc_units;

			if (acc_units < 1)
			{
				cout << "Gift units must be at least 1" << endl;
				acc_units = 0;
			}
		}
	}

	void display(const Gift& acc_Gift)
	{
		cout << "Gift Details:" << endl;
		cout << "Description: " << acc_Gift.g_description << endl;
		cout << "Price: " << acc_Gift.g_price << endl;
		cout << "Units: " << acc_Gift.g_units << endl;
	}

}




