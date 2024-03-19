/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author   Pattarwan Saravaneeyawong
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SENECA_MENU_H
#define SENECA_MENU_H

namespace seneca {
	class Menu {
		char* m_text = nullptr;
		int m_menuNum{};
		int m_indent{};
		void printIndent()const;
	public:
		Menu(const char* menuContent, int numberOfTabs = 0);
		virtual ~Menu();

		//Cannot copy or assign to other Menu object
		Menu(const Menu&) = delete;

		void printMenu()const;

		int& operator>> (int& Selection);
	};



}

#endif // !SENECA_MENU_H