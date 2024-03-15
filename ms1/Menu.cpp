/* Citation and Sources...
Final Project Milestone 1
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

using namespace std;

namespace seneca {
	Menu::Menu(const char* menuContent, int numberOfTabs)
	{
		size_t i;

		delete[] m_text;

		m_text = new char[strlen(menuContent) + 1];

		strcpy(m_text, menuContent);
		m_indent = numberOfTabs;
		m_menuNum = 0;

		for (i = 0; i < (strlen(menuContent) + 1); i++)
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
		m_text = nullptr;
	}

	void Menu::printMenu()
	{
		size_t i;
		size_t j = 0;
		bool notNewline = true;

		//No indent infront
		for (i = 0; i < ((size_t)m_menuNum + 1); i++)
		{
			notNewline = true;
			for (j = j; j < (strlen(m_text) + 1) && notNewline; j++)
			{

				if (m_text[j] == '\n') 
				{
					notNewline = false;

				}
				else
				{
					cout << m_text[j];

				}

			}
			cout << endl;
			if (m_indent != 0 && m_text[j - 1] == '\n')
			{
				cout << " ";
				cout.width(m_indent);
				cout.fill(' ');
				
			}
		}
		if (m_indent != 0)
		{
			cout << " ";
			cout.width(m_indent);
			cout.fill(' ');
		}
		cout << "0- Exit" << endl;
		if (m_indent != 0)
		{
			cout << " ";
			cout.width(m_indent);
			cout.fill(' ');
		}
		cout << "> ";

	}
	int& Menu::operator>>(int& Selection)
	{
		int usrSelection = 0;
		bool valid = true;

		printMenu();
		
		do {
			cin >> usrSelection;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				valid = false;
				cout << "Bad integer value, try again: ";
			}
			else if (usrSelection < 0 || usrSelection > m_menuNum)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				valid = false;
				cout << "Invalid value enterd, retry[0 <= value <= " << m_menuNum << "]: ";
			}
			else if (cin.peek() != '\n') 
			{
				cin.clear();
				cin.ignore(1000, '\n');
				valid = false;
				cout << "Only enter an integer, try again: ";
			}
			else
			{
				valid = true;
			}

		} while (!valid);

		Selection = usrSelection;
		return Selection;
	}
}