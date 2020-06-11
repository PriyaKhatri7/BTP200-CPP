#include <iostream>
#include <cstring>
#include "Train.h"

using namespace std;

namespace sdds
{

	void Train::setTrain(const char* m_name, int m_id)
	{
		//validate params
		//if train's data members are invalid as follows then set to default values
		if (nullptr == m_name || m_name[0] == '\0' || m_id < 1)
		{
			Train::name[0] = '\0';
			Train::id = 0;
		}
		//else if the train has valid values then set the train's name and id to those values
		else
		{
			strcpy(name, m_name);
			Train::id = m_id;
		}

		//there is no cargo being carried by the Train
		cargo = nullptr;
	}

	//checking for empty state
	bool Train::isEmpty() const
	{
		if (Train::name[0] == '\0' || Train::id == 0)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	char* Cargo::getdescription()
	{
		return description;
	}

	double Cargo::getWeight() const
	{
		return weight;
	}
	void Train::display() const
	{
		cout << "***Train Summary***" << endl;

		if (isEmpty())
		{
			cout << "This is an empty train." << endl;
		}
		else if (!isEmpty())
		{
			cout << "Name: " << name << " ID: " << id << endl;

			if (cargo != nullptr)
			{
				cout << "Cargo: " << cargo->getdescription() << " Weight: " << cargo->getWeight() << endl;
			}
			else
			{
				cout << "No cargo on this train." << endl;
			}
		}

	}

	void Train::loadCargo(Cargo n_Cargo)
	{
		//pointer = new Type;
		cargo = new Cargo;
		*cargo = n_Cargo;
	}

	void Train::unloadCargo()
	{
		delete cargo;
		cargo = nullptr;

	}

	void Cargo::init(const char* c_desc, double c_weight)
	{
		if (strlen(c_desc) < MAX_DESC) //checking desc lenght
		{
			if (MIN_WEIGHT < c_weight || c_weight > MAX_WEIGHT)
			{
				weight = MIN_WEIGHT; //set min_weight to whatever value weight is
			}
			else 
			{
				strcpy(description, c_desc);
				weight = c_weight;

			}
		}
	}


	bool Train::swapCargo(Train& c_swap)
	{
		//declare
		bool trainSwap = false;
		
		if (this->cargo != nullptr && c_swap.cargo != nullptr)
		{
			Cargo* swapTempC;

			swapTempC* = this->cargo;
			this->cargo = c_swap.cargo;
			c_swap.cargo = swapTempC;
			c_swap->swapTempC;


			trainSwap = true;
		}
		return swapCargo;
	}

	bool increaseCargo(double incCargoWeight)
	{
		

	}

}