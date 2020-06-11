#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H

namespace sdds
{
	class ReadWritable
	{
		bool commaSepValsFlag;

	public:
		ReadWritable();
		virtual ~ReadWritable();

		bool isCsv() const; //returns param 
		void setCsv(bool); //set param to incoming bool value

		virtual std::istream& read(std::istream& istr = std::cin) = 0; //
		virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;
	};

	std::ostream& operator<<(std::ostream&, const ReadWritable&);
	std::istream& operator>>(std::istream&, ReadWritable&);
}
#endif // !SDDS_READWRITABLE_H
