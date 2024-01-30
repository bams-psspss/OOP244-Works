/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:		Tuesday 30 January 2024
**************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Room.h"


using namespace std;

namespace seneca
{
	void set(Room& room, int numberOfGuests, const char* roomNumber)
	{
		int i;
		room.m_noOfGuests = numberOfGuests;

		strcpy(room.m_roomNumber, roomNumber);

		room.m_guests = new Guest[numberOfGuests];

		for (i = 0; i < room.m_noOfGuests; i++)
		{
			room.m_guests[i].m_firstName = new char[MAX_NAME + 1];
			room.m_guests[i].m_lastName = new char[MAX_NAME + 1];
		}
	
	}

	void print(const Room& room)
	{
		int i = 0;
		if (room.m_noOfGuests)
		{
			cout << "Room Number: " << room.m_roomNumber << endl;

			for (i = 0; i < room.m_noOfGuests; i++)
			{

				if (room.m_guests[i].m_firstName != nullptr && room.m_guests[i].m_lastName != nullptr)
				{
					cout.width(4);
					cout << "";
					cout << room.m_guests[i].m_firstName << " ";

					cout << room.m_guests[i].m_lastName;

					if (!room.m_guests[i].m_adult)
					{
						cout << "(Child)";
					}

					cout << endl;
				}

				else
				{
					cout.width( 4 );
					cout << "";
					cout << "Vacated!" << endl;
				}
			}
		}
		else
		{
			cout << "Empty Room!" << endl;
		}
	}

	void book(Room& room)
	{
		int i = 0;
		char inputFName[MAX_NAME + 1] = { 0 };
		char inputLName[MAX_NAME + 1] = { 0 };
		int age = 0;

		cout << "Room number: ";
		cin >> room.m_roomNumber;

		cout << "Number of guests: ";
		cin >> room.m_noOfGuests;

		room.m_guests = new Guest[room.m_noOfGuests];

		for (i = 0; i < room.m_noOfGuests; i++)
		{
			cout << i + 1 << ":" << endl;

			cout << "Name: ";
			cin >> inputFName;

			cout << "Lastname: ";
			cin >> inputLName;

			cout << "Age: ";
			cin >> age;

			room.m_guests[i].m_firstName = new char[strlen(inputFName) + 1];
			strcpy(room.m_guests[i].m_firstName, inputFName);


			room.m_guests[i].m_lastName = new char[strlen(inputLName) + 1];
			strcpy(room.m_guests[i].m_lastName, inputLName);

			room.m_guests[i].m_adult = legalAge(age);

		}

	}

	void vacate(Room& room)
	{
		int i;

		for (i = 0; i < room.m_noOfGuests; i++)
		{
			if (room.m_guests[i].m_firstName)
			{
				delete[] room.m_guests[i].m_firstName;
				room.m_guests[i].m_firstName = nullptr;
			}
			if (room.m_guests[i].m_lastName)
			{
				delete[] room.m_guests[i].m_lastName;
				room.m_guests[i].m_lastName = nullptr;
			}

			room.m_guests[i].m_adult = true;

		
		}
		delete[] room.m_guests;
		room.m_guests = nullptr;

		room.m_roomNumber[0] = '\0';
		room.m_noOfGuests = 0;

	}



}

