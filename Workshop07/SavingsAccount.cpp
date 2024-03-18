/***********************************************************************
// OOP244 Workshop #7
//
// File:    SavingsAccount.cpp
// Version: 1.0
// Author:  Pattarawan Saravaneeyawong
//
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "BankAccount.h"
#include "SavingsAccount.h"

using namespace std;

namespace seneca {
	void SavingsAccount::writeInterest(std::ostream& out) const
	{
		out.setf(ios::fixed);
		out.precision(3);
		out << m_interest << "%";
	}

	SavingsAccount::SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate) : BankAccount(name, openDate, depInfo, balance), m_interest(interest), m_interestDate(interestDate)
	{
	}

	void SavingsAccount::applyInterest(Date& dt)
	{
		double tmpBalance = 0;
		double interestAmount = 0;

		tmpBalance = getBalance();
		cout << "   ";
		writeCurrency(cout, tmpBalance);
		cout << " + ";

		interestAmount = (m_interest * tmpBalance);
		writeCurrency(cout, interestAmount);
		cout << " (";
		writeInterest(cout);
		cout << ") = ";

		tmpBalance += interestAmount;
		setBalance(tmpBalance);
		writeCurrency(cout, tmpBalance);
		cout << " | ";
	
		cout << m_interestDate << " => ";
		dt.write(cout);

		m_interestDate = dt;

		cout << endl;
	}

	std::ostream& SavingsAccount::write(std::ostream& out) const
	{
		BankAccount::write(out);
		cout << " | ";
		writeInterest(out);
		cout << " | ";
		cout << m_interestDate;
	

		return out;
	}

	std::istream& SavingsAccount::read(std::istream& in)
	{
		BankAccount::read(in);

		cout << "Interest Date ";
		cin >> m_interestDate;

		cout << "Interest Rate: ";
		cin >> m_interest;

		return in;
	}


	std::istream& operator>>(std::istream& in, SavingsAccount& acct)
	{
		return acct.read(in);
	}

	std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct)
	{
		return acct.write(out);
	}

}