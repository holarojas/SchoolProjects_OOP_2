/* ------------------------------------------------------
Workshop 9 part 1
Module: Text
Filename: Text.cpp
Version 1.1
Author: Martha Rojas
Student ID: 112073218
Date: March 31st, 2022
Revision History
-----------------------------------------------------------
Date       Reason
22/03/31   First version
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include "Text.h"

using namespace std;
namespace sdds
{
	//Index Operator
	//Provides read-only access to the content of the text for the derived classes of Text.
	//The behaviour of the operator is not defined if the index goes out of bounds or if the content is null.
	const char& Text::operator[](int index) const
	{
		int size = strlen(m_content);
		if (index < size && m_content != nullptr) {
			//Keep it all as it is
		}
		else {
			m_content[index] = EOF; //We've reached End of File. Set to EOF to return it.
		}

		return m_content[index];
	}

	//Set to an empty state
	void Text::setEmpty()
	{
		m_content = nullptr;
	}

	//Default constructor
	Text::Text()
	{
		setEmpty();
	}

	//Destructor
	Text::~Text()
	{
		delete[] m_content;
		m_content = nullptr;
	}

	//Copy Constructor
	Text::Text(const Text& inObj)
	{
		setEmpty();
		delete[] m_content;
		//setEmpty();

		if (inObj.m_content != nullptr) {
			m_content = new char[strlen(inObj.m_content) + 1];
			strcpy(m_content, inObj.m_content);
		}
	}

	//Overlad Assignment Operator
	Text& Text::operator=(const Text& inObj)
	{
		//Make surre this is not a self copy
		if (&(*this) != &inObj) {
			//Do exactly the same as copy constructor
			delete[] m_content;
			setEmpty();

			if (inObj.m_content != nullptr) {
				m_content = new char[strlen(inObj.m_content) + 1];
				strcpy(m_content, inObj.m_content);
			}
		}
		else {
			delete[] m_content;
			setEmpty();
		}
		return *this;
	}

	//To be able to allocate dynamic memory and read the content of a file into the memory, 
	//you need to know the size of the text file in bytes.
	//Returns the number of bytes in an istream object or the value zero if the stream is in an invalid state.
	int Text::getFileLength(std::istream& is)
	{
		int len{};
		if (is) {
			// save the current read position
			std::streampos cur = is.tellg();
			// go to the end
			is.seekg(0, ios::end);
			// let what is the positions (end position = size)
			len = is.tellg();
			// now go back to where you were.
			is.seekg(cur);
		}
		return len;
	}

	std::istream& Text::read(std::istream& istr)
	{
		int length = getFileLength(istr);

		//Deallocates the content
		delete[] m_content;
		setEmpty();

		//Allocates memory to the size of the file on the disk + 1 (for the null byte)
		m_content = new char[length + 1];
		
		//Reads the file into the allocated memory (character by character to the end)
		int idx = 0;
		while (istr >> noskipws >> m_content[idx]) {
			idx++;
		}
		strcpy(&m_content[idx], "\0");
		
		istr.clear();
		return istr;
	}

	//Virtual function
	//Will insert the content of the Text class into the ostream if m_content is not null.
	//Also, this function does not change the content of a file
	std::ostream& Text::write(std::ostream& ostr) const
	{
		if (m_content != nullptr) {
			ostr << m_content;
		}

		return ostr;
	}

	//Extraction Operator Overload
	std::istream& operator>>(std::istream& istr, Text& inObj)
	{
		inObj.read(istr);
		return istr;
	}

	//Insertion Operator Overload
	std::ostream& operator<<(std::ostream& ostr, const Text& inObj)
	{
		inObj.write(ostr);
		return ostr;
	}
}