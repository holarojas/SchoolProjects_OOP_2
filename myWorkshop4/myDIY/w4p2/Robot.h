/* ------------------------------------------------------
Workshop 4 Part 2
Module: Robot
Filename: Robot.H
Version 1.1
Revision History
-----------------------------------------------------------
Student Name:	Martha Rocio Rojas Martinez
Email:			mrrojas-martinez@myseneca.ca
Student ID:		112073218
Date:			13/Feb/22
-----------------------------------------------------------*/
#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H

namespace sdds
{
	class Robot
	{
	private:
		char* mName;
		char* mLocation;
		double mWeight;
		double mWidth;
		double mHeight;
		double mSpeed;
		bool mDeployed;

		const char* getLocation() const; //To return the robot location

	public:
		Robot(); //Default constructor for a robot with no information to set the robot into an empty state
		Robot(const char* inName, const char* inLocation, double inWeight, double inWidth, double inHeight, double inSpeed, bool inDeployed); //To initialize the robot information
		~Robot(); //Destructor, must handle any potential memory leak

		Robot& set(const char* inName, const char* inLocation, double inWeight, double inWidth, double inHeight, double inSpeed, bool inDeployed); //To set the robot information
		Robot& setLocation(const char* inLocation);
		Robot& setDeployed(double inDeployed); //To set the robot deployment status (true or false)

		const char* getName() const; //To return the robot name
		double speed() const; //To return the speed of the robot
		bool isValid() const; //To return if the robot information is valid
		bool isDeployed() const; //To return if a robot is deployed

		void displayTitle() const; //To display the title line
		void display() const; //To display the information
		void displayTitleNo2Lines() const; //To display the title line
	};

	int conrtolRooomReport(const Robot robot[], int num_robots); //Receives an array of robots and prints a report of their info and a summary that prints the total number of deployed robots and the info of the fastest robot in the array
}


#endif 

