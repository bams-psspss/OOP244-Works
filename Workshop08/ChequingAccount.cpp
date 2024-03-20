#include "ChequingAccount.h"
/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: ChequingAccount.cpp
// Version 1.0
// Date: 19 March 2024
// Author: Pattarawan Saravaneeyawong   
// Description
// This file implements the ChequingAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include <iostream>
#include "ChequingAccount.h"

using namespace std;

namespace seneca {
	ChequingAccount::ChequingAccount(double balance, double transactionFee, double monthlyFee) : Account(balance)
	{
		transactionFee > 0 ? m_transFee = transactionFee : m_transFee = 0.0;
		monthlyFee > 0 ? m_monthlyFee = monthlyFee : m_monthlyFee = 0.0;
	}

	bool ChequingAccount::credit(double value)
	{
		bool answer = false;

		if (Account::credit(value))
		{
			Account::debit(m_transFee);
			answer = true;
		}
		return answer;
	}

	bool ChequingAccount::debit(double value)
	{
		bool answer = false;

		if (Account::debit(value))
		{
			Account::debit(m_transFee);
			answer = true;
		}

		return answer;
	}

	void ChequingAccount::monthEnd()
	{
		Account::debit(m_monthlyFee);
	}

	void ChequingAccount::display(std::ostream& out) const
	{
		out << "Account Type: Chequing" << endl;

		out.setf(ios::fixed);
		out.precision(2);
		out << "Balance: $" << balance() << endl;
		out << "Per Transaction Fee: " << m_transFee << endl;
		out << "Monthly Fee: " << m_monthlyFee << endl;
		
	}


}
