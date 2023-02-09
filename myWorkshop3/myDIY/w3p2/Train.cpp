/* ------------------------------------------------------
Workshop 3 part 2
Module: Train
Filename: Train.cpp
Version 1.1
Revision History
-----------------------------------------------------------
Student Name:	Martha Rocio Rojas Martinez
Email:			mrrojas-martinez@myseneca.ca
Student ID:		112073218
Date:			06/Feb/22
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <string.h>
#include "Train.h"

using namespace std;


namespace sdds
{

	void Train::set(const char* inName, int inNoPeople, double inSpeed)
	{
		//Condition to set the name Train member
		if (inName != nullptr && strlen(inName) > 0) {
			strncpy(name, inName, MAX_NAME_LEN);
		}
		else {			
			strcpy(name, "XXXX"); //Safe-empty state for name member.
		}

		//Condition to set the noPeople Train member
		if (inNoPeople > 0 && inNoPeople <= MAX_PEOPLE) {
			noPeople = inNoPeople;
		}
		else {
			noPeople = 1; //Safe-empty state for name member. I decided 1 because there must be a driver
		}

		//Condition to set the speed Train member
		if (inSpeed > 0 && inSpeed <= MAX_SPEED) {
			speed = inSpeed;
		}
		else {
			speed = 20.0; //Safe-empty state for name member. I decided 20km/h as the default value for speed
		}

	}

	bool Train::isSafeEmpty() const
	{
		bool result = false;
		if (strcmp(name, "XXXX") == 0 ) { //Data Member I chose to hold the special value that identifies an empty state
			result = true;
		}
		else {
			result = false;
		}

		return result;
	}

	void Train::display() const
	{
		cout.setf(ios::fixed);
		cout.precision(2); //To print 2 decimals

		if (!isSafeEmpty())
		{
			cout << "NAME OF THE TRAIN : " << name << endl;
			cout << "NUMBER OF PEOPLE  : " << noPeople << endl;
			cout << "SPEED             : " << speed << " km/h" << endl;
		}
		else {
			cout << "Safe Empty State!" << endl;
		}
	}

	bool Train::loadPeople(int inNoPeople)
	{
		bool result = false;
		if (!isSafeEmpty()) {
			noPeople += inNoPeople; //Add (or substract) the amount of people the user specified as input
			if (noPeople >= MAX_PEOPLE) { //Don't go past the max value
				noPeople = MAX_PEOPLE;
			}
			else if (noPeople <= 0) { //Don't go below zero
				noPeople = 0;
			}
		}
		else {
			result = true;
		}

		return result;
	}

	bool Train::changeSpeed(double inSpeed)
	{
		bool result = false;

		if (!isSafeEmpty()) {
			speed += inSpeed; //Add (or substract) the amount of speed the user specified as input
			if (speed >= MAX_SPEED) {//Don't go past the max value
				speed = MAX_SPEED;
			}
			else if (speed <= 0) {//Don't go below zero
				speed = 0;
			}
		}
		else {
			result = true;
		}

		return result;
	}

	Train::Train()
	{
		//Empty safe-state values
		strcpy(name, "XXXX");
		noPeople = 1;
		speed = 20.0;		
	}

	/*Train::Train(char* n, int p, double s)
	{
		//Initializing values using set logic rules.
		set(n, p, s); 
	}
	*/
	
	Train::~Train()
	{
		; //Class' destructor
	}

	int Train::getPeopleVal() //Member function created to access to the value of the noPeople data member from a global function.
	{
		int peopleVal = this->noPeople;
		return peopleVal;
	}

	int transfer(Train& first, Train& second) //Transfer is a global function so it does not have access to Train object's data members. That's why I created the getPeopleVal() function, as that is a member function it can get that value and then pass it to the global function.
	{
		int result = 0;
		int capacity = 0;
		
		if (first.getPeopleVal() >= 0 && second.getPeopleVal() <= MAX_PEOPLE) {
			if (second.getPeopleVal() == 0) {
				//Nobody will transfer, there is no people on train 2
			}
			else {
				capacity = MAX_PEOPLE - first.getPeopleVal();
				first.loadPeople(capacity);
				second.loadPeople(-capacity);
				result = capacity;
			}

		}
		if (first.isSafeEmpty() || second.isSafeEmpty()) {
			result = -1;
		}
		return result;
	}
}