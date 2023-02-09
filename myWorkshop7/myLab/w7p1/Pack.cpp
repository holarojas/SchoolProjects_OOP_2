/* ------------------------------------------------------
Workshop 7 part 1
Module: N/A
Filename: Pack.cpp
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
#include "Pack.h"

using namespace std;
namespace sdds
{
	//Set empty state to Base class and Pack
	void Pack::setEmptyPack()
	{
		Container::setEmpty();
		m_unitSize = 0;
	}

	//Default Constructor
	Pack::Pack()
	{
		setEmptyPack();
	}

	//Pack Constructor using Base Class constructor
	Pack::Pack(const char* descr, int size, int unitSize, int noOfUnits):Container(descr, size*unitSize, noOfUnits*unitSize)
	{
		if (unitSize > 0) {
			m_unitSize = unitSize;
		}
		else {
			setEmptyPack();
		}
	}

	//Overrides (shadows) the operator += of the Base Class 
	//Receives a number to add units to the pack and returns the number of units successfully added
	int Pack::operator+=(const int value)
	{
		int result = Container::operator+=(value * m_unitSize);
		return result / m_unitSize;
	}

	//Overrides (shadows) the operator -= of the Base Class
	//Receives a number to remove units from the pack and returns the number of units successfully removed
	int Pack::operator-=(const int value)
	{
		int result = Container::operator-=(value * m_unitSize);
		return result / m_unitSize;
	}

	//Returns the unit size attribute
	int Pack::unit()
	{
		return m_unitSize;
	}

	//Returns the content volume of the Base class divided by the unit size
	int Pack::noOfUnits()
	{
		return getVolume() / m_unitSize;
	}

	//Return the capacity of the base class divided by the unit size
	int Pack::size()
	{
		return getCapacity() / m_unitSize;
	}

	//Overloads the clear function of the Base class
	void Pack::clear(int packSize, int unitSize, const char* descr)
	{
		if (unitSize > 0) {
			Container::clear(packSize * unitSize, descr);
			m_unitSize = unitSize;
		}
	}

	//Overrides (shadows) the print of the Base class
	//Will display a valid Pack as follows
	std::ostream& Pack::print(std::ostream& ostr)
	{
		Container::print(ostr);
		if (m_unitSize > 0) {
			ostr << ", " << (getVolume() / m_unitSize) << " in a pack of " << (getCapacity() / m_unitSize);
		}
		return ostr;
	}

	//Overrides (shadows) the read of the Base class
	//Will get a number for the count of the units to be added to the pack if the pack is valid and not full.
	std::istream& Pack::read(std::istream& istr)
	{
		bool exit = false;
		int input;

		if (!isValid(getDescr(), getCapacity(), getVolume())) {
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
		}
		else {
			//Check if there is still space to add volume in the Container
			if (getVolume() < getCapacity()) {
				cout << "Add to ";
				print(cout) << endl << "> ";

				do {
					istr >> input;
					//Check if the number of units in the Pack is less than size of the Pack
					if ((getVolume() / m_unitSize) < (getCapacity() / m_unitSize)) {

						//If input value is between 1 and the number of missing units of the Pack
						if (input >= 1 && input <= (getCapacity() / m_unitSize) - (getVolume() / m_unitSize)) {
							int added = *this += input;
							cout << "Added " << added << endl;
							exit = true;
						}
						else if (input < 1 || input >(getCapacity() / m_unitSize) - (getVolume() / m_unitSize)) {
							cout << "Value out of range [1<=val<=" << (getCapacity() / m_unitSize) - (getVolume() / m_unitSize) << "]: ";

						}
						else {
							cout << "Invalid Integer, retry: ";
						}

					}
				} while (exit == false);
			}
			else {
				//There is no space in the container
				cout << "Pack is full!, press <ENTER> to continue...";
			}
		}

		istr.ignore(1000, '\n');
		return istr;
	}

	std::ostream& operator<<(std::ostream& ostr, Pack& inObj)
	{
		inObj.print(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Pack& inObj)
	{
		inObj.read(istr);
		return istr;
	}

}