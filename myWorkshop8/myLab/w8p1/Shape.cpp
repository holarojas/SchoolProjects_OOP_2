/* ------------------------------------------------------
Workshop 8 part 1
Module: N/A
Filename: Shape.cpp
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
#include <iostream>
#include "Shape.h"

using namespace std;
namespace sdds
{
	//Empty destructor
	Shape::~Shape()
	{
		;
	}

	//Overload the insertion operator
	std::ostream& operator<<(std::ostream& ostr, Shape& inObj)
	{
		inObj.draw(ostr);
		return ostr;
	}

	//Overload the extraction operator
	std::istream& operator>>(std::istream& istr, Shape& inObj)
	{
		inObj.getSpecs(istr);
		return istr;
	}
}