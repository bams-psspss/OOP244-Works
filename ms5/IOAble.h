/* Citation and Sources...
Final Project Milestone 5
Module: IOAble
Filename: IOAble.h
Version 1.0
Author   Pattarawan Saravaneeyawong
Revision History
-----------------------------------------------------------
Date      Reason

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SENECA_IOABLE_H
#define SENECA_IOABLE_H
#include <iostream>

namespace seneca {
	class IOAble {

	public:
		virtual std::ostream& write(std::ostream& ostr)const = 0;
		virtual std::istream& read(std::istream& istr) = 0;

		virtual ~IOAble() {};
	};

	std::ostream& operator<<(std::ostream& ostr, const IOAble& ioable);
	std::istream& operator>>(std::istream& istr, IOAble& ioable);
}

#endif