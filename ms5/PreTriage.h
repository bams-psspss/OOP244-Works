/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.h
Version 1.1
Author   Pattarwan Saravaneeyawong
Revision History
-----------------------------------------------------------
Date					Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SENECA_PRETRIAGE_H
#define SENECA_PRETRIAGE_H
#include "Utils.h"
#include "Patient.h"
#include "Time.h"

namespace seneca {
	const int maxPat = 100;
	const int maxFileName = 500;
	class PreTriage {
		Time m_tContaigen{};
		Time m_tTriage{};
		Patient* m_patLine[maxPat]{};
		char m_dataFile[maxFileName]{};
		int m_numPat{};

		Time getWaitTime(const Patient& patient) const;
		void setAverageWaitTime(Patient& patient);
		int indexOfFirstInLine(char typeOfPat) const;
		void load();
		void save() const;
		void registerPatient();
		void admit();
		void lineup() const;

	public:
		PreTriage(const char* data);
		virtual ~PreTriage();
		void run();

	}; 


}


#endif // !SENECA_PRETRIAGE_H
