/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:		Saturday 03, February 2024
**************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Customer.h"

using namespace std;

namespace seneca 
{
	bool Customer::isEmpty() const
	{
		bool isEmpty = false;
		if (m_name == nullptr || m_name[0] == '\0' || m_car == nullptr)
		{
			isEmpty = true;
		}
		return isEmpty;
	}

	void Customer::setEmpty()
	{
			m_name = nullptr;
			m_id = 0;
	}

	void Customer::deallocateMemory()
	{
		delete[] m_name;
		m_name = nullptr;

	}

	void Customer::set(int customerId, const char* name, const Car* car)
	{
		deallocateMemory();

		if (name != nullptr && name[0] != '\0' && car != nullptr)
		{
			m_id = customerId;
			
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		
			m_car = car;

		}

	} 

	void Customer::display() const
	{
		int i;
		if (!isEmpty()) 
		{
			cout.unsetf(ios::right);
			cout.setf(ios::left) << cout.width(15);
			cout << "Customer ID:";
			cout.setf(ios::right); cout.width(20);
			cout << m_id << endl;

			cout.unsetf(ios::right); cout.width(15);
			cout << "First Name:";
			cout.setf(ios::right); cout.width(20);
			cout << m_name << endl;

			cout.unsetf(ios::right);
			m_car->display();
		}
	}

	const Car& Customer::car() const
	{
		return *m_car;
	}

}