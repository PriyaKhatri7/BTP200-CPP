#include <iostream>
#include "ReadWritable.h"

using namespace std;

namespace sdds
{
	//default
	ReadWritable::ReadWritable()
	{
		commaSepValsFlag = false;
	}
	ReadWritable::~ReadWritable()
	{
		//empty virtual. no implementation.
	}

	bool ReadWritable::isCsv() const
	{
		return commaSepValsFlag;
	}
	void ReadWritable::setCsv(bool value)
	{
		commaSepValsFlag = value;
	}

	ostream& operator<<(std::ostream& ost, const ReadWritable& rw)
	{
		rw.write(ost);
		return ost;
	}

	istream& operator>>(std::istream& ist, ReadWritable& rw)
	{
		rw.read(ist);
		return ist;
	}
}