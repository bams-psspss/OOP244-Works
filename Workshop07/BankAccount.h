/***********************************************************************
// OOP244 Workshop #7
//
// File:    BankAccount.cpp
// Version: 1.0
// Author:  Pattarawan Saravaneeyawong
//
***********************************************************************/

#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H
#include <iostream>
#include "DepositUtility.h"

namespace seneca {
	const int MAX_NAME = 51;

	class BankAccount {
		char m_name[MAX_NAME];
		Date m_openDate;
		DepositInfo m_depInfo;
		double m_balance;

	protected:
		//Return current balance of the account (m_balance)
		double getBalance() const;
		//sets the current m_balance to balnce
		void setBalance(double balance);
		//Print out the balance
		void writeCurrency(std::ostream& out, double amount) const;

	public:
		BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance);
	

		std::ostream& write(std::ostream& out) const ;
		std::istream& read(std::istream& in);
	};

	std::istream& operator>>(std::istream& in, BankAccount& acct);
	std::ostream& operator<<(std::ostream& out, const BankAccount& acct);
}


#endif // !SENECA_BANKACCOUT_H
