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