/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace seneca {
	void Menu::printIndent() const
	{
		for (int i = 0; i < m_indent; i++) {
			cout << "   ";
		}
	}
	Menu::Menu(const char* menuContent, int numberOfTabs)
	{
		size_t i{};
		m_text = new char[strlen(menuContent) + 1];

		strcpy(m_text, menuContent);
		m_indent = numberOfTabs;
		m_menuNum = 0;

		for (i = 0; menuContent[i] ; i++)
		{
			if (menuContent[i] == '\n')
			{
				m_menuNum++;
			}
		}

	}

	Menu::~Menu()
	{
		delete[] m_text;
	}

	void Menu::printMenu()const
	{
		int i{};
		printIndent();
		for (i = 0; m_text[i]; i++) {
			cout<< m_text[i];
			if (m_text[i] == '\n') printIndent();
		}
		cout << endl;
		printIndent();
		cout << "0- Exit" << endl;
		printIndent();
		cout << "> ";

	}
	int& Menu::operator>>(int& Selection)
	{
		printMenu();
		Selection = U.getInt(0, m_menuNum);
		return Selection;
	}
}