//WS02 - Part 1 | Name: Priya Khatri | Email: pkhatri4@myseneca.ca | Student number: 110149176

#ifndef SDDS_GIFT_H
#define SDDS_GIFT_H

namespace sdds
{
	const int MAX_DESC = 15; //max length of gifts descrip
	const double MAX_PRICE = 999.999; // mac price of a gift

	struct Gift
	{
		char m_description[MAX_DESC + 1]; //1 for nullbtye. Store the desc of the gift
		double m_price; //price of gift. min 0 max MAX_PRICE
		int m_units; //# of units/copies of the Gift
	};

	void gifting(char* desc);
	void gifting(double& price);
	void gifting(int& units);
	void display(const Gift& theGift);
}

#endif // !SDDS_GIFT_H

