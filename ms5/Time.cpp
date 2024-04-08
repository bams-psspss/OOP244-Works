/* Citation and Sources...
Final Project Milestone 5
Module: Time
Filename: Time.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Time.h"

using namespace std;
namespace seneca {
	Time& Time::reset()
	{
		m_totalMin = U.getTime();
		return *this;
	}

	Time::Time(unsigned int min)
	{
		m_totalMin = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const
	{
		ostr.fill('0');
		ostr.width(2);
		ostr << (m_totalMin / 60) << ":";
		ostr.fill('0');
		ostr.width(2);
		ostr << m_totalMin % 60;
		ostr.fill(' ');
		return ostr;
	}

	std::istream& Time::read(char delimeter, std::istream& istr)
	{
		int hours{}, mins{};
		istr >> hours;

		if (istr.peek() != delimeter)
		{
			istr.setstate(ios::failbit);
		}
		else
		{
			istr.ignore();
			istr >> mins;
		}

		m_totalMin = (hours * 60) + mins;

		return istr;
	}

	Time::operator unsigned int() const
	{
		return m_totalMin;
	}

	Time& Time::operator*=(int val)
	{
		m_totalMin *= val;

		return *this;
	}

	Time& Time::operator-=(const Time& D)
	{
		m_totalMin -= D.m_totalMin;
		if (m_totalMin <= -1)
		{
			m_totalMin += 1440;
		}

		return *this;
	}

	Time Time::operator-(const Time& T) const
	{
		Time diffTime;

		diffTime.m_totalMin = m_totalMin - T.m_totalMin;

		if (diffTime.m_totalMin <= -1)
		{
			diffTime.m_totalMin += 1440;
		}

		return diffTime;
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& time)
	{
		return time.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Time& time)
	{
		return time.read(':', istr);
	}

}