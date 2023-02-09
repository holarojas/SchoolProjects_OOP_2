/* ------------------------------------------------------
Workshop 7 part 1
Module: N/A
Filename: Container.cpp
Version 1
Author: Martha Rocio Rojas Martinez
Student ID: 112073218
Email: mrrojas-martinez@myseneca.ca
Revision History
-----------------------------------------------------------
Date       Reason
2022/03/17 First version
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Container.h"

using namespace std;
namespace sdds
{
	//Sets the Container to an invalid empty state
	void Container::setEmpty()
	{
		*m_contDesc = { 0 };
		m_capacity = 0;
		m_contVol = 0;
	}

	//Container will be rendered invalid if the content description is null or the content volume exceeds the capacity
	bool Container::isValid(const char* descr, const int capacity, const int volume)
	{
		bool valid = true;
		if (strlen(descr) <= 0 || volume > capacity) {
			valid = false;
		}
		return valid;
	}

	//Default Constructor
	Container::Container()
	{
		setEmpty();
	}

	//Constructor for two or three arguments
	Container::Container(const char* descr, int capacity, int volume)
	{
		if (!isValid(descr, capacity, volume)) {
			//Invalid state
			setEmpty(); 
		}
		else
		{
			strcpy(m_contDesc, descr);
			m_capacity = capacity;
			m_contVol = volume;
		}
	}

	//Returns the capacity value
	int Container::getCapacity() const
	{
		return m_capacity;
	}

	//Returns the volume value
	int Container::getVolume() const
	{
		return m_contVol;
	}

	//Returns the container description
	const char* Container::getDescr()
	{
		return m_contDesc;
	}

	//Return the actual amount that is added to the container
	int Container::operator+=(const int value)
	{
		int valAdded = 0;
		int toFull = 0;

		if ((m_contVol + value) <= m_capacity) {
			m_contVol += value;
			valAdded = value;
		}
		else {
			toFull = m_capacity - m_contVol;
			m_contVol += toFull;
			valAdded = toFull;
		}
		return valAdded;
	}

	//Returns the actual reduced amount
	int Container::operator-=(const int value)
	{
		int valReduced = 0;

		if (value < m_contVol) {
			m_contVol -= value;
			valReduced = value;
		}
		else {
			valReduced = m_contVol;
			m_contVol = 0;
		}
		return valReduced;
	}

	//Returns true if the Container is in a valid state or false if it is not.
	Container::operator bool()
	{
		return (isValid(m_contDesc, m_capacity, m_contVol));
	}

	//If the capacity is a positive value and the content description a valid cString, it will set the corresponding attributes, therefore making the container valid.
	void Container::clear(int capacity, const char* descr)
	{
		if (capacity > 0 && strlen(descr) > 0) {
			m_capacity = capacity;
			strcpy(m_contDesc, descr);
		}
	}

	//Print a valid container
	std::ostream& Container::print(std::ostream& ostr) 
	{
		if (isValid(m_contDesc, m_capacity, m_contVol)) {
			ostr << m_contDesc << ": (" << m_contVol << "cc/" << m_capacity << ")";
		}
		else {
			ostr << "****: (**cc/***)";
		}
		return ostr;
	}

	//Will get an amount to be added to the container
	std::istream& Container::read(std::istream& istr)
	{
		if (!isValid(m_contDesc, m_capacity, m_contVol)) {
			
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
		}
		else {
			cout << "Add to ";
			print(cout);
			
			bool exit = false;
			int input;
			do {
				cout << endl << "> ";
				istr >> input;
				if (input >= 1 && input <= 220000) {
					int added = *this += input;
					cout << "Added " << added << " CCs" << endl;
				}
				else if (input < 1 || input > 220000) {
					cout << "Value out of range [1<=val<=" << m_capacity - m_contVol << "]: " << endl;
				}
				else {
					cout << "Invalid Integer, retry: " << endl;
				}
			} while (exit == true);

		}
		istr.ignore(1000, '\n');
		return istr;
	}

	std::ostream& operator<<(std::ostream& ostr, Container& inObj)
	{
		inObj.print(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Container& inObj)
	{
		inObj.read(istr);
		return istr;
	}
}
