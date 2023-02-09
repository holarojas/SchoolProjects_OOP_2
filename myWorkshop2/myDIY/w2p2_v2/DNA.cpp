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
Notes:			My bubble sort algorithm worked fine with the small .csv file but for the big csv file I had to use the <algorithm> std::sort function
				I found the code in this website https://www.section.io/engineering-education/getting-started-with-structs-sorting-in-c++/
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include "DNA.h"
#include "cStrTools.h"

using namespace std;

namespace sdds
{
	//File scoped variables
	static struct DNA* dna = nullptr; //The DNA Pointer 
	static int numDNAs; //Number of DNA strands currently in the dynamic array of dna
	static int arrSize; //Current allocation size of the array. It is the max size that the numDNAs can grow up to (before realocation for expansion)
	static int size; //Holds the memory allocation and expansion size

	FILE* file = NULL; //Allocate memory for file pointer 

	//We use matchedStrands DNA in read() and sort() functions
	static struct DNA* matchedStrands = nullptr;
	//We use matchCount variable in read(), sort() and displayMatches() functions
	static int matchCount = 0;

	
	bool beginSearch(const char* filename)
	{
		bool result = false;
		int id = 0, c, strandSize = 0;
		char strand[MAX_STRAND_CHARS] = { 0 };

		cout << "DNA search program" << endl;

		initialize(1000); //Create the original dna dynamic array where we are going to store all the values in the file.
 
		file = fopen(filename, "r"); //Open file in reading mode

		if (file != NULL) {
			//Scan each record and assign the value to each variable.
			while ((fscanf(file, "%d,%[^\n]", &id, strand)) != EOF) {

				strandSize = 0;
				for (c = 0; strand[c] != '\0'; c++) {
					strandSize++; //Get the number of chars in the static array
				}

				if (numDNAs == arrSize) {
					//If dna array has no space available to store the i record
					int currentStrandSize = 0;
					struct DNA* temp = nullptr; //We'll use this array to store the actual values of the dna array.
					temp = new DNA[arrSize + size]; //It will be double the current size

					for (int i = 0; i < arrSize; i++) { //Copy the current values that exist in the dna array

						temp[i].id = dna[i].id;

						currentStrandSize = 0;
						for (int j = 0; dna[i].strand[j] != '\0'; j++) { //Count the dna[i].strand size of char array
							currentStrandSize++;
						}
						temp[i].strand = nullptr;
						temp[i].strand = new char[currentStrandSize + 1];
						strCpy(temp[i].strand, dna[i].strand);

						//Now that all the current strand values are stored in the temp (bigger array) we can delete the memory stored in each strand array of dna
						delete[] dna[i].strand;
						dna[i].strand = nullptr;
					}
					//We need to store the new value that didn't previously fit in dna array but now fits in temp array
					temp[arrSize].id = id; //id of he current read record

					//Allocate memory for dynamic array that stores the DNA strand
					temp[arrSize].strand = nullptr;
					temp[arrSize].strand = new char[strandSize + 1];
					strCpy(temp[arrSize].strand, strand); //strand of the current read record

					numDNAs++;

					delete[] dna; //We can now delete the dna array, because we've copied the values in temp.
					dna = temp; //We use the dna pointer to point to temp address, so we can access that memory (where we can find our values)

					arrSize = (arrSize + size); //Remember that now our dna array is double the size

				}
				else {
					//If dna array has space available to store the i record.
					dna[numDNAs].id = id;
					dna[numDNAs].strand = nullptr;
					dna[numDNAs].strand = new char[strandSize + 1];
					strCpy(dna[numDNAs].strand, strand);

					numDNAs++;
				}
			}
			result = true;
		}

		return result;
	}

	//Initialize variables
	void initialize(int allocSize)
	{
		numDNAs = 0;
		arrSize = allocSize;
		size = allocSize;

		dna = new DNA[allocSize]; //Create the dna array with the size that was initially set as an argument when calling the function
	}

