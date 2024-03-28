/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.h
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

#ifndef SENECA_PATIENT_H
#define SENECA_PATIENT_H

#include <iostream>
#include "Utils.h"
#include "IOAble.h"
#include "Ticket.h"

namespace seneca {
	const int maxNameLen = 50 + 1;

	class Patient : public IOAble {
		char* m_patientName{};
		int m_OHIP{};
		Ticket m_ticket;

	public:
		Patient(int ticketNumber);
		Patient(const Patient& patient);
		Patient& operator=(const Patient& patient);
		
		~Patient();

		virtual char type() const = 0;

		bool operator== (char rhs) const;
		bool operator== (const Patient& rhsPt) const;

		void setArrivalTime();

		Time time() const;
		int number() const;

		operator bool() const;
		operator const char* () const;

		virtual std::ostream& write(std::ostream& ostr)const;
		virtual std::istream& read(std::istream& istr);
	};


}

#endif // !SENECA_PATIENT_H
