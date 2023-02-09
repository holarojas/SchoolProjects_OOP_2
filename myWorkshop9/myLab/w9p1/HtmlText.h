/* ------------------------------------------------------
Workshop 9 part 1
Module: HtmlText
Filename: HtmlText.h
Version 1.1
Author: Martha Rojas 
Student ID: 112073218
Date: March 31st, 2022
Revision History
-----------------------------------------------------------
Date       Reason
22/03/31   First version
-----------------------------------------------------------*/
#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H

#include "Text.h"

namespace sdds
{
	//A Text Class that has a title and can insert the text contents of the class into ostream in simple HTML format
	class HtmlText: public Text
	{
		char* m_title;	//Character pointer for holding the title of the HTML file

	public:
		HtmlText();
		HtmlText(const char* title);
		~HtmlText();
		HtmlText(const HtmlText& inObj);
		HtmlText& operator=(const HtmlText& inObj);
		

		std::ostream& write(std::ostream& ostr) const;
	};
}

#endif