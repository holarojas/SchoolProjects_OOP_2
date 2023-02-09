/* ------------------------------------------------------
Workshop 7 part 1
Module: N/A
Filename: Pack.h
Version 1
Author: Martha Rocio Rojas Martinez
Student ID: 112073218
Email: mrrojas-martinez@myseneca.ca
Revision History
-----------------------------------------------------------
Date       Reason
2022/03/17 First version
-----------------------------------------------------------*/
#ifndef SDDS_PACK_H
#define SDDS_PACK_H

#include "Container.h"

namespace sdds
{
	class Pack: public Container
	{
		int m_unitSize; //Capacity of one of the units in the pack
						//Size of the Pack is m_capacity / m_unitSize
						//Number of units currently in the pack is m_contVol / m_unitSize
		
		void setEmptyPack();

	public:
		Pack();
		Pack(const char* descr, int size, int unitSize = 330, int noOfUnits = 0);

		int operator+=(const int value);
		int operator-=(const int value);

		int unit();
		int noOfUnits();
		int size();

		void clear(int packSize, int unitSize, const char* descr);
		std::ostream& print(std::ostream& ostr);
		std::istream& read(std::istream& istr);
	};

	std::ostream& operator<<(std::ostream& ostr, Pack& inObj);
	std::istream& operator>>(std::istream& istr, Pack& inObj);
}

#endif // !SDDS_PACK_H
