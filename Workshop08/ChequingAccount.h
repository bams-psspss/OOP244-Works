/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: ChequingAccount.h
// Version 1.0
// Date: 19 March 2024
// Author: Pattarawan Saravaneeyawong
// Description
// This file defines the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#ifndef SENECA_CHEQUINGACCOUNT_H
#define SENECA_CHEQUINGACCOUNT_H
#include <iostream>
#include "Account.h"

namespace seneca {
	class ChequingAccount : public Account {
		double m_transFee{};
		double m_monthlyFee{};

	public:
		ChequingAccount(double balance, double transactionFee, double monthlyFee);

		bool credit(double value);
		bool debit(double value);

		void monthEnd();
		void display(std::ostream& out) const;
	};
}




#endif // !SENECA_CHEQUINGACCOUNT_H
