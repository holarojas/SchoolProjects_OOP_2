/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.cpp
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
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Portfolio.h"

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
       emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && ( type == 'V' || type == 'G' || type == 'I') ) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const{
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Value: ";
            cout.width(10);
            cout << double(*this);
            cout << " | ";
            cout << " Type: ";
            cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (double(*this)) { //Added double cast
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    Portfolio::operator double() const
    {
        return m_value;
    }

    Portfolio::operator const char*() const
    {
        return m_stock;
    }

    Portfolio::operator char() const
    {
        return m_type;
    }

    Portfolio::operator bool()
    {
        return (m_type == 'G' || m_type == 'V' || m_type == 'I');
    }

    Portfolio& Portfolio::operator+=(double rValue)
    {
        //A double can be added to the value of the Portfolio m_value using += operator. 
        //If the Portfolio does not evaluate TRUE or the double value is negative, the action is ommited.
        if (bool(*this) == true && rValue > 0) {
            m_value = m_value + rValue;
        }

        return *this;
    }

    Portfolio& Portfolio::operator-=(double rValue)
    {
        //A double can be subtracted from the value of the Portfolio m_value using -= operator.
        //If the Portfolio does not evaluate TRUE or the double value is negative, the action is ommitted.
        if (bool(*this) == true && rValue > 0) {
            m_value = m_value - rValue;
        }

        return *this;
    }

    bool Portfolio::operator~() const
    {
        //Will return true if m_value is negative.
        //This operator can not modify the Portfolio object.
        bool result = false;
        if (m_value < 0) {
            result = true;
        }
        else {
            result = false;
        }
        return result;
    }

    Portfolio& Portfolio::operator<<(Portfolio& rPortf)
    {
        //Move m_value from Portfolio in the right to the left.
        //After this operation, the total investment value of the Portfolio on the left will be the sum of both Portfolios.
        //The Portfolio on the right is set to empty.
        //If any of the two portfolios don't evaluate to TRUE, no action should be taken.
        if (*this && rPortf) {
            m_value = m_value + rPortf.m_value;
            rPortf.emptyPortfolio();
        }
        return *this;
    }

    Portfolio& Portfolio::operator>>(Portfolio& rPortf)
    {
        //Move m_value from Portfolio in the left to the right.
        //After this operation, the total investment value of the Portfolio in the right will be the sum of both Portfolios.
        //The Portfolio on the left is set to empty.
        //If any of the two portfolios does not evaluate to TRUE, no actions should be taken.
        if (*this && rPortf) {
            rPortf.m_value = rPortf.m_value + m_value;
            emptyPortfolio();
        }
        return *this;
    }



    double operator+(const Portfolio& lPortf, const Portfolio& rPortf)
    {
        double sum = 0;
        //The double value should be the sum of th m_values of the two Portfolios.
        //If any of the two Portfolios don't evaluate to TRUE, then zero is returned.
        if (double(lPortf) && double(rPortf)) {
            sum = (double)(lPortf)+(double)(rPortf);
        }
        else {
            sum = 0;
        }

        return sum;
    }

    double operator+=(double& lDouble, const Portfolio& rPortf)
    {
        //The value of the right operand (Portfolio) should be added to the left operand (double reference).
        //Then, the value of the double reference is returned.
        lDouble = lDouble + (double)(rPortf);
        return lDouble;
    }
}