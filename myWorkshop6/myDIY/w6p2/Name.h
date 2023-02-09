/* ------------------------------------------------------
Workshop 6 part 2
Module: Name
Filename: Name.h
Version 1
Author: Martha Rojas
Revision History
-----------------------------------------------------------
Student Name:	Martha Rocio Rojas Martinez
Student ID:		112073218
Date			Reason
07/03/2022		Workshop #6
-----------------------------------------------------------*/
#ifndef SDDS_NAME_H
#define SDDS_NAME_H

namespace sdds
{
	const int MAX_NAME_LENGTH = 50;

	class Name
	{
		char* m_firstName{};
		char* m_middleName{};
		char* m_lastName{};
		bool m_printFormat;

		void setEmpty();
		void allocateAndCopy(const char* fName, const char* mName, const char* lName);

	public:
		Name(); //Constructor
		Name(const char* fName); 
		Name(const char* fName, const char* lName); 
		Name(const char* fName, const char* mName, const char* lName); 
		~Name(); //Destructor

		Name(const Name& inObj);
		Name& operator=(const Name& inObj);
		Name& operator+=(std::string cStr);
		operator bool() const;

		void setShort(bool abbr);

		std::istream& read(std::istream& istr);
		std::ostream& print(std::ostream& ostr) const;

	};

	std::istream& operator>>(std::istream& istr, Name& inObj); //Extraction from istream Operator overload
	std::ostream& operator<<(std::ostream& ostr, const Name& inObj); // Insertion to ostream Operator overload
}

#endif // !SDDS_NAME_H


