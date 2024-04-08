/* Citation and Sources...
Final Project Milestone 5
Module: TestPatient
Filename: TestPatient.cpp
Version 1.1
Author   Pattarwan Saravaneeyawong
Revision History
-----------------------------------------------------------
Date					Reason
29 / 03 / 2024			I forgot to include the citation part
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
#include "TestPatient.h"

using namespace std;
namespace seneca {
	int nextTestTicket = 1;

	TestPatient::TestPatient() : Patient(nextTestTicket) {
		nextTestTicket++;
	}

	char TestPatient::type() const{
		return 'C';
	}

	std::ostream& TestPatient::write(std::ostream& ostr) const {
		if (&ostr == &cout) {
			ostr << "Contagion TEST" << '\n';
		}
		Patient::write(ostr);

		return ostr;
	}

	std::istream& TestPatient::read(std::istream& istr) {
		Patient::read(istr);
		if (&istr != &cin) {
			nextTestTicket = Patient::number() + 1;
		}

		return istr;
	}


}