/* ------------------------------------------------------
Workshop 8 part 1
Module: N/A
Filename: Shape.h
Version 1
Author: Martha Rocio Rojas Martinez
Student ID: 112073218
Email: mrrojas-martinez@myseneca.ca
Revision History
-----------------------------------------------------------
Date       Reason
2022/03/24 First version
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and
assignments.
-----------------------------------------------------------*/
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H


namespace sdds
{
	class Shape
	{

	public:
		virtual void draw(std::ostream& ostr) = 0;
		virtual void getSpecs(std::istream& istr) = 0;
		virtual ~Shape();

	};
	std::ostream& operator<<(std::ostream& ostr, Shape& inObj);
	std::istream& operator>>(std::istream& istr, Shape& inObj);
	
}

#endif // !SDDS_SHAPE_H


