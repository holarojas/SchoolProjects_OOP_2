/* ------------------------------------------------------
Workshop 1 part 2
Module: Phone
Filename: Phone.h
Version 1
Author    Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date: Jan 22th, 2022

Name:           Martha Rocio Rojas Martinez
Email:          mrrojas-martinez@myseneca.ca
Student ID:     112073218

-----------------------------------------------------------*/
#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H

namespace sdds
{
	#define MAX_CHARS 50
	#define MAX_RECORDS 50

	//USING REGULAR CHAR ARRAYS
	struct PhoneDir
	{
		char name[MAX_CHARS];
		char area[MAX_CHARS];
		char prefix[MAX_CHARS];
		char number[MAX_CHARS];
	};

	//Application start using static info from the user
	void phoneDir(const char* programTitle, const char* fileName);

	//Display the Header using program title
	void displayTitle(const char* title);

	//Open the file and extract the data
	void readFile(const char* title, const char* name);

	//Get input string from user
	void getInputData(struct PhoneDir* dir, struct PhoneDir* lower);

	//Logic to find the person
	void search(const struct PhoneDir* dir, const struct PhoneDir* lower, char* toFind);
}

#endif
