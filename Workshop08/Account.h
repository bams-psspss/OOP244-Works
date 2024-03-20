/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: Account.h
// Version 1.0
// Date:	19 March 2024
// Author: Pattarawan Saravaneeyawong
// Description
// This file defines the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H
#include "iAccount.h"

namespace seneca {

	class Account: public iAccount {
		double m_currentBalance{};

	protected:
		double balance() const;

	public:
		Account(double balance);
		bool credit(double value);
		bool debit(double value);
	};
}

#endif // !SENECA_ACCOUNT_H
