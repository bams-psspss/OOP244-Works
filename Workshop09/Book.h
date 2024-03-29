/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:		29 / 03 / 2024
**************************************************/
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <iostream>
#include "LibraryItem.h"

namespace seneca {
	class Book : public LibraryItem {
		char* m_author{};
	public:
		Book(const char* title, const int year, const char* author);
		Book(const Book& books);
		Book& operator=(const Book& books);

		~Book();

		std::ostream& display(std::ostream& ostr = std::cout) const;

		bool operator> (const Book& other) const;
	};
}





#endif
