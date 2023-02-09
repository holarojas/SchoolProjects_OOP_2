/*------------------------------------------------------
Workshop 10 part 1
Module: temps
File: temps.h
Version 1.0
Author: Martha Rocio Rojas Martinez
Student ID: 112073218
Revision History
-----------------------------------------------------------
Date		Reason
2022/04/12	First version
----------------------------------------------------------- */
#ifndef SDDS_TEMPS_H
#define SDDS_TEMPS_H

using namespace std;
namespace sdds
{
	template <typename type>
	Collection<type> select(const type arrObj[], int size, const type& obj)
	{
		unsigned matches = 0;
		unsigned elem = 0;

		//Find out number of matches
		for (int i = 0; i < size; i++) {
			if (arrObj[i] == obj) { //<-- We need the == comparison operator overload for each type
				matches++;
			}
		}

		//Create collection object of size of matches
		Collection<type> coll(matches); //<-- We need Collection constructor and constructor for each type

		//Set the elements to the matches found
		for (int i = 0; i < size; i++) {
			if (arrObj[i] == obj) {
				coll[elem] = arrObj[i]; //<-- We need the operator[] overload for each type
				elem++;
			}
		}

		return coll;
	}
	
	template <typename type>
	void printCollection(const Collection<type>& obj, const char* title)
	{
		cout << title << endl; 
		for (unsigned i = 0; i < obj.size(); i++) { //<-- Function size() to retrieve the m_size of each type
			cout << obj[i] << endl; //<-- We need the << operator overload for each type
		}
	}
}

#endif // !SDDS_TEMPS_H

