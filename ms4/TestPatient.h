/* Citation and Sources...
Final Project Milestone 4
Module: TestPatient
Filename: TestPatient.h
Version 1.1
Author   Pattarwan Saravaneeyawong
Revision History
-----------------------------------------------------------
Date					Reason
29 / 03 / 2024			I forgot to include the citation part-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SENECA_TESTPATIENT_H
#define SENECA_TESTPATIENT_H
#include <iostream>
#include "Patient.h"

namespace seneca {
	class TestPatient: public Patient {
	public:
		TestPatient();
		virtual char type() const;

		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);

		~TestPatient() = default;

	};

}
#endif // !SENECA_TESTPATIENT_H
