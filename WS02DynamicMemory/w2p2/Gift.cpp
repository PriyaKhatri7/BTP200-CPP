//WS02 - Part 2 | Name: Priya Khatri | Email: pkhatri4@myseneca.ca | Student number: 110149176

#include <iostream>
#include <cstring> //strlen
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

	bool wrap(Gift& theGift)
	{
		char pattern[MAX_WRAP + 1];
		int patternlen;

		while (theGift.m_wrapLayers != 0) //err if m_wrapLayers = 0. the gift is already wrapped!
		{
			cout << "Gift is already wrapped!" << endl;
			return false;
		}
		
		theGift.m_wrapLayers = 0; //setting 

		cout << "Wrapping gifts..." << endl;
		
		while (theGift.m_wrapLayers == 0) //while no layers of gift wrap enter the loop
		{
			cout << "Enter the number of wrapping layers for the Gift: ";
			cin >> theGift.m_wrapLayers; //ask user for # of layers for current Gift

			//make user keep trying until valid
			if (theGift.m_wrapLayers < 1)
			{
				cout << "Layers at minimum must be 1, try again." << endl;
				theGift.m_wrapLayers = 0; //set to 0 so user has to try again
			}
		}

		//R.S assigns to L.S when allocating memory
		theGift.m_wrap = new Wrapping[theGift.m_wrapLayers]; //allocate dynamic memory to store # of layers in gift
		for (int i = 0; i < theGift.m_wrapLayers; i++) //loop for X layer
		{
			cout << "Enter wrapping pattern #" << i + 1 << ": ";
			cin >> pattern;

			patternlen = strlen(pattern);

			//allocate memory and validation loops
			if (patternlen < MAX_WRAP)
			{
				theGift.m_wrap[i].m_pattern = new char[patternlen + 1];
				strcpy(theGift.m_wrap[i].m_pattern, pattern);
			}
		}
		return true;
	}

	bool unwrap(Gift& theGift)
	{
		while (theGift.m_wrapLayers > 0)
		{
			cout << "Gift being unwrapped." << endl;
			theGift.m_wrapLayers = 0;
			theGift.m_wrap = nullptr;

			return true;
		}
		delete theGift.m_wrap;
		theGift.m_wrap = nullptr;

		while (theGift.m_wrapLayers <= 0)
		{
			cout << "Gift isn't wrapped! Cannot unwrap." << endl;
			return false;
		}
		return true;
	}

	void gifting(Gift& theGift)
	{
		cout << "Preparing a gift..." << endl;

		//uses previous gifting functions to get specified parts for the gift
		gifting(theGift.m_description);
		gifting(theGift.m_price);
		gifting(theGift.m_units);

		//attempts to wrap the gift if possible
		wrap(theGift);

	}

	void display(const Gift& theGift)
	{

		if (theGift.m_wrap == nullptr)
		{
			cout << "Gift Details:" << endl;
			cout << " Description: " << theGift.m_description << endl;
			cout << "       Price: " << theGift.m_price << endl;
			cout << "       Units: " << theGift.m_units << endl;
			cout << "Unwrapped!" << endl;
		}
		else
		{
			cout << "Gift Details:" << endl;
			cout << " Description: " << theGift.m_description << endl;
			cout << "       Price: " << theGift.m_price << endl;
			cout << "       Units: " << theGift.m_units << endl;
			cout << "Wrap Layers: " << theGift.m_wrapLayers << endl;
			for (int i = 0; i < theGift.m_wrapLayers; i++)
				cout << "Wrap #" << i + 1 << " -> " << theGift.m_wrap[i].m_pattern << endl;
		}
	}

}