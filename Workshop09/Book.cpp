/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:		29 / 03 / 2024
**************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"

using namespace std;
namespace seneca {
	Book::Book(const char* title, const int year, const char* author) : LibraryItem(title, year) {
		m_author = new char[strlen(author) + 1];
		strcpy(m_author, author);
	}
	Book::Book(const Book& books) : LibraryItem(books) {
		
		delete[] m_author;
		m_author = new char[strlen(books.m_author) + 1];
		strcpy(m_author, books.m_author);

	}
	Book& Book::operator=(const Book& books){
		if (this != &books) {
			LibraryItem::operator=(books);

			delete[] m_author;
			m_author = new char[strlen(books.m_author) + 1];
			strcpy(m_author, books.m_author);

		}

		return *this;
	}
	Book::~Book(){
		delete[] m_author;
	}
	std::ostream& Book::display(std::ostream& ostr) const {

		LibraryItem::display();
		ostr << '\n';
		ostr << "Author: " << m_author;

		return ostr;
	}
	bool Book::operator>(const Book& other) const {
		bool answer = false;
		if (m_author && other.m_author) {
			if (strcmp(m_author, other.m_author) > 0)
			{
				answer = true;
			}
			else
			{
				answer = false;
			}
		}

		return answer;
	}
}