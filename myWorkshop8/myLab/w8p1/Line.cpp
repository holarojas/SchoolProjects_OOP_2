/* ------------------------------------------------------
Workshop 8 part 1
Module: N/A
Filename: Line.cpp
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
#include <string>
#include "Line.h"

using namespace std;
namespace sdds
{
	//Default (no argument) constructor
	Line::Line():LblShape()
	{
		m_length = 0;
	}

	//Two argument constructor
	Line::Line(string inStr, int length):LblShape(inStr)
	{
		m_length = length;
	}

	//Reads comma-separated specs of the Line from istream.
	//This function overrides the getSpecs function of the base class as follows.
	//First, it will call the getSpecs function of the base class, then it will read the value of the m_length attribute
	//from the istream argument, and then it will ignore the rest of the characters up to and including the newline character '\n'
	void Line::getSpecs(std::istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_length;
		istr.ignore(1000, '\n');
	}

	//This function overrides the draw function of the base class.
	//If the m_length member variable is greater than zero and the label() is not null,
	//this function will first print the label() and then go to the new line.
	//Afterward it keeps printing the '=' to the value of the m_length member variable.
	//Otherwise it will take no action
	void Line::draw(std::ostream& ostr) 
	{
		if (m_length > 0 && label() != nullptr) {
			ostr << label() << endl;
			ostr.width(m_length);
			ostr.fill('=');
			ostr << '=';
		}
	}
}