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
Date:			Jan 30th, 2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "DNA.h"
#include "cStrTools.h"

using namespace std;

namespace sdds
{
	//File scoped variables
	static struct DNA* dna = nullptr; //The DNA Pointer 
	static int numDNAs; //Number of DNA strands currently in the dynamic array of cars
	static int arrSize; //Current allocation size of the array. It is the max size that the numDNAs can grow up to (before realocation for expansion)
	static int size; //Holds the memory allocation and expansion size

	static int strandArrSize;

	static FILE* file = NULL; //ALLOCATED DATA

	struct DNA* temp = nullptr;
	

	struct DNA* foundRecords = nullptr; 
	static int matchCount;

	struct DNA tempSort = { 0 };



	bool beginSearch(const char* filename)
	{
		bool result = false;;
		int c;
		char strand[MAX_STRAND_CHARS] = { 0 };
		struct DNA recordDNA = { 0 };
		
		initialize(2); //TEST size of 2. Initialize a dynamic array of size 2

		//FILE* file = NULL; //Allocate memory for file pointer 
		file = fopen(filename, "r"); //Open file in reading mode

		if (file != NULL) {
			//Scan each record and assign the value to each variable. Fill the temp array.
			while (fscanf(file, "%d,%[^\n]", &recordDNA.id, strand) != EOF) {
				//i++;	

				for (c = 0; strand[c] != '\0'; c++) {
					; //Get the number of chars in the static array
				}

				strandArrSize = c + 1;

				recordDNA.strand = nullptr;
				recordDNA.strand = new char[strandArrSize]; //ALLOCATED DATA
				strCpy(recordDNA.strand, strand); //Copy the value to the dynamic array for the strand

				saveData(recordDNA);

				delete[] recordDNA.strand;
				recordDNA.strand = nullptr;

				result = true;
			}

		}
		else {
			result = false;
		}

		return result;
	}

	//Initialize variables
	void initialize(int allocSize)
	{
		numDNAs = 0;
		arrSize = allocSize;
		size = allocSize;

		dna = new DNA[allocSize]; //ALLOCATED DATA
	}


	//Saves the data for each DNA record
	void saveData(const DNA& recordDNA)
	{
		
		if (numDNAs == arrSize) { //DNA dynamic array is full, we need to enlarge it
			//struct DNA* temp = nullptr; 
			temp = new DNA[arrSize + size]; //ALLOCATED DATA

			for (int i = 0; i < arrSize; i++) {

				temp[i].id = dna[i].id;

				//Allocate memory for dynamic array that stores the DNA strand
				temp[i].strand = nullptr;
				temp[i].strand = new char[strandArrSize];

				//Count again for the real size of the dna.strand variable - AGHA

				strCpy(temp[i].strand, dna[i].strand);

				delete[] dna[i].strand;
				dna[i].strand = nullptr;
			}
			temp[arrSize].id = recordDNA.id;

			//Allocate memory for dynamic array that stores the DNA strand
			temp[arrSize].strand = nullptr;
			temp[arrSize].strand = new char[strandArrSize];
			strCpy(temp[arrSize].strand, recordDNA.strand);

			numDNAs++;

			delete[] dna;


			dna = temp;

			

			arrSize = (arrSize + size);




		}
		else {

			dna[numDNAs].id = recordDNA.id;

			//Allocate memory for dynamic array that stores the DNA strand
			dna[numDNAs].strand = nullptr;
			dna[numDNAs].strand = new char[strandArrSize];
			strCpy(dna[numDNAs].strand, recordDNA.strand);

			numDNAs++;

		}
		
	}

