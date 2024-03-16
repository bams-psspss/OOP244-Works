#ifndef SENECA_MENU_H
#define SENECA_MENU_H


namespace seneca {
	class Menu {
		char* m_text;
		int m_menuNum;
		int m_tabsNum;

	public:
		Menu(const char* menuContent, int numberOfTabs = 0);
		virtual ~Menu();

	};

	

	 

}




#endif SENECA_MENU_H