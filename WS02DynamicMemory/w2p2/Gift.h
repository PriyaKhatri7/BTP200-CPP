//WS02 - Part 2 | Name: Priya Khatri | Email: pkhatri4@myseneca.ca | Student number: 110149176

#ifndef SDDS_GIFT_H
#define SDDS_GIFT_H

namespace sdds
{
	const int MAX_DESC = 15; //max length of gifts descrip
	const double MAX_PRICE = 999.999; // mac price of a gift
	const int MAX_WRAP = 20; //wrapping layers a gift can have

	struct Wrapping
	{
		//dynamically allocated arr of chars
		char* m_pattern; //desc the pattern of wrapping paper
	};

	struct Gift
	{
		char m_description[MAX_DESC + 1]; //1 for nullbtye. Store the desc of the gift
		double m_price = 0.0; //price of gift. min 0 max MAX_PRICE
		int m_units = 0; //# of units/copies of the Gift

		Wrapping* m_wrap;
		int m_wrapLayers; //# layers used to wrap the gift
	};

	void gifting(char* desc);
	void gifting(double& price);
	void gifting(int& units);

	bool wrap(Gift& theGift);
	bool unwrap(Gift& theGift);
	void gifting(Gift& theGift);
	void display(const Gift& theGift);
	
}

#endif // !SDDS_GIFT_H

