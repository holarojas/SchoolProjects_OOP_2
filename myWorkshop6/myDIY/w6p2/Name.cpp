/* ------------------------------------------------------
Workshop 6 part 2
Module: Name
Filename: Name.cpp
Version 1
Author: Martha Rojas
Revision History
-----------------------------------------------------------
Student Name:	Martha Rocio Rojas Martinez
Student ID:		112073218
Date			Reason
07/03/2022		Workshop #6
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include "Name.h"

using namespace std;
namespace sdds
{
	//Set to initial empty state
	void Name::setEmpty()
	{
		m_firstName = nullptr;
		m_middleName = nullptr;
		m_lastName = nullptr;
		m_printFormat = false;
	}

	void Name::allocateAndCopy(const char* fName, const char* mName, const char* lName)
	{
		//Free the memory
		delete[] m_firstName;
		delete[] m_middleName;
		delete[] m_lastName;
		setEmpty();

		//Allocate enough memory to store name in Cstring
		//Copy the Cstring
		if (strlen(fName) > 0) {
			m_firstName = new char[strlen(fName) + 1];
			strcpy(m_firstName, fName);
		}
		if (strlen(mName) > 0) {
			m_middleName = new char[strlen(mName) + 1];
			strcpy(m_middleName, mName);
		}
		if (strlen(lName) > 0) {
			m_lastName = new char[strlen(lName) + 1];
			strcpy(m_lastName, lName);
		}
	}

	//Default Constructor
	Name::Name()
	{
		setEmpty();
	}

	//Constructor 1 Argument
	Name::Name(const char* fName)
	{
		if (fName != nullptr && strlen(fName) > 0) {
			allocateAndCopy(fName, "", "");
		}
		else {
			setEmpty();
		}
	}

	//Constructor 2 Arguments
	Name::Name(const char* fName, const char* lName)
	{
		if ((fName != nullptr && strlen(fName) > 0) && (lName != nullptr && strlen(lName) > 0)) {
			allocateAndCopy(fName, "", lName);
		}
		else {
			setEmpty();
		}
	}

	//Constructor 3 Arguments
	Name::Name(const char* fName, const char* mName, const char* lName)
	{
		if ((fName != nullptr && strlen(fName) > 0) && (mName != nullptr && strlen(mName) > 0) && (lName != nullptr && strlen(lName) > 0)) {
			allocateAndCopy(fName, mName, lName);
		}
		else {
			setEmpty();
		}
	}

	//Destructor
	Name::~Name()
	{
		delete[] m_firstName;
		delete[] m_middleName;
		delete[] m_lastName;
		setEmpty();
	}

	//Copy Constructor
	Name::Name(const Name& inObj)
	{
		delete[] m_firstName;
		delete[] m_middleName;
		delete[] m_lastName;
		setEmpty();

		if (inObj.m_firstName != nullptr) {
			m_firstName = new char[strlen(inObj.m_firstName) + 1];
			strcpy(m_firstName, inObj.m_firstName);
		}
		if (inObj.m_middleName != nullptr) {
			m_middleName = new char[strlen(inObj.m_middleName) + 1];
			strcpy(m_middleName, inObj.m_middleName);
		}
		if (inObj.m_lastName != nullptr) {
			m_lastName = new char[strlen(inObj.m_lastName) + 1];
			strcpy(m_lastName, inObj.m_lastName);
		}
			
	}

	//Overload Assignment Operator
	Name& Name::operator=(const Name& inObj)
	{
		//Make sure this is not a self copy
		if (&(*this) != &inObj) {
			//Do exactly the same as copy constructor
			delete[] m_firstName;
			delete[] m_middleName;
			delete[] m_lastName;
			setEmpty();

			m_firstName = new char[strlen(inObj.m_firstName) + 1];
			m_middleName = new char[strlen(inObj.m_middleName) + 1];
			m_lastName = new char[strlen(inObj.m_lastName) + 1];

			strcpy(m_firstName, inObj.m_firstName);
			strcpy(m_middleName, inObj.m_middleName);
			strcpy(m_lastName, inObj.m_lastName);
		}
		else {
			delete[] m_firstName;
			delete[] m_middleName;
			delete[] m_lastName;
			setEmpty();
		}
		return *this;
	}

	//Overload sum(additional) operator. When a Cstring is added to the name, it will be used  to set the next available part of the name
	Name& Name::operator+=(std::string cStr)
	{
		if (cStr.empty() || cStr.find(' ') != cStr.npos) {
			//Operation is aborted and the object will not change
		}
		else {
			if (m_firstName == nullptr) {
				m_firstName = new char[cStr.size() + 1];
				strcpy(m_firstName, cStr.c_str());
			}
			else if (m_middleName == nullptr) {
				m_middleName = new char[cStr.size() + 1];
				strcpy(m_middleName, cStr.c_str());
			}
			else if (m_lastName == nullptr) {
				m_lastName = new char[cStr.size() + 1];
				strcpy(m_lastName, cStr.c_str());
			}
			else {
				//If the name has all tree parts, the operation fails and sets the object into an invalid empty state
				//If there are spaces in the CString the operation fails. The Name object is then set to an invalid state
				delete[] m_firstName;
				delete[] m_middleName;
				delete[] m_lastName;
				setEmpty();
			}
		}
		
		return *this;
	}

	//Boolean type conversion operator. Return true if m_name != nullptr
	Name::operator bool() const
	{
		return (m_firstName != nullptr);
	}

	//If the argument passed is true, the middle name will be abbreviated when printed
	void Name::setShort(bool abbr)
	{
		m_printFormat = abbr;
	}

	//Read function
	std::istream& Name::read(std::istream& istr)
	{
		delete[] m_firstName;
		delete[] m_middleName;
		delete[] m_lastName;
		setEmpty();

		string line = { "" };
		string tempFirst = { "" };
		string tempMid = { "" };
		string tempLast = { "" };

		//Get whole line of input
		getline(istr, line, '\n');
		
		stringstream stream(line);

		//Read First Name
		getline(stream, tempFirst, ' ');

		char next = stream.peek();
		if (!isalpha(next)) { //If there is no letter next, it means this text is only a first name
			m_firstName = new char[tempFirst.size() + 1];
			strcpy(m_firstName, tempFirst.c_str());

			delete[] m_middleName;
			m_middleName = nullptr;

			delete[] m_lastName;
			m_lastName = nullptr;
		}
		else { //If there is a letter next:
			m_firstName = new char[tempFirst.size() + 1];
			strcpy(m_firstName, tempFirst.c_str());

			//Read Middle Name
			getline(stream, tempMid, ' ');

			next = stream.peek();
			if (!isalpha(next)) { //If there is no letter next, it means this text is a last name
				m_lastName = new char[tempMid.size() + 1];
				strcpy(m_lastName, tempMid.c_str());

				delete[] m_middleName;
				m_middleName = nullptr;

			}
			else {
				//If there is a letter next, then there is a middle name and last name
				m_middleName = new char[tempMid.size() + 1];
				strcpy(m_middleName, tempMid.c_str());

				getline(stream, tempLast, ' ');
				m_lastName = new char[tempLast.size() + 1];
				strcpy(m_lastName, tempLast.c_str());

				next = stream.peek();
				if (isalpha(next)) { //If there is another name (A 4th name) then is invalid
					delete[] m_firstName;
					delete[] m_middleName;
					delete[] m_lastName;
					setEmpty();
					istr.putback('\n');
				}
			}

		}
		
		

		return istr;
	}

	//Print function
	std::ostream& Name::print(std::ostream & ostr) const
	{
		if (m_firstName == nullptr) {
			ostr << "Bad Name";
		}
		else {
			//Only First Name
			if (m_firstName != nullptr && m_middleName == nullptr && m_lastName == nullptr) {
				ostr << m_firstName;
			} //Only First Name and Last Name
			else if (m_firstName != nullptr && m_middleName == nullptr && m_lastName != nullptr) {
				ostr << m_firstName << ' ' << m_lastName;
			} //Only First Name and Middle Name
			else if (m_firstName != nullptr && m_middleName != nullptr && m_lastName == nullptr) {
				ostr << m_firstName << ' ' << m_middleName;
			}
			//Has the tree parts
			else if (m_firstName != nullptr && m_middleName != nullptr && m_lastName != nullptr) {
				if (m_printFormat == true) { //SHORT FORMAT
					ostr << m_firstName << ' ' << m_middleName[0] << '.' << ' ' << m_lastName;
				}
				else if (m_printFormat == false) { //NORMAL FORMAT
					ostr << m_firstName << ' ' << m_middleName << ' ' << m_lastName;
				}
			}

		}	 
		return ostr;
	}
	

	std::istream& operator>>(std::istream& istr, Name& inObj)
	{
		inObj.read(istr);
		
		return istr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Name& inObj)
	{
		inObj.print(ostr);
		return ostr;
	}
}


