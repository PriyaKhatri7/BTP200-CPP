#include <iostream>

#ifndef BASKET_H
#define BASKET_H

using namespace std; //don't put using namespace in the header

namespace sdds
{
	class Basket
	{
		char* nameFruitB; //dynamically allocate array of chars. During implementation use [].
		int num_FruitB;
		double price_basket;

	public:
		Basket();
		Basket(const char*, int, double);
		Basket(const Basket&); //copy constructor
		Basket& operator=(const Basket&); //copy assignment operator
		~Basket();

		void setName(const char* theName); //set the name of the param
		void setqty(int); //set quantity of fruits of the basket
		void setPrice(double); //set the price of the basket
		bool isEmpty() const; //return true if it is in an SES
		bool addPrice(double);
		ostream& display(ostream& os) const; //display the current details of basket

		//operator overload members
		bool operator==(const Basket&) const; //true if the values are the false
		bool operator!=(const Basket&) const; //return true is baskets are not identical

	};
	//operator overload helpers
	ostream& operator<<(ostream& os, const Basket& bsk); //callers display to print into os the conten of bsk

}
#endif // !BASKET_H