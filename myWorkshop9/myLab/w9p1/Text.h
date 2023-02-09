/* ------------------------------------------------------
Workshop 9 part 1
Module: Text
Filename: Text.h
Version 1.1
Author: Martha Rojas
Student ID: 112073218
Date: March 31st, 2022
Revision History
-----------------------------------------------------------
Date       Reason
22/03/31   First version
-----------------------------------------------------------*/
#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H

namespace sdds
{
	//A class that can read the contents of a text file into memory and insert it into ostream.
	class Text
	{
		char* m_content;	//Holds the content of the text file dynamically

		void setEmpty();

	protected:
		const char& operator[](int index) const;

	public:
		Text();
		~Text();
		Text(const Text& inObj);
		Text& operator=(const Text& inObj);

		int getFileLength(std::istream& is);
		std::istream& read(std::istream& istr);
		virtual std::ostream& write(std::ostream& ostr) const;
	};

	std::istream& operator>>(std::istream& istr, Text& inObj);
	std::ostream& operator<<(std::ostream& ostr, const Text& inObj);
}

#endif