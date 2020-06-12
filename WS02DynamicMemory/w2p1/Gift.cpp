//WS02 - Part 1 | Name: Priya Khatri | Email: pkhatri4@myseneca.ca | Student number: 110149176

#include <iostream>
#include <iomanip>
#include "Gift.h"

using namespace std;

namespace sdds
{
	void gifting(char* desc)
	{
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1); //adjust the number characters to accept from user
		cin >> desc; //store in desc
	}

	void gifting(double& price)
	{
		price = -1;
		while (price == -1)
		{
			cout << "Enter gift price: ";
			cin >> price; //valid user number

			//validation checker
			if (price < 0 || price > MAX_PRICE)
			{
				cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
				price = -1;
			}
		}
		
	}

	void gifting(int& units)
	{
		units = 0;
		while (units == 0)
		{
			cout << "Enter gift units: ";
			cin >> units; //valid user number

			//checks if num is atleast 1
			if (units < 1)
			{
				cout << "Gift units must be at least 1" << endl;
				units = 0;
			}
		}
		
	}

	void display(const Gift& theGift)
	{
		cout << "Gift Details:" << endl;
		cout << " Description: " << theGift.m_description << endl;
		cout << "       Price: " << theGift.m_price << endl;
		cout << "       Units: " << theGift.m_units << endl;
	}
}