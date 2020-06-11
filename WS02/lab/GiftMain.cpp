/***********************************************************************
// BTP200 Workshop 2: Dynamic Memory & Function Overloading
// File GiftMain.cpp
// Version 1.0
// Date 2020/01/05
// Author Michael Huang
// Description
// Tests Gift module and provides a set of TODOs to complete
// which the main focuses are dynamic memory allocation
//
// Revision History
// -----------------------------------------------------------
// Name Date Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Gift.h"
#include "Gift.h" // Intentional
using namespace std;
using namespace sdds;

int main() {
	int numberOfGifts = 0; // Initial number of Gifts

	Gift* gGift = nullptr;

	cout << "Enter number of Gifts to allocate: ";
	cin >> numberOfGifts;

	if (numberOfGifts < 1) return 1;

	gGift = new Gift[numberOfGifts];

	for (int i = 0; i < numberOfGifts; ++i) {
		cout << "Gift #" << i + 1 << ": " << endl;

		gifting(gGift[i].g_description);

		cin.ignore(2000, '\n'); // clear input buffer

		gifting(gGift[i].g_price);

		cin.ignore(2000, '\n'); // clear input buffer

		gifting(gGift[i].g_units);

		cin.ignore(2000, '\n');
		cout << endl;
	}

	for (int i = 0; i < numberOfGifts; ++i)
	{
		cout << "Gift #" << i + 1 << ": " << endl;
		display(gGift[i]);
		cout << endl;
	}
	
	delete[] gGift;
	gGift = nullptr;

	return 0;
}