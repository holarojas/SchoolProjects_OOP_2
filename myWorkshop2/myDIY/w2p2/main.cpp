/* ------------------------------------------------------
Workshop 2 part 2
Module: N/A
Filename: main.cpp
Version 1
Author    Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Student Name:	Martha Rocio Rojas Martinez
Student ID:		112073218
Date:			Jan 30th, 2022
-----------------------------------------------------------*/

#include <iostream>
#include "cStrTools.h"
#include "DNA.h" //I am using lowercase
using namespace std;
using namespace sdds;
int main()
{
    bool done = false; //Flag to keep in the loop
    char dna[101]; //DNA that the user need to search for
    char filename[256]; //Filename to extract all the hard data
    cout << "Enter DNA data file name: ";
    cin >> filename; // User enters the filename that contains the hard data
        if (beginSearch(filename)) {
        while (!done) {
            cout << "Enter a DNA squence (max 100 chars)" << endl << "> ";
            read(dna, 100);
            if (strCmp(dna, "!") == 0) {
                done = true;
            }
            else {
               if (read(dna)) {
                    sort();
                    displayMatches();
                    deallocate();
               }
                else {
                    cout << "No match found!" << endl;
                }
            }
        }
    endSearch();
    }
    return 0;
}
