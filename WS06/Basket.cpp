#include <iostream>
#include <iomanip> //setprecision
#include <cstring>
#include "Basket.h"

using namespace std;

namespace sdds
{

	//set to empty state
	Basket::Basket()
	{
		nameFruitB = nullptr;
		num_FruitB = 0;
		price_basket = 0.0;
	}

	Basket::Basket(const char* name, int quantity, double price): Basket()
	{
		if ((name != nullptr) && (quantity > 0) && (price > 0.0))
		{
			nameFruitB = new char[strlen(name) + 1];
			strcpy(this->nameFruitB, name);

			this->num_FruitB = quantity;
			this->price_basket = price;
		}

	}

	//Copy constructor
	Basket::Basket(const Basket& src)
	{
		//shallow copies
		num_FruitB = src.num_FruitB;
		price_basket = src.price_basket;

		//allocate dyamic memory for names
		if (src.nameFruitB != nullptr)
		{
			nameFruitB = nullptr;
			nameFruitB = new char[strlen(src.nameFruitB) + 1];

			int ct = strlen(src.nameFruitB) + 1;
			//copy data from source resource to newly allocated resource
			for (int i = 0; i < ct; i++)
			{
				this->nameFruitB[i] = src.nameFruitB[i];
			}
		}
		else
		{
			nameFruitB = nullptr;
		}
	}

	//Copy assignment operator
	Basket& Basket::operator=(const Basket& source)
	{
		//check for self-assignment
		if (this != &source)
		{
			//shallow copy for non-resouce variables
			num_FruitB = source.num_FruitB;
			price_basket = source.price_basket;

			//deallocate previously allocated dynamic memory
			delete[] nameFruitB;

			//allocate new dynamic memory if needed
			if (source.nameFruitB != nullptr) {
				nameFruitB = nullptr;
				nameFruitB = new char[strlen(source.nameFruitB) + 1];

				int ct = strlen(source.nameFruitB) + 1;
				//copy resource data
				for (int i = 0; i < ct; i++)
					this->nameFruitB[i] = source.nameFruitB[i];
			}
			else
			{
				nameFruitB = nullptr;
			}
		}
		return *this;
	}

	//destructor
	Basket::~Basket()
	{
		delete[] nameFruitB;
		nameFruitB = nullptr;
	}

	void Basket::setName(const char* theName)
	{
		if (theName != nullptr)
		{
			nameFruitB = new char[strlen(theName) + 1];
		}
		else
		{
			nameFruitB = nullptr;
		}
	}

	void Basket::setqty(int qty)
	{
		if (qty > 0)
		{
			num_FruitB = qty;
		}
		else
		{
			num_FruitB = 0;
		}
	}

	void Basket::setPrice(double setp)
	{
		if (setp > 0.0)
		{
			price_basket = setp;
		}
		else
		{
			price_basket = 0.0;
		}
	}

	bool Basket::isEmpty() const
	{
		if ((this->nameFruitB == nullptr) && (this->num_FruitB == 0) && (this->price_basket == 0.0))
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	bool Basket::addPrice(double addp)
	{
		if (addp > 0)
		{
			this->price_basket = this->price_basket + addp;
			return true;
		}
		else {
			return false;

		}

	}

	ostream& Basket::display(ostream& os) const
	{
		if (!isEmpty())
		{
			os << "Basket Details" << endl;
			os << "Name: " << this->nameFruitB << endl;
			os << "Quantity: " << this->num_FruitB << endl;
			os << fixed << setprecision(2) << "Price: " << this->price_basket << endl;
			
		}
		else
		{
			os << "The Basket has not yet been filled" << endl;
		}
		return os;
	}

	bool Basket::operator==(const Basket& b1) const
	{

		if ((this->nameFruitB == b1.nameFruitB) && (this->num_FruitB == b1.num_FruitB) && (this->price_basket == b1.price_basket))
		{
			return false;
		}
		else
		{
			return true;
		}

	}

	bool Basket::operator!=(const Basket& increase) const
	{
		if ((this->nameFruitB != increase.nameFruitB) && (this->num_FruitB != increase.num_FruitB) && (this->price_basket != increase.price_basket))
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	ostream& operator<<(ostream& os, const Basket& bsk)
	{
		bsk.display(os);
		return os;
	}


}
