/* Citation and Sources...
Final Project Milestone 4
Module: Time
Filename: Time.h
Version 1.0
Author   Pattarwan Saravaneeyawong
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SENECA_TIME_H
#define SENECA_TIME_H
#include <iostream>
#include "Utils.h"


namespace seneca {
	class Time {
		int m_totalMin{};

	public:
		Time& reset();
		Time(unsigned int min = 0u);
		virtual ~Time() = default;

		std::ostream& write(std::ostream& ostr = std::cout)const;
		std::istream& read(char delimiter = ':', std::istream& istr = std::cin);

		operator unsigned int() const;

		Time& operator*= (int val);
		Time& operator-= (const Time& D);
		Time operator- (const Time& T) const;
	};


	std::ostream& operator<<(std::ostream& ostr, const Time& time);
	std::istream& operator>>(std::istream& istr, Time& time);
}




#endif // !SENECA_TIME_H
