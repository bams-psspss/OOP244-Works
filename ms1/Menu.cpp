#include <iostream>
#include "Menu.h"

using namespace std;

namespace seneca {
	Menu::Menu(const char* menuContent, int numberOfTabs)
	{
		int i;
		m_text = new char[strlen(menuContent) + 1];
		strcpy(m_text, menuContent);
		
		if (numberOfTabs != 0) {
			m_tabsNum = numberOfTabs;
		}

		for (i = 0; i < strlen(menuContent) + 1; i++) {
			  
		}
	}
	Menu::~Menu()
	{
		delete[] m_text;
	}
}