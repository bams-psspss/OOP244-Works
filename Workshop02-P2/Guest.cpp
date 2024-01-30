/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:
**************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Guest.h"

using namespace std;

namespace seneca
{
	void set(Guest& guest, const char* first, const char* last, int age)
	{
		if (first != nullptr && last != nullptr && first[0] != '\0' && last[0] != '\0')
		{
			guest.m_firstName = new char[strlen(first) + 1];
			strcpy(guest.m_firstName, first);

			guest.m_lastName = new char[strlen(last) + 1];
			strcpy(guest.m_lastName, last);

			guest.m_adult = legalAge(age);

		}
		else
		{

			//Man Idk if I should check for each and delete it
			guest.m_firstName = nullptr;
			guest.m_lastName = nullptr;

			guest.m_adult = true;
		}

	}

	void print(const Guest& guest)
	{
		if (checkForNotNull(guest))
		{
			cout << guest.m_firstName << " " << guest.m_lastName;

			if (!guest.m_adult)
			{
				cout << "(Child)";
			}

			cout << endl;
		}
		else
		{
			cout << "Vacated!" << endl;
		}

	}

	void book(Guest& guest)
	{
		char inputFName[MAX_NAME + 1 ] = {0};
		char inputLName[MAX_NAME + 1 ] = {0};
		int age = 0;

		cout << "Name: ";
		cin >> inputFName;
		cout << "Lastname: ";
		cin >> inputLName;
		cout << "Age: ";
		cin >> age;

		set(guest, inputFName, inputLName, age);

	}

	void vacate(Guest& guest)
	{
		if (checkForNotNull(guest))
		{
			delete[] guest.m_firstName;
			guest.m_firstName = nullptr;

			delete[] guest.m_lastName;
			guest.m_lastName = nullptr;

		}
		else
		{
			//do nothing
			//Maybe promtp user "This guest is empty!";
		}
	}



	bool checkForNotNull(const Guest guest)
	{
		bool empty = true;

		if (guest.m_firstName != nullptr && guest.m_lastName != nullptr)
		{
			empty = true;
		}
		else
		{
			empty = false;
		}

		return empty;
	}

	bool legalAge(int age)
	{
		bool legal = false;

		if (age >= 18)
		{
			legal = true;
		}
		return legal;
	}


}