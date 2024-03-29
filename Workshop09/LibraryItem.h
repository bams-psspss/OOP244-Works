/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:		29 / 03 / 2024
**************************************************/
#ifndef SENECA_LIBRARYITEM_H
#define SENECA_LIBRARYITEM_H
#include <iostream>

namespace seneca {
	class LibraryItem {
		char* m_title{};
		int m_year{};
	public:
		LibraryItem();
		LibraryItem(const char* title, const int year);

		LibraryItem(const LibraryItem& lib);
		LibraryItem& operator=(const LibraryItem& lib);
		~LibraryItem();

		virtual std::ostream& display(std::ostream& ostr = std::cout) const;
	};
}


#endif // !SENECA_LIBRARYITEM_H
