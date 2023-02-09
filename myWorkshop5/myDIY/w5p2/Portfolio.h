/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.h
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials        Date           Reason
F.S.            07/02/2022     Peer Review
Martha Rojas    20/02/2022     Workshop #5
Student ID: 112073218
-----------------------------------------------------------*/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>

namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;

      void emptyPortfolio(); //Safe empty state

   public:
       Portfolio(); //Constructor
       Portfolio(double, const char*, char); //3 arguments constructor

       std::ostream& display() const;
       void dispPortfolio() const;


       //TYPE CONVERSION OPERATORS
       operator double() const;
       operator const char*() const;
       operator char() const;
       explicit operator bool();

       //UNARY MEMBER OPERATORS
       bool operator~() const; 
       //BINARY MEMBERS OPERATORS
       Portfolio& operator+=(double);
       Portfolio& operator-=(double);
       Portfolio& operator<<(Portfolio&);
       Portfolio& operator>>(Portfolio&);
       
   };
   //HELPER OPERATORS
   double operator+(const Portfolio&, const Portfolio&);
   double operator+=(double&, const Portfolio&);
}
#endif // SDDS_Portfolio_H_