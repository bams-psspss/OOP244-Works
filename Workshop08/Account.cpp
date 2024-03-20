#include "Account.h"
/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: Account.cpp
// Version 1.0
// Date: 19 March 2024
// Author: Pattarawan Saravaneeyawong
// Description
// This file implements the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
	double Account::balance() const
	{
		return m_currentBalance;
	}
	Account::Account(double balance)
	{
		if (balance <= 0.0)
		{
			m_currentBalance = 0.0;
		}
		else
		{
			m_currentBalance = balance;
		}
	}

	bool Account::credit(double value)
	{
		bool answer = true;

		if (value <= 0.0)
		{
			answer = false;
		}
		else
		{
			m_currentBalance += value;
		}

		return answer;
	}

	bool Account::debit(double value)
	{
		bool answer = true;

		if (value <= 0.0)
		{
			answer = false;
		}
		else
		{
			m_currentBalance -= value;
		}

		return answer;
	}

}

