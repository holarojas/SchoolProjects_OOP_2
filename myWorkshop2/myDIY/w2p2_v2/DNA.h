/* ------------------------------------------------------
Workshop 2 part 2
Module: DNA
Filename: DNA.cpp
Version 1
Author  Martha Rojas
Revision History
-----------------------------------------------------------
Student Name:	Martha Rocio Rojas Martinez
Student ID:		112073218
Date:			Jan 31th, 2022
-----------------------------------------------------------*/
#ifndef SDDS_DNA_H
#define SDDS_DNA_H

#define MAX_STRAND_CHARS 1000
#define MAX_ID_DIGITS 6

namespace sdds
{
	struct DNA
	{
		int id;
		char* strand;
	};


	//Open file and initialize requirements
	//Return true if file is opened successfully or false if it fails to open the file.
	bool beginSearch(const char* filename);

	//Initialize variables
	void initialize(int allocSize);

	//Creates an array of DNA records to the number of matches found in the file and stores the matches in them
	//Returns true if at least one match is found and false if no match is found in the records
	bool read(const char* subDNA);

	//I got help from a website in order to create this function and using std::sort.
	bool compare(DNA matchedA, DNA matchedB);

	//Sort the dynamic arrays of DNA matches found in the file based  on the ids in ascending order
	void sort();

	//Display the found matches
	void displayMatches();

	//Deallocate memory used for the matchedStrand array
	void deallocate();

	//Deallocate memory used for the dna array that includes all the records from the file
	void endSearch();

}

#endif

