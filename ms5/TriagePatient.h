/* Citation and Sources...
Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.h
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
#ifndef SENECA_TRIAGEPATIENT_H
#define SENECA_TRIAGEPATIENT_H
#include "Patient.h"

namespace seneca {
	class TriagePatient : public Patient {
		char* m_symptom{};
	public:
		TriagePatient();
		~TriagePatient();
		virtual char type() const;

		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);

	};

}



#endif // !SENECA_TRIAGEPATIENT_H
