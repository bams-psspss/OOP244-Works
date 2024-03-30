#include <iostream>
#include "TriagePatient.h"

using namespace std;
namespace seneca {
	int nextTriageTicket = 1;
	const int maxSympLen = 512;


	TriagePatient::TriagePatient() : Patient(nextTriageTicket), m_symptom(nullptr) {
		nextTriageTicket =+ 1;
	}

	TriagePatient::~TriagePatient() {
		delete[] m_symptom;
	}

	char TriagePatient::type() const {
		return 'T';
	}

	std::ostream& TriagePatient::write(std::ostream& ostr) const {
		if (&ostr == &cout) {
			ostr << "TRIAGE" << '\n';
			Patient::write(cout);
			ostr << "Symptoms: " << m_symptom << '\n';
		}
		else if (&ostr == &clog) {
			Patient::write(clog);
		}
		else{
			Patient::write(ostr);
			ostr << m_symptom;
		}
		return ostr;
	}

	std::istream& TriagePatient::read(std::istream& istr) {
		char tmpSymp[512]{};

		delete[] m_symptom;

		Patient::read(istr);

		if (cin.fail()) {
			delete[] m_symptom;
			m_symptom = nullptr;
		}
		else
		{
			if (&istr != &cin) {
				istr.ignore(100, ',');
				istr.getline(tmpSymp, 511, '\n');

				m_symptom = new char[U.strlen(tmpSymp) + 1];
				U.strcpy(m_symptom, tmpSymp, 511);

			}
			else {
				cout << "Symptoms: ";
				istr.getline(tmpSymp, 511);
				m_symptom = new char[U.strlen(tmpSymp) + 1];
				U.strcpy(m_symptom, tmpSymp, 511);

			}
		}
		
		return istr;
	}

}