	//Search for matching strands on the dna array based on the string given by user
	bool read(const char* subDNA)
	{
		bool result;
		int matchStrandSize = 0;

		for (int i = 0; i < numDNAs; i++) { //We need to count how many matches we have.

			const char* stringFound = strStr(dna[i].strand, subDNA); //Compare if some strand in our dna array matches the subDNA entered by the user
			if (stringFound != nullptr) {
				matchCount++;
			}
		}

		
		matchedStrands = new DNA[matchCount]; //Create the array with the size of matched strands
		matchCount = 0; //We need to start counting from 0 again because matchCount will be our index number

		for (int i = 0; i < numDNAs; i++) { //We need to go again through every element, but now to copy the values to our new array for found strands

			const char* stringFound = strStr(dna[i].strand, subDNA); //Compare if some strand in our dna array matches the subDNA entered by the user
			if (stringFound != nullptr) {
				matchedStrands[matchCount].id = dna[i].id;

				//cout << "TEST! MATCHED STRAND:" << dna[i].strand;

				matchStrandSize = 0;
				for (int j = 0; dna[i].strand[j] != '\0'; j++) { //Count the dna[i].strand size of char array
					matchStrandSize++;
				}
				matchedStrands[matchCount].strand = nullptr;
				matchedStrands[matchCount].strand = new char[matchStrandSize + 1]; //Create new char array for this matched strand //I NEED TO ADD 2 OR MORE TO WORK!
				strCpy(matchedStrands[matchCount].strand, dna[i].strand);

				matchCount++;
			}
		}

		if (matchCount > 0) {
			result = true;
		}
		else {
			result = false;
		}

		return result;
	}

	bool compare(DNA matchedA, DNA matchedB)
	{
		if (matchedA.id < matchedB.id)
			return true;
		else
			return false;
	}

	//Sort the matched records in ascending order. My Bubble Sort code only works for the smaller .csv files.
	void sort()
	{
		//struct DNA tempSort = { 0 };
		//int i, j, sortStrandSize = 0;
		
		std::sort(matchedStrands, matchedStrands + matchCount, compare); //I got help from a website in order to create this function and using std::sort.

		//for (i = matchCount - 1; i > 0; i--) {
		//	for (j = 0; j < i; j++) {
		//		if (matchedStrands[j].id > matchedStrands[j + 1].id) { //If the next right number is bigger than the current, then we need to swipe positions

		//			//Copy the values of the current position to the temp DNA array
		//			tempSort.id = matchedStrands[j].id;

		//			sortStrandSize = 0;
		//			for (int c = 0; matchedStrands[j].strand[c] != '\0'; c++) { //Count the matchedStrand[j].strand size of char array
		//				sortStrandSize++;
		//			}
		//			tempSort.strand = nullptr;
		//			tempSort.strand = new char[sortStrandSize + 1]; //Create new char array for this strand
		//			strCpy(tempSort.strand, matchedStrands[j].strand);

		//			//Copy the values of the next right element to the current element position
		//			matchedStrands[j].id = matchedStrands[j + 1].id;
		//			strCpy(matchedStrands[j].strand, matchedStrands[j + 1].strand);

		//			//Copy the values that are stored in temp to the next right position
		//			matchedStrands[j + 1].id = tempSort.id;
		//			strCpy(matchedStrands[j + 1].strand, tempSort.strand);
		//			

		//			//Delete the strand created in the temp DNA array
		//			delete[] tempSort.strand;
		//			tempSort.strand = nullptr;
		//		}
		//	}
		//}
	}
	

	//Display the matches from the matchedStrands DNA array which is now sorted
	void displayMatches()
	{
		cout << matchCount << " matches found:" << endl;
		for (int i = 0; i < matchCount; i++) {
			cout << i + 1 << ") " << matchedStrands[i].id << ":" << endl;
			cout << matchedStrands[i].strand << endl;
			cout << "======================================================================" << endl;
		}		
	}

	void deallocate()
	{
		//Delete the memory allocated for the strand chars in the matchedStrand Array
		for (int i = 0; i < matchCount; i++) {
			delete[] matchedStrands[i].strand;
			matchedStrands[i].strand = nullptr;
		}

		//Delete the memory allocated for the matchedStrands Array
		delete[] matchedStrands;
		matchedStrands = nullptr;
	}

	void endSearch()
	{
		//Delete the memory allocated for the matchedStrands Array
		delete[] matchedStrands;
		matchedStrands = nullptr;

		//Delete the memory allocated for the strand chars in the dna Array
		for (int i = 0; i < numDNAs; i++) {
			delete[] dna[i].strand;
		}	

		//Delete the memory allocated for the dna array itself
		delete[] dna;
		dna = nullptr;

		fclose(file);

		cout << "DNA Search Program Closed." << endl;
	}

}