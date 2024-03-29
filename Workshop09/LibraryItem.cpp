/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:		29 / 03 / 2024
**************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LibraryItem.h"

using namespace std;
namespace seneca {
	LibraryItem::LibraryItem() : m_title(nullptr), m_year(0) {}

	LibraryItem::LibraryItem(const char* title, const int year) : m_year(year){
		m_title = new char[strlen(title) + 1];
		strcpy(m_title, title);
	}

	LibraryItem::LibraryItem(const LibraryItem& lib) : m_year(lib.m_year) {
		delete[] m_title;
		m_title = new char[strlen(lib.m_title) + 1];
		strcpy(m_title, lib.m_title);
	}

	LibraryItem& LibraryItem::operator=(const LibraryItem& lib){
		if (this != &lib) {
			m_year = lib.m_year;

			delete[] m_title;
			m_title = new char[strlen(lib.m_title) + 1];
			strcpy(m_title, lib.m_title);

		}

		return *this;
	}

	LibraryItem::~LibraryItem(){
		delete m_title;
	}

	std::ostream& LibraryItem::display(std::ostream& ostr) const {
		ostr << "Title: " << m_title << " (" << m_year << ")";

		return ostr;
	}



	

	
}