	bool read(const char* subDNA)
	{
		bool result = false;
		int foundStrandSize = 0;
		matchCount = 0;

		for (int i = 0; i < numDNAs; i++) { //For Loop used to count matched records

			//Compare if there is a match between a DNS and the word entered by the user
			const char* stringFound = strStr(dna[i].strand, subDNA);

			if (stringFound == nullptr) {
				; //String was not found in this record
			}
			else {
				matchCount++;
			}
		}

		foundRecords = new DNA[matchCount]; //New dynamic array for records matching the subDNA
		

		matchCount = 0;
		for (int i = 0; i < numDNAs; i++) { //For loop used to copy the values from the original DNA array o the newly created foundRecords dynamic array
			const char* stringFound = strStr(dna[i].strand, subDNA);

			if (stringFound == nullptr) {
				;//String was not found in this record
			}
			else {

				foundRecords[matchCount].id = dna[i].id;

				for (int j = 0; dna[i].strand[j] != '\0'; j++) {
					foundStrandSize++; // Count chars in subDNA array based on the i element that the subDNA was found on the original DNA array
				}

				//Allocate memory for dynamic array that stores the DNA strand
				foundRecords[matchCount].strand = nullptr;
				foundRecords[matchCount].strand = new char[foundStrandSize + 1];
				strCpy(foundRecords[matchCount].strand, dna[i].strand);

				matchCount++;
			}
		}

		if (matchCount > 0) {
			result = true;
		}

		return result;
	}

	void sort()
	{
		
		//struct DNA* tempSort = nullptr;
		//tempSort = new DNA[matchCount];
		//struct DNA tempSort = { 0 };

		//struct DNA tempSort = { 0 };
		int i, j, charCounter = 0;

		//Using Bubble Sort Algorithm
		for (i = matchCount - 1; i > 0; i--) {
			for (j = 0; j < 1; j++) {
				if (foundRecords[j].id > foundRecords[j + 1].id) {
					tempSort.id = foundRecords[j].id;
					
					for (int ch = 0; foundRecords[j].strand[ch] != '\0'; ch++) {
						charCounter = ch; // Count chars in DNA strand of j found record
					}
					tempSort.strand = nullptr;
					tempSort.strand = new char[charCounter + 1];
					tempSort.strand = foundRecords[j].strand;
					//strCpy(tempSort.strand, foundRecords[j].strand);

					foundRecords[j].id = foundRecords[j + 1].id;
					foundRecords[j].strand = foundRecords[j + 1].strand;
					//strCpy(foundRecords[j].strand, foundRecords[j + 1].strand);

					foundRecords[j + 1].id = tempSort.id;
					foundRecords[j + 1].strand = tempSort.strand;
					//strCpy(foundRecords[j + 1].strand, tempSort.strand);

					
					//TESTING DEALLOCATION
					//delete[] tempSort.strand;
					//tempSort.strand = nullptr;


				}

		
			}
			
			
		}	

	}

	void displayMatches()
	{
		cout << matchCount << " matches found:" << endl;
		for (int i = 0; i < matchCount; i++) {
			cout << i + 1 << ") " << foundRecords[i].id << ":" << endl;
			cout << foundRecords[i].strand << endl;
			cout << "======================================================================" << endl;
			//delete[] foundRecords[i].strand;
			//foundRecords[i].strand = nullptr;
		}
		//delete[] tempSort.strand;
		//tempSort.strand = nullptr;

		
	}

	void deallocate()
	{


	
		delete[] tempSort.strand;
		tempSort.strand = nullptr;
		// 
		//for (int i = 0; i < matchCount; i++) {
			//delete[] dna[i].strand;
			//delete[] temp[i].strand;
			//delete[] foundRecords;
			//delete[] tempSort[i].strand;
		//}

		//delete[] foundRecords;
		//foundRecords = nullptr;

		//delete[] foundRecords;
		//foundRecords = nullptr;
		
		

	}

	void endSearch()
	{
		

		for (int i = 0; i < numDNAs; i++) {
			delete[] dna[i].strand;
		}

		for (int i = 0; i < matchCount; i++) {
			delete[] foundRecords[i].strand;
			foundRecords[i].strand = nullptr;
		}

		for (int i = 0; i < (arrSize + size); i++) {
			delete[] temp;
			temp = nullptr;

		}
		
		fclose(file);

		
		

		
		cout << "DNA Search Program Closed." << endl;
	}

}