#include "SavingsAccount.h"
/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingsAccount.cpp
// Version 1.0
// Date: 19 March 2024
// Author: Pattarawan Saravaneeyawong
// Description
// This file implements the SavingsAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

#include <iostream>
#include "SavingsAccount.h"

using namespace std;

namespace seneca {
	SavingsAccount::SavingsAccount(double initialBalance, double interestRate) : Account (initialBalance)
	{
		if (interestRate <= 0.0)
		{
			m_interestRate = 0.0;
		}
		else
		{
			m_interestRate = interestRate;
		}
	}
	void SavingsAccount::monthEnd()
	{
		double interestEarned = 0.0;
		double currentBal = balance();

		interestEarned = currentBal * m_interestRate;

		credit(interestEarned);
		
	}
	void SavingsAccount::display(ostream& out) const
	{
		
		out << "Account type: Savings" << endl;
		out.setf(ios::fixed);
		out.precision(2);
		out << "Balance: $" << balance() << endl;
		out << "Interest Rate (%): " << (m_interestRate * 100) << endl;
	}
}