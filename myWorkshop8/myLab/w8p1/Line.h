/* ------------------------------------------------------
Workshop 8 part 1
Module: N/A
Filename: Line.h
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
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"

namespace sdds
{
	//Line inherits the LblShape class to create a horizontal line with a label
	class Line : public LblShape
	{
		int m_length;

	public:
		Line();
		Line(std::string inStr, int length);
		//~Line(); This class has no destructor implemented

		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr);

	};
}
#endif // !SDDS_LINE_H

