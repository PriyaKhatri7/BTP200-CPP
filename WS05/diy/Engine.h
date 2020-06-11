#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H

namespace sdds
{

	class Engine
	{
		double e_size;
		char e_type[30];

	public:
		void setEmpty();
		double get() const;
		void display() const;

		//Constructors
		Engine();
		Engine(const char* type, double size);

	};
}


#endif // !SDDS_ENGINE_H

