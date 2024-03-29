/* Citation and Sources...
Final Project Milestone 4
Module: Patient
Filename: Patient.cpp
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

#include <iostream>
#include "Patient.h"

using namespace std;

namespace seneca {
	Patient::Patient(int ticketNumber) : m_ticket(ticketNumber) {}

	Patient::Patient(const Patient& patient) : m_OHIP(patient.m_OHIP), m_ticket(patient.m_ticket) {
		U.aloCopy(m_patientName, patient.m_patientName, maxNameLen);
	}

	Patient& Patient::operator=(const Patient& patient)
	{

		if (this != &patient) {
			U.aloCopy(m_patientName, patient.m_patientName, maxNameLen);

			m_OHIP = patient.m_OHIP;
			m_ticket = patient.m_ticket;
		}

		return *this;
	}
	Patient::~Patient()
	{
		delete[] m_patientName;
	}

	bool Patient::operator== (char rhs) const
	{
		return (type() == rhs);
	}

	bool Patient::operator==(const Patient& rhsPt) const
	{
		return (type() == rhsPt.type());
	}

	void Patient::setArrivalTime()
	{
		m_ticket.resetTime();
	}

	Time Patient::time() const
	{
		return m_ticket.time();
	}

	int Patient::number() const
	{
		return m_ticket.number();
	}

	Patient::operator bool() const
	{
		return (m_patientName != nullptr && m_OHIP > 0);
	}

	Patient::operator const char* () const
	{
		return m_patientName;
	}

	std::ostream& Patient::write(std::ostream& ostr) const
	{
		if (&ostr == &std::clog) {
			if (m_patientName == nullptr || m_OHIP <= 0) {
				ostr << "Invalid Patient Record" << endl;
			}
			else {

				ostr.setf(ios::left);
				ostr.width(53);
				ostr.fill('.');

				ostr << m_patientName;
				ostr << m_OHIP;

				ostr.fill(' ');
				ostr.setf(ios::right);
				ostr.width(5);

				ostr << m_ticket.number() << " " << m_ticket.time();

				ostr.unsetf(ios::right);
			}
		}
		else if (&ostr == &std::cout) {
			if (m_patientName == nullptr || m_OHIP <= 0) {
				ostr << "Invalid Patient Record" << endl;
			}
			else {
				ostr << m_ticket << "\n";
				ostr << m_patientName << ", OHIP: " << m_OHIP << "\n";
			}
		}
		else {
			ostr << type() << ",";
			ostr << m_patientName << "," << m_OHIP;
			ostr << ",";
			m_ticket.write(ostr);
		}
		return ostr;
	}

	std::istream& Patient::read(std::istream& istr)
	{
		const int minNum = 100000000;
		const int maxNum = 999999999;
		const int maxName = 51;

		char tmpName[maxName]{};
		int tmpOHIP = 0;

		if (cin.fail()) {
			delete[] m_patientName;
			m_patientName = nullptr;
		}
		else if (&istr == &cin) {
			cout << "Name: ";
			istr.get(tmpName, maxName);
			istr.ignore(maxName, '\n');

			U.aloCopy(m_patientName, tmpName, maxName);


			cout << "OHIP: ";
			tmpOHIP = U.getInt(minNum, maxNum);
			m_OHIP = tmpOHIP;
		}
		else {
			istr.get(tmpName, maxName, ',');
			istr.ignore(maxName, ',');

			U.aloCopy(m_patientName, tmpName, maxName);

			istr >> tmpOHIP;
			m_OHIP = tmpOHIP;
			istr.ignore(10000, ',');



			if (!m_ticket.read(istr)) {

				istr.setstate(std::ios::failbit);
			}


		}


		return istr;
	}


}

