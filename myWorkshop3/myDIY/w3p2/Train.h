/* ------------------------------------------------------
Workshop 3 part 2
Module: Train
Filename: Train.h
Version 1.1
Revision History
-----------------------------------------------------------
Student Name:	Martha Rocio Rojas Martinez
Email:			mrrojas-martinez@myseneca.ca
Student ID:		112073218
Date:			06/Feb/22
-----------------------------------------------------------*/

#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds
{
	const int MAX_NAME_LEN = 20;
	const int MAX_PEOPLE = 1000;
	const double MAX_SPEED = 320;

	class Train
	{
	private:
		char name[MAX_NAME_LEN + 1];
		int noPeople;
		double speed; //km per hour

	public:
		Train(); //Constructor
		Train(char*, int, double); //Constructor that uses set() function member
		~Train(); //Class' destructor
		void set(const char*, int, double); //Set values for data members
		void display() const; //Sends Train info to standard output
		bool isSafeEmpty() const; //Returns true if the Train object is in a safe empty state, false otherwise.

		bool loadPeople(int); //Used to increase or decrease the number of people on a train.
		bool changeSpeed(double); //Used to increase or decrease the speed of a train.

		int getPeopleVal(); //Get the value for the noPeople data member
	};

	int transfer(Train& first, Train& second); //Moves as many passengers as possible from the second Train to the first Train
}

#endif
