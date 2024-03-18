/***********************************************************************
// OOP244 Workshop #7
//
// File:    BankAccount.cpp
// Version: 1.0
// Author:  Pattarawan Saravaneeyawong
//
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "BankAccount.h"

using namespace std;

namespace seneca {
	double BankAccount::getBalance() const
	{
		return m_balance;
	}
	void BankAccount::setBalance(double balance)
	{
		m_balance = balance;
	}
	void BankAccount::writeCurrency(ostream& out, double amount) const
	{
		out.setf(ios::fixed);
		out.precision(2);
		out << "$" << amount;
	}
	BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance)
	{
		strncpy(m_name, name, MAX_NAME);
		m_openDate = openDate;
		m_depInfo = depInfo;
		m_balance = balance;
	}
	ostream& BankAccount::write(ostream& out) const
	{ 
		out << ">> " << m_name << " | ";
		writeCurrency(out, m_balance);
		out << " | ";
		out << m_openDate << " | " << m_depInfo;

		return out;
	}
	std::istream& BankAccount::read(std::istream& in)
	{
	
		cout << "Name: ";
		in.getline(m_name, MAX_NAME, '\n');
		
		cout << "Opening Balance: ";
		in >> m_balance;
		in.ignore(100, '\n');

		cout << "Date Opened ";
		m_openDate.read(in);
		in.ignore(100, '\n');

		m_depInfo.read(in);
		in.ignore(100, '\n');
		return in;
	}

	std::istream& operator>>(std::istream& in, BankAccount& acct)
	{
		return acct.read(in);
	}

	std::ostream& operator<<(std::ostream& out, const BankAccount& acct)
	{
		return acct.write(out);
	}

}