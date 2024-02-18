/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.h
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
#pragma once
#ifndef SENECA_BANKACCOUNT_H_
#define SENECA_BANKACCOUNT_H_



namespace seneca
{
   const int ACCT_MAXLEN_USER = 16; // Max Length of user name
   const double CHECKING_TRANS_FEE = 1.25;
   const double CHECKING_INTER_RATE = 0.005;
   const double SAVINGS_TRANS_FEE = 3.50;
   const double SAVINGS_INTER_RATE = 0.025;

   // Class Definition
   class bankAccount
   {
   private:
      // Data Members
      char m_userName[ACCT_MAXLEN_USER];
      double m_funds;
      bool	m_checking;
      int m_monthlyTransactions;

      bool isOpen() const;

   public:
      bankAccount(const char* name = nullptr, bool checking = false);
      bool setup(const char* name, bool checking);

      // ADD: Type Conversion, Unary, Binary Operators & Additional Methods
      operator bool() const;
      operator double() const;

      bankAccount& operator++();
      bankAccount& operator--();

      bool operator+= (double amount);
      bool operator-= (double amount);
      bool operator== (const bankAccount& input) const;
      bool operator> (double amount) const;
      bool operator<= (double amount) const;
      bool operator<<(bankAccount& input);

      void display(void) const;
        
   };

   // ADD: Global helpers
   bool operator> (double lhs, const bankAccount& rhs);
   bool operator<= (double lhs, const bankAccount& rhs);
}
#endif

