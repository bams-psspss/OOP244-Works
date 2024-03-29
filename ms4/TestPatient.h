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
