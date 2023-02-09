/* ------------------------------------------------------
Workshop 8 part 1
Module: N/A
Filename: LblShape.cpp
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
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include "Shape.h"

namespace sdds
{
	//Inherit an abstract class from the interface Shape.
	//This class adds a label to a shape.
	class LblShape : public Shape
	{
		char* m_label = nullptr;	//Hold the dynamically allocated label for the Shape.
		void set(std::string inStr);

	protected:
		const char* label();

	public:
		LblShape();
		LblShape(std::string inStr);
		~LblShape();
		LblShape(const LblShape&) = delete; //Prevent copying any instance of this class
		void operator=(const LblShape&) = delete; //Prevent assignment of any instance of this class

		void getSpecs(std::istream& istr);
 
	};
}

#endif // !SDDS_LBLSHAPE_H


