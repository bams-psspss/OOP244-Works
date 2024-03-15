/* Citation and Sources...
Final Project Milestone 1
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
		m_hours = 0;
		m_mins = 0;
	}

	std::ostream& Time::write(std::ostream& ostr) const 
	{
		int hours = m_totalMin / 60;
		int mins = m_totalMin - (hours * 60);

		//try setfill and setwidth but fail
		if (hours < 10) 
		{
			ostr << "0";
		}
		ostr << hours << ":";
		if (mins < 10) {
			ostr << "0" << mins;
		}
		else {
			ostr << mins;
		}


		return ostr;

	}

	std::istream& Time::read(char delimeter, std::istream& istr) 
	{

		istr >> m_hours;
		if (istr.fail()) 
		{
			istr.setstate(ios::failbit);
		}
		//the peek check for the last thing without entering anything
		//I google it
		//But I wanna know what is inside, but there is no source for it.
		if (istr.peek() != delimeter)
		{
			istr.setstate(ios::failbit);
		}
		else
		{
			istr.ignore();
			istr >> m_mins;
		}

		m_totalMin = (m_hours * 60) + m_mins;

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