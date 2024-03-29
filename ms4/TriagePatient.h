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
