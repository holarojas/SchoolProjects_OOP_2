/* ------------------------------------------------------
Workshop 8 part 1
Module: N/A
Filename: Rectangle.cpp
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
#include <string.h>
#include "Rectangle.h"

using namespace std;
namespace sdds
{
	//Default (no argument) constructor
	Rectangle::Rectangle():LblShape()
	{
		m_width = 0;
		m_height = 0;
	}

	//Three argument constructor
	Rectangle::Rectangle(string label, int width, int height):LblShape(label)
	{
		int getLength = strlen(label.c_str());
		m_width = width;
		m_height = height;
		if ((m_height < 3) || m_width < getLength + 2) {
			m_width = 0;
			m_height = 0;
		}
	}

	//Reads a comma-separated specs of the Rectangle from istream.
	//This function overrides the getSpecs function of the base class as follows:
	//First, it will call the getSpecs function of the base class, 
	//then it will read two comma-separated values from istream for m_width and m_length 
	// and then ignores the rest of the characters up to and including the newline character '\n'
	void Rectangle::getSpecs(std::istream& istr)
	{
		LblShape::getSpecs(istr);
		string input = { "" };
		getline(istr, input, ',');
		m_width = stoi(input);

		input = { "" };
		getline(istr, input, '\n');
		m_height = stoi(input);

		//istr.ignore(1000, '\n');
	}

	//This function overrides the draw function of the base class.
	//If the rectangle is not in an empty state, this function will draw a rectangle
	//with a label inside as follows, otherwise, it will do nothing
	void Rectangle::draw(std::ostream& ostr)
	{
		if (m_width > 0 && m_height > 0) {
			int setWidth = m_width - 1;
			
			//First Line
			ostr << "+";
			ostr.width(setWidth);
			ostr.fill('-');
			ostr << "+" << endl;

			//Second Line
			int setLabelWidth = setWidth - strlen(label());
			ostr << "|" << label();
			ostr.width(setLabelWidth);
			ostr.fill(' ');
			ostr << '|' << endl;

			//Next Lines
			for (int i = 0; i < m_height - 3; i++) {
				ostr << "|";
				ostr.width(setWidth);
				ostr.fill(' ');
				ostr << "|" << endl;
			}

			//Last Line
			ostr << "+";
			ostr.width(setWidth);
			ostr.fill('-');
			ostr << "+";
		}
		
	}
}