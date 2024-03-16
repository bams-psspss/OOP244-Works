/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.h
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

#ifndef  SENECA_TIME_H
#define SENECA_TIME_H
#include "Utils.h"

namespace seneca {
	class Time {
		int m_totalMins{0};

	public:
		Time& reset();
		Time(unsigned int min = 0u);
		
		std::ostream& write(std::ostream& ostr = std::cout)const;

		//This is Fucked the enter 12
		std::istream& read(char delimiter = ':', std::istream& istr = std::cin);

		operator unsigned int()const;

		//This is Fucked cal wrong
		Time& operator*= (int val);

		Time& operator-= (const Time& D);

		//This is Fucked calculated wrong
		Time operator-(const Time& T)const;

	};

	std::ostream& operator<<(std::ostream& ostr, const Time& time);
	std::istream& operator>>(std::istream& istr, Time& time);


}




#endif // ! SENECA_TIME_H
