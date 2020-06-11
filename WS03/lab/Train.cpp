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
		//delete[] cargo;
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

	void Train::display() const
	{
		cout << "***Train Summary***" << endl;

		if (isEmpty())
		{
			cout << "This is an empty train." << endl;
		}
		else if(!isEmpty())
		{
			cout << "Name: " << name << " ID: " << id << endl;

			if (cargo != nullptr)
			{
				cout << "Cargo: " << cargo->description << " Weight: " << cargo->weight << endl;
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

}