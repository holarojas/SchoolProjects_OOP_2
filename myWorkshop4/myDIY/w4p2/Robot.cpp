/* ------------------------------------------------------
Workshop 4 Part 2
Module: Robot
Filename: Robot.cpp
Version 1.1
Revision History
-----------------------------------------------------------
Student Name:	Martha Rocio Rojas Martinez
Email:			mrrojas-martinez@myseneca.ca
Student ID:		112073218
Date:			13/Feb/22
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <iomanip>
#include "Robot.h"

using namespace std;

namespace sdds
{
	Robot::Robot()
	{
		//Set the robot into an empty state
		mName = nullptr;
		mLocation = nullptr;
		mWeight = 0.0;
		mWidth = 0.0;
		mHeight = 0.0;
		mSpeed = 0.0;
		mDeployed = false;
	}

	Robot::Robot(const char* inName, const char* inLocation, double inWeight, double inWidth, double inHeight, double inSpeed, bool inDeployed)
	{
		int strCountName = 0, strCountLoc = 0;

		//Take data from inName and copy it to the dynamic char array
		for (size_t j = 0; j < strlen(inName); j++) { 
			strCountName++;
		}
		mName = new char[strCountName + 1];
		strcpy(mName, inName);

		//Take data from inLocation and copy it to the dynamic char array
		for (size_t j = 0; j < strlen(inLocation); j++) {
			strCountLoc++;
		}
		mLocation = new char[strCountLoc + 1];
		strcpy(mLocation, inLocation);

		//Copy the rest of input values to the data members
		mWeight = inWeight;
		mWidth = inWidth;
		mHeight = inHeight;
		mSpeed = inSpeed;
		mDeployed = inDeployed;

	}

	Robot& Robot::setLocation(const char* inLocation)
	{
		int strCountLoc = 0;

		for (size_t j = 0; j < strlen(inLocation); j++) {
			strCountLoc++;
		}
		mLocation = new char[strCountLoc + 1];
		strcpy(mLocation, inLocation);

		return *this;
	}

	Robot& Robot::setDeployed(double inDeployed)
	{
		mDeployed = inDeployed;

		return *this;
	}

	Robot& Robot::set(const char* inName, const char* inLocation, double inWeight, double inWidth, double inHeight, double inSpeed, bool inDeployed)
	{
		//Deallocate dynamic memory
		delete[] mName;
		delete[] mLocation;
		mName = nullptr;
		mLocation = nullptr;

		int strCountName = 0;// strCountLoc = 0;

		//Take data from inName and copy it to the dynamic char array
		for (size_t j = 0; j < strlen(inName); j++) {
			strCountName++;
		}
		mName = new char[strCountName + 1];
		strcpy(mName, inName);

		//Take data from inLocation and copy it to the dynamic char array
		setLocation(inLocation);
		
		//Copy the rest of input values to the data members
		mWeight = inWeight;
		mWidth = inWidth;
		mHeight = inHeight;
		mSpeed = inSpeed;
		setDeployed(inDeployed);

		return *this;
	}

	const char* Robot::getName() const
	{
		return mName;
	}

	const char* Robot::getLocation() const
	{
		return mLocation;
	}

	bool Robot::isDeployed() const
	{
		return mDeployed;
	}

	bool Robot::isValid() const
	{
		bool valid = false;
		if (strcmp(mName, "Broken") == 0 || mName == nullptr) {
			valid = false;
		}
		else {
			valid = true;
		}

		return valid;
	}

	double Robot::speed() const
	{
		return mSpeed;
	}

	void Robot::displayTitle() const
	{
		cout << setw(55) << "                        ------ Robot Control Room -----" << endl;
		cout << setw(59) << "                    ---------------------------------------" << endl;

		cout << "| ";
		cout << setw(11) << left << "Robot ID";
		cout << "| ";
		cout << setw(15) << left << "Location";
		cout << " |";
		cout << setw(7) << right << "Weight";
		cout << " |";
		cout << setw(7) << right << "Width";
		cout << " |";
		cout << setw(7) << right << "Height";
		cout << " |";
		cout << setw(7) << right << "Speed";
		cout << " |" << setw(9) << right << "Deployed";
		cout << " |";
		cout << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
	}

	void Robot::displayTitleNo2Lines() const
	{
		cout << "| ";
		cout << setw(11) << left << "Robot ID";
		cout << "| ";
		cout << setw(15) << left << "Location";
		cout << " |";
		cout << setw(7) << right << "Weight";
		cout << " |";
		cout << setw(7) << right << "Width";
		cout << " |";
		cout << setw(7) << right << "Height";
		cout << " |";
		cout << setw(7) << right << "Speed";
		cout << " |" << setw(9) << right << "Deployed";
		cout << " |";
		cout << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
	}

	void Robot::display() const
	{
		cout.setf(ios::fixed);
		cout.precision(1); //To print 1 decimal

		cout << "| ";
		cout << setw(11) << left << mName;
		cout << "| ";
		cout << setw(16) << left << mLocation;
		cout << "| ";
		cout << setw(6) << right << mWeight;
		cout << " |";
		cout << setw(7) << right << mWidth;
		cout << " |";
		cout << setw(7) << right << mHeight;
		cout << " |";
		cout << setw(7) << right << mSpeed;
		if (mDeployed == false) {
			cout << " | " << setw(9) << left << "NO";
		}
		else {
			cout << " | " << setw(9) << left << "YES";
		}
		cout << "|";
		cout << endl;

	}


	Robot::~Robot()
	{
		delete[] mName;
		delete[] mLocation;
		mName = nullptr;
		mLocation = nullptr;
	}

	int conrtolRooomReport(const Robot robot[], int num_robots)
	{
		int invalidRecord = 0, num_deployed = 0, fastest_idx = 0;;

		robot->displayTitle();
		for (int i = 0; i < num_robots; i++) {
			if (robot[i].getName() == nullptr) {
				invalidRecord = i;
				i = num_robots;//Stop displaying the info
			}
			else {
				if (strcmp(robot[i].getName(), "Broken") == 0) {
					invalidRecord = i;
					i = num_robots;//Stop displaying the info
				}
				else {
					robot[i].display(); //Print this valid record
					invalidRecord = -1;
					if (robot[i].isValid() == true) {
						if (robot[i].isDeployed() == true) {
							num_deployed++;
						}
					}
					for (int x = 0; x < num_robots; x++) {
						if (robot[i].speed() > robot[x].speed()) {
							fastest_idx = i;
						}
						else if (robot[x].speed() > robot[i].speed()) {
							fastest_idx = x;
						}
					}
				}
			}	
		}
		if (invalidRecord == -1) {

			cout << "|=============================================================================|" << endl;
			cout << left << "| SUMMARY:                                                                    |" << endl;
			cout << left << "| " << setw(3) << num_deployed << "robots are deployed.                                                     |" << endl;
			cout << "| The fastest robot is:                                                       |" << endl;
			robot[0].displayTitleNo2Lines();

			robot[fastest_idx].display();

			cout << "|=============================================================================|" << endl;	
		}

		return invalidRecord;
	}
}