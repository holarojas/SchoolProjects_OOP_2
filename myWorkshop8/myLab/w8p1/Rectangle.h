/* ------------------------------------------------------
Workshop 8 part 1
Module: N/A
Filename: Rectangle.h
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
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LblShape.h"

namespace sdds
{
	//Rectangle class inherits the LblShape class to create a frame with a label inside
	class Rectangle : public LblShape
	{
		int m_width;
		int m_height;

	public:
		Rectangle();
		Rectangle(std::string label, int width, int height);
		//~Rectangle(); This class has no destructor implemented

		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr);
	};
}
#endif // !SDDS_RECTANGLE_H

