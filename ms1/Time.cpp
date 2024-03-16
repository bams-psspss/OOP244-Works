/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.cpp
Version 1.0
Author   Pattarawan Saravaneeyawong
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

#include <iostream>
#include "Time.h"

using namespace std;

namespace seneca {

	Time& Time::reset()
	{
		m_totalMins = U.getTime();

		return *this;
	}

	Time::Time(unsigned int min)
	{
		m_totalMins = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const
	{
		int hours = 0;
		int minutes = 0;

		if (m_totalMins >= 0)
		{
			hours = m_totalMins / 60;
			minutes = m_totalMins % 60;
		}
		else
		{
			hours = (m_totalMins + 1440) / 60;
			minutes = (m_totalMins + 1440) % 60;

		}

		ostr << hours << ":";
		if (minutes < 10) {
			ostr << "0" << minutes;
		}
		else {
			ostr << minutes;
		}

		return ostr;
	}

	std::istream& Time::read(char delimiter, std::istream& istr)
	{
		int hours = 0;
		int minutes = 0;
		char theColon = '\0';

		U.getTime();
		if (theColon == delimiter)
		{
			istr.ignore();
		}
		else
		{

			istr.setstate(ios::failbit);
		}
		
		return istr;
	}


	Time::operator unsigned int() const
	{
		return m_totalMins;
	}

	Time& Time::operator*=(int val)
	{
		m_totalMins *= val;

		return *this;
	}

	Time& Time::operator-=(const Time& D)
	{
		m_totalMins -= D;

		return *this;
	}

	Time Time::operator-(const Time& T) const
	{
		int diffTime;
		diffTime = m_totalMins - T;

		return diffTime;
	}



	std::ostream& operator<<(std::ostream& ostr, const Time& time)
	{
		return time.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Time& time)
	{
		return time.read(':',istr);
	}

}