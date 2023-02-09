/* ------------------------------------------------------
Workshop 2 part 1
Module: cStrTools
Filename: cStrTools.h
Version 1
Author Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date: Jan 27th, 2022        

Name:           Martha Rocio Rojas Martinez
Email:          mrrojas-martinez@myseneca.ca
Student ID:     112073218

-----------------------------------------------------------*/
#ifndef SDDS_CSTRTOOLS_H
#define SDDS_CSTRTOOLS_H

namespace sdds
{
	// Returns the lower case value of a character
	char toLower(char ch);

	// Compares s1 and s2 cStrings and returns:
	// > 0 if s1 > s2
	// < 0 if s1 < s2
	// == 0 if s1 == s2
	int strCmp(const char* s1, const char* s2);

	// Compares s1 and s2 cStrings upto len characters and returns:
	// > 0 if s1 > s2
	// < 0 if s1 < s2
	// == 0 if s1 == s2
	int strnCmp(const char* s1, const char* s2, int len);

	// Copies src to des
	void strCpy(char* des, const char* src);

	// Returns the length of str
	int strLen(const char* str);

	// If "find" is found in "str" it will return the addres of the match
	// If not found it will returns nullptr (zero)
	const char* strStr(const char* str, const char* find);

	// Returns true if ch is alphabetical
	int isAlpha(char ch);

	// Returns true if ch is a whitespace character
	int isSpace(char ch);

	// Removes the non-alphabetic characters from the begining and end of a word
	void trim(char word[]);

	// Copies the  lower case version of the source into des.
	void toLowerCaseAndCopy(char des[], const char source[]);

	// Reads a cString upto maxSize characters or upto the delimiter character,
	// whichever comes first (skipping leading white space characters but accpting
	// spaces in the cString)
	void read(char* cString, unsigned int maxSize, char delimiter = '\n');
}

#endif
