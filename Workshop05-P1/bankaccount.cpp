/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.cpp
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:		Saturday 18 February 2024
**************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "bankaccount.h"
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

namespace seneca
{
	// Default Constructor with default arguments
	bankAccount::bankAccount(const char* name, bool checking)
	{
		m_userName[0] = '\0';	// Empty string implies is account is not open 
		setup(name, checking);
	}

	// Open bank account: setup can only be done once!
	bool bankAccount::setup(const char* name, bool checking)
	{
		if (isOpen())					
			return false;
		if (name == nullptr)
			return false;

		strcpy(m_userName, name);	
		m_monthlyTransactions = 0;	
		m_checking = checking;
		m_funds = 0;
		return true;
	}

	// Account is open if user name string is not empty
	bool bankAccount::isOpen() const
	{
		return (m_userName[0] != '\0');
	}


	// ADD: Type Conversion, Unary & Binary Operators; + Additional Methods

	bankAccount::operator bool() const
	{
		return isOpen();
	}

	bankAccount::operator double() const
	{
		return m_funds;
	}

	bankAccount& bankAccount::operator++()
	{
		double interest = 0.0;

		if (isOpen() && m_funds > 0)
		{
			if (m_checking) 
			{
				//Is Check Account
				interest = (m_funds * CHECKING_INTER_RATE);
			}
			else
			{
				interest = (m_funds * SAVINGS_INTER_RATE);
			}
			m_funds += interest;
		}

		return *this;
	}

	bankAccount& bankAccount::operator--()
	{
		double fees = 0.0;
		if (isOpen())
		{
			if (m_checking)
			{
				//Is Check Account
				fees = (m_monthlyTransactions * CHECKING_TRANS_FEE);
			}
			else
			{
				fees = (m_monthlyTransactions * SAVINGS_TRANS_FEE);
			}
			m_funds -= fees;
		}
		return *this;
	}

	bool bankAccount::operator+=(double amount)
	{
		bool answer = false;

		if (isOpen())
		{
			m_funds += amount;
			m_monthlyTransactions++;

			cout << "Deposit $";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << amount << " for " << m_userName << endl;

			answer = true;

		}

		

		return answer;
	}

	bool bankAccount::operator-=(double amount)
	{
		bool answer = false;
		double negativeAmount = 0;
		if (isOpen())
		{
			negativeAmount = amount;
			amount = amount * -1;
			m_funds += amount;
			m_monthlyTransactions++;
			

			cout << "Withdraw $";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << negativeAmount << " for " << m_userName << endl;

			answer = true;
		}
		return answer;
	}

	bool bankAccount::operator==(const bankAccount& input) const
	{
		bool answer = false;
		if (isOpen())
		{
			if ((strcmp(input.m_userName, m_userName) == 0) && 
				(input.m_funds == m_funds) && 
				(input.m_checking == m_checking))
			{
				answer = true;
			}
		}

		return answer;
	}

	bool bankAccount::operator>(double amount) const
	{
		bool answer = false;

		if (isOpen())
		{
			if (m_funds > amount)
			{
				answer = true;
			}
		}

		return answer;
	}

	bool bankAccount::operator<=(double amount) const
	{
		bool answer = false;
		
		if (isOpen())
		{
			if (amount > m_funds)
			{
				answer = true;
			}
		}
		return answer;
	}

	bool bankAccount::operator<<(bankAccount& input)
	{
		bool answer = false;
		if (isOpen() && input.isOpen() && (input.m_funds > 0))
		{
			cout << "Transfer $" << input.m_funds << " from " << input.m_userName;
			cout << " to " << m_userName << endl;

			//use THIS like right now user to go operator +=
			*this += input.m_funds;

			input -= (input.m_funds);

			answer = true;
		}

		return answer;
	}

	void bankAccount::display(void) const
	{
		cout << "Display Account -> User:";
		if (isOpen())
		{
			cout.setf(ios::right);
			cout.width(16);
			cout.fill('-');
			cout << m_userName;
			cout << " | ";

			cout.width(9);
			cout.fill(' ');
			if (m_checking)
			{
				cout << "Checking";
			}
			else 
			{
				cout << "Savings";
			}

			cout.setf(ios::left);
			cout.width(10);
			cout << " | Balance: $";
			cout.setf(ios::right);
			cout.width(8);
			cout.precision(2);
			cout << m_funds;

			cout << " | Transactions:";
			cout.width(3);
			cout.fill('0');
			cout << m_monthlyTransactions;
			cout << endl;
			cout.fill(' ');

		}
		else
		{
			cout.width(7);
			cout.fill('-');
			cout << " " << "NOT OPEN" << endl;
			cout.fill(' ');
		}
	}

	
	// ADD: Global Helper Functions



	bool operator>(double lhs, const bankAccount& rhs)
	{
		bool answer = false;
		if (bool(rhs))
		{
			if (lhs > double(rhs))
			{
				answer = true;
			}
				
		}
		return answer;
	}

	bool operator<=(double lhs, const bankAccount& rhs)
	{
		bool answer = false;
		if (bool(rhs))
		{
			if (lhs <= double(rhs))
			{
				answer = true;
			}

		}
		return answer;
	}

}
