/*WS02 - In Lab
Name: Priya Khatri
Email: pkhatri4@myseneca.ca
Student number: 110149176
*/

#ifndef GIFT_H
#define GIFT_H

namespace sdds {

	//create 2 constant variables
	const int MAX_DESC = 15; //max lenght of gift's description
	const double MAX_PRICE = 999.99; //max price of gift

	//design and code a structure named gift
	struct Gift {
		char g_description[MAX_DESC + 1]; //add 1 for nullbyte
		double g_price;
		int g_units;
	};

	//overloaded functions
	void gifting(char*);
	void gifting(double&);
	void gifting(int&);
	void display(const Gift&);
}

#endif // !GIFT_H

