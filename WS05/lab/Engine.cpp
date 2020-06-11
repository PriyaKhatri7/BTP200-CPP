#include <iostream>
#include <cstring>
#include "Engine.h"

using namespace std;

namespace sdds
{

	double Engine::get() const
	{
		return this->e_size;
	}

	void Engine::display() const
	{
			cout << this->e_size << " liters - " << this->e_type << endl;
	}

	void Engine::setEmpty()
	{
		e_size = 0;
		e_type[0] = '\0';
	}

	//constructor
	Engine::Engine()
	{
		//no params and go to safe empty state
		setEmpty();
	}

	Engine::Engine(const char* type, double size)
	{
		if (size < 0)
		{
			setEmpty();
		}
		else
		{
			e_size = size;
			strcpy(e_type, type);
			
		}
	}

}
