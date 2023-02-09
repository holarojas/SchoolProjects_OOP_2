/* ------------------------------------------------------
Workshop 9 part 1
Module: HtmlText
Filename: HtmlText.cpp
Version 1.1
Author: Martha Rojas
Student ID: 112073218
Date: March 31st, 2022
Revision History
-----------------------------------------------------------
Date       Reason
22/03/31   First version
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "HtmlText.h"

using namespace std;
namespace sdds
{
	//Default Constructor
	HtmlText::HtmlText()
	{
		m_title = nullptr;
	}

	//Constructor 1 Argument
	HtmlText::HtmlText(const char* title)
	{
		m_title = nullptr;
		delete[] m_title;

		if (title == nullptr) {
			m_title = nullptr;
		}
		else {
			delete[] m_title;
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}

	}

	//Destructor
	HtmlText::~HtmlText()
	{
		delete[] m_title;
		m_title = nullptr;
	}

	//Copy Constructor
	HtmlText::HtmlText(const HtmlText& inObj): Text(inObj)
	{
		m_title = nullptr;
		delete[] m_title;
		//m_title = nullptr;

		if (inObj.m_title != nullptr) {
			m_title = new char[strlen(inObj.m_title) + 1];
			strcpy(m_title, inObj.m_title);
		}
	}
	HtmlText& HtmlText::operator=(const HtmlText& inObj)
	{
		Text::operator=(inObj); //TRY
		//Make surre this is not a self copy
		if (&(*this) != &inObj) {
			//Do exactly the same as copy constructor			
			delete[] m_title;
			m_title = nullptr;

			if (inObj.m_title != nullptr) {
				m_title = new char[strlen(inObj.m_title) + 1];
				strcpy(m_title, inObj.m_title);
			}
		}
		else {
			delete[] m_title;
			m_title = nullptr;
		}
		return *this;
	}

	//Text::write Override
	//Will convert the text file to a simple HTML format when writing file
	std::ostream& HtmlText::write(std::ostream& ostr) const
	{
		bool multSpaces = false;

		ostr << "<html><head><title>";

		if (m_title != nullptr) {
			ostr << m_title;
		}
		else {
			ostr << "No Title";
		}

		ostr << "</title></head>\n<body>\n";

		if (m_title != nullptr) {
			ostr << "<h1>" << m_title << "</h1>\n";
		}

		int i = 0;
		while (this->operator[](i) != EOF) {
			switch (this->operator[](i)) {
			case ' ':
				if (multSpaces) {
					ostr << "&nbsp;";
				}
				else {
					multSpaces = true;
					ostr << ' ';
				}
				break;
			case '<':
				ostr << "&lt;";
				multSpaces = false;
				break;
			case '>':
				ostr << "&gt;";
				multSpaces = false;
				break;
			case '\n':
				ostr << "<br />\n";
				multSpaces = false;
				break;
			default:
				multSpaces = false;
				ostr << this->operator[](i);
			}
			i++;
		}
		ostr << "</body>\n</html>";
		return ostr;
	}
	
}