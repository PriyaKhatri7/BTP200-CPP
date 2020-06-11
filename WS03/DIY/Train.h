#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds
{
	const int MAX_NAME = 30; //max length for trains name
	const int MAX_DESC = 20; //max length for a Cargo's description excluding nullbyte
	const double MAX_WEIGHT = 700.555; //max lenght for a Cargo
	const double MIN_WEIGHT = 40.444; //min lenght for a Cargo

	class Cargo //default class is private
	{
		char description[MAX_DESC + 1]; //desc for cargo
		double weight; //weight of cargo

	public:
		char* getdescription();
		double getWeight() const;
		void init(const char*, double);
		
	};

	class Train 
	{
	private:
		char name[MAX_NAME];
		int id;
		Cargo* cargo; //A pointer of Cargo type. It will be used to represent the Cargo a Train is carrying by utilizing dynamic memory.

	public:
		//Train Public Members
		void setTrain(const char*, int);
		bool isEmpty() const;
		void display() const;
		void loadCargo(Cargo);
		void unloadCargo();
		bool swapCargo(Train&);
		bool increaseCargo(double);
	};

}

#endif // !SDDS_TRAIN_H

