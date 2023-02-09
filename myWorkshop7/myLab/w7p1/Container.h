/* ------------------------------------------------------
Workshop 7 part 1
Module: N/A
Filename: Container.h
Version 1
Author: Martha Rocio Rojas Martinez
Student ID: 112073218
Email: mrrojas-martinez@myseneca.ca
Revision History
-----------------------------------------------------------
Date       Reason
2022/03/17 First version
-----------------------------------------------------------*/
#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H

namespace sdds
{
	int const MAX_CONTENT_SIZE = 50;

	class Container
	{
		char m_contDesc[MAX_CONTENT_SIZE + 1]; //Description of what the container is holding
		int m_capacity; //Max amount a container can hold in CCs
		int m_contVol; //Current amount the container is holding. Can not exceed the capacity.

	protected:
		void setEmpty();
		bool isValid(const char* descr, const int capacity, const int volume);
		int getCapacity() const;
		int getVolume() const;
		const char* getDescr();

	public:
		Container();
		Container(const char* descr, int capacity, int volume = 0);

		int operator+=(const int value);
		int operator-=(const int value);
		operator bool();

		void clear(int capacity, const char* descr);
		std::ostream& print(std::ostream& ostr);
		std::istream& read(std::istream& istr);
	};

	std::ostream& operator<<(std::ostream& ostr, Container& inObj);
	std::istream& operator>>(std::istream& istr, Container& inObj);

}

#endif // !SDDS_CONTAINER_H
