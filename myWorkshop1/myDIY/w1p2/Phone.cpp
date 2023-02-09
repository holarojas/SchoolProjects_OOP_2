/* ------------------------------------------------------
Workshop 1 part 2
Module: Phone
Filename: Phone.cpp
Version 1
Author Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date: Jan 22th, 2022

Name:           Martha Rocio Rojas Martinez
Email:          mrrojas-martinez@myseneca.ca
Student ID:     112073218

-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Phone.h"
#include "cStrTools.h"

using namespace std;

namespace sdds
{
	void phoneDir(const char* programTitle, const char* fileName)
	{
		displayTitle(programTitle);
		readFile(programTitle, fileName);
	}

	void readFile(const char* title, const char* name)
	{
		int i = 0, n, j;
		
		struct PhoneDir tempDir[MAX_RECORDS] = { 0 };
		struct PhoneDir lowerDir[MAX_RECORDS] = { 0 };
		
		FILE* file = NULL; //Allocate memory for pointer
		file = fopen(name, "r"); //Open file in reading mode

		if (file != NULL) {
			//Scan each record and assign the value to each variable. Fill the temp array.
			while (i < MAX_CHARS && fscanf(file, "%[^\t]\t%s\t%s\t%s\n", tempDir[i].name, tempDir[i].area, tempDir[i].prefix, tempDir[i].number) != EOF) {

				i++;
			}		
			for (n = 0; n < i; n++) {
				//Make lower case every character in every name and store it in the lower case array.
				for (j = 0; tempDir[n].name[j] != '\0'; j++) {
					lowerDir[n].name[j] = toLower(tempDir[n].name[j]);
				}
			}

			//Get data from the user. Ask for the key word to find.
			getInputData(tempDir, lowerDir);
		}
		else {
			cout << name << " file not found!" << endl;
			cout << "Thank you for using " << title << " directory." << endl;
		}
		fclose(file);
	}

	void displayTitle(const char* title)
	{
		cout << title << " phone direcotry search" << endl;
		cout << "-------------------------------------------------------" << endl;
	}

	void getInputData(struct PhoneDir* dir, struct PhoneDir* lower)
	{
		int i;
		bool flag = false;
		char word[MAX_CHARS] = { 0 };
		
		do {
			cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
			cout << "> ";
			cin >> word;

			if (strCmp(word, "!") != 0) {
				
				//Make word all lowercase
				for (i = 0; i < strLen(word); i++) {
					word[i] = toLower(word[i]);
				}

				//Search for the word in the Phone Dir
				search(dir, lower, word);
			}
			else {
				flag = true;
				cout << "Thank you for using Star Wars directory." << endl;			
			}
		} while (!flag);		
	}

	void search(const struct PhoneDir* dir, const struct PhoneDir* lower, char* toFind)
	{
		int recordsFound = 0, i;
		int records[MAX_RECORDS] = { 0 };
		int useVar; //I added this variable because I was getting the error: 
					//warning: variable 'records' set but not used [-Wunused-but-set-variable]  int records[MAX_RECORDS] = { 0 };
					//in matrix.

		
		//Look at each entry in the lower case Phone Dir
		for (i = 0; strCmp(lower[i].name,"") != 0; i++) {
			
			//Compare if there is a match between a name in the Phone Dir and the word entered by the user
			const char* foundAddress = strStr(lower[i].name, toFind);

			if (foundAddress == nullptr) {
				//String was not found in this record
			}
			else {
				//String was found in the i element of the lower case Phone Dir
				//Store the element number in the records array
				useVar = records[recordsFound];
				records[useVar] = i;
				recordsFound++;
				//Print the result records but using the regular Phone Dir
				cout << dir[i].name << ": (" << dir[i].area << ") " << dir[i].prefix << "-" << dir[i].number << endl;
			}
		}
	}
}