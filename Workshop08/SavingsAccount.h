/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingAccount.h
// Version 1.0
// Date:	19 March 2024
// Author:  Pattarawan Saravaneeyawong
// Description
// This file defines the SavingsAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H
#include "Account.h"

namespace seneca {
	class SavingsAccount : public Account {
		double m_interestRate{};

	public:
		SavingsAccount(double initialBalance, double interestRate);
		void monthEnd();
		void display(std::ostream& out) const;

	};
}

#endif // !SENECA_SAVINGSACCOUNT_H

