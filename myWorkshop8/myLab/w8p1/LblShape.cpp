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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>
#include"LblShape.h"

using namespace std;
namespace sdds
{
	//Allocate memory and sets string to data member
	void LblShape::set(string inStr)
	{
		delete[] m_label;
		m_label = new char[strlen(inStr.c_str()) + 1];
		strcpy(m_label, inStr.c_str());
	}

	//Query that returns the unmodifiable value of m_label member variable
	const char* LblShape::label()
	{
		return m_label;
	}

	//Default no argument constructor
	LblShape::LblShape()
	{
		if (m_label != nullptr)
		{
			m_label = nullptr;
		}
	}

	//One argument constructor. Allocates memory to hold the incoming Cstring.
	LblShape::LblShape(string inStr)
	{
		set(inStr);
	}

	//Destructor. Deletes the memory pointed by m_label member variable
	LblShape::~LblShape()
	{
		delete[] m_label;
		m_label = nullptr;
	}

	//Reads a comma-delimited Cstring from the istream.
	//Override the Shape::getSpecs pure virtual function to receive a Cstring (a label) from istream
	//up to the ',' character (and then extract and ignore the comma). 
	// 
	// Afterward, follow the same logic as was done in the one argument constructor; 
	// allocate memory large enough to hold the Cstring and copy the Cstring into the newly allocated memory 
	void LblShape::getSpecs(std::istream& istr)
	{
		string input = { "" };
		getline(istr, input, ',');
		set(input);
	}
}