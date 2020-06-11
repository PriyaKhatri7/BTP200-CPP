// Priya Khatri, 110149176, pkhatri4@myseneca.ca
#include <iostream>
#include <cstring>

#ifndef NUMBERSBOX_H
#define NUMBERSBOX_H

namespace sdds
{


	template <class T>
	class NumbersBox
	{
		char name[15]; //name of box
		int size; //size of box
		T* items; //nums in box

	public:
		//constructor
		NumbersBox()
		{
			name[0] = '\0';
			size = 0;
			items = nullptr;
		}
		//2-arg constructor
		//size of boxes, name of boxes
		NumbersBox(int sofbox, const char* nofbox)
		{
			//hold atleast 1 box
			if (sofbox > 0)
			{
				items = new T[size];
				size = sofbox;
				strcpy(name, nofbox);
			}
			else //set empty
			{
				name[0] = '\0';
				size = 0;
				items = nullptr;
			}
		}

		//access to box's items via index. return value of item in the box at index i.
		T& operator[](int i)
		{
			return items[i];
		}

		//multiply each item in our Box by the opposing Box’s item thus 
		//modifying the current object’s items. returns current object.
		NumbersBox<T>& operator*=(const NumbersBox<T>& other)
		{
			if (other.size == this->size)
			{
				for (int i = 0; i < size; i++)
				{
					this->items[i] *= other.items[i];
				}
			}
			return *this;
		}

		//resize items arr dynamicaly and incorporating the num passed into the resized arr
		NumbersBox<T>& operator+=(T num)
		{
			//create temp arr
			T* tmpItem;
			tmpItem = nullptr;
			tmpItem = new T[size];

			//copy old arr to temp
			for (int i = 0; i < size; i++)
			{
				tmpItem[i] = items[i];
			}
			//increase size by one
			size++;

			//delete old array and make another array with the same old name now allocated with new size
			delete[] items;
			items = nullptr;

			items = new T[size];

			//copy temp array into new array and at last index add num variable
			for (int i = 0; i < size; i++)
			{
				if (i == (size - 1))
				{
					items[i] = num;
				}
				else
				{
					items[i] = tmpItem[i];
				}
			}

			//delete temp array for memory leaks and return this 
			delete[] tmpItem;
			tmpItem = nullptr;

			return *this;
		}

		std::ostream& display(std::ostream& os) const
		{
			//if (name[0] == '\0' && size > 0 && items == nullptr)
			if(name[0] == '\0')
			{
				os << "Empty Box" << std::endl;
			}
			else
			{
				os << "Box name: " << name << std::endl;
				for (int i = 0; i < size; i++)
				{
					if (i == (size - 1))
					{
						os << items[i] << std::endl;
					}
					else
					{
						os << items[i] << ", ";
					}
				}
				os << std::endl;
			}
			return os;
		}
	};

	template <class T>
	std::ostream& operator<<(std::ostream& os, NumbersBox<T>& box)
	{
		box.display(os);
		return os;
	}
}
#endif // !NUMBERSBOX_H
