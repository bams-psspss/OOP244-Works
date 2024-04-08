/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
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
#include <iostream>
#include <fstream>
#include "PreTriage.h"
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace seneca {
	Time PreTriage::getWaitTime(const Patient& patient)const
	{
		int count = 0;
		Time estTime{};
		int i = 0;

		for (i = 0; i < m_numPat; i++) {
			if (m_patLine[i]->type() == patient.type()) {
				count++;
			}
		}

		if (patient.type() == 'C') {
			estTime = m_tContaigen;
		}
		else if(patient.type() == 'T') {
			estTime = m_tTriage;
		}
		else {
			estTime = estTime.reset();
		}

		estTime *= count;
	         
		return estTime;
	}

	void PreTriage::setAverageWaitTime(Patient& patient) {
		Time currTime = U.getTime();
		Time patTime = patient.time();
		Time avgWTime;
		int patTickNum = patient.number();

		avgWTime = patient.type() == 'C' ? m_tContaigen : m_tTriage;

		avgWTime = ((currTime - patTime) + (avgWTime * (patTickNum - 1))) / patTickNum;

		if (patient.type() == 'C')
		{
			m_tContaigen = avgWTime;
		}
		else {
			m_tTriage = avgWTime;
		}
	}

	int PreTriage::indexOfFirstInLine(char typeOfPat) const
	{
		int index = 0;
		bool found = false;
		int i = 0;
		
		for (i = 0; i < m_numPat && !found; i++) {
			if (m_patLine[i]->type() == typeOfPat) {
				index = i;
				found = true;
			}
		}
		if (!found) {
			index = -1;
		}

		return index;
	}

	void PreTriage::load() {
		ifstream file(m_dataFile);
		Patient* lclpt = nullptr;
		char patTypeFile{};
		int i = 0;

		cout << "Loading data..." << endl;
		if (file.is_open()) {

			file >> m_tContaigen;
			file.ignore();
			file >> m_tTriage;
			file.ignore();


			for (i = 0; i < maxPat && file >> patTypeFile; i++) {
				file.ignore();
				if (patTypeFile == 'C') {
					lclpt = new TestPatient;
				}
				else {
					lclpt = new TriagePatient;
				}

				if (lclpt) {
					lclpt->read(file);
					m_patLine[m_numPat++] = lclpt;
				}
			}
			if (m_numPat == maxPat && file.peek() != EOF) {
				cout << "Warning: number of records exceeded " << maxPat << endl;
				cout << maxPat << " Records imported...\n\n";
			}
			else if (m_numPat <= maxPat && m_numPat > 0) {

				cout << m_numPat << " Records imported...\n\n";
			}
			else {
				cout << "No data or bad data file!\n\n";
			}
		}
		else {
			cout << "No data or bad data file!\n\n";
		}
		file.close();

	}

	void PreTriage::save() const{
		ofstream file(m_dataFile);
		int i = 0;
		int contPat = 0;
		int triaPat = 0;

		if (file.is_open()) {
			cout << "Saving lineup..." << endl;
			file << m_tContaigen << "," << m_tTriage << endl;

			for (i = 0; i < m_numPat; i++)
			{
				m_patLine[i]->write(file);
				file << endl;

				if (m_patLine[i]->type() == 'C') {
					contPat++;
				}
				else
				{
					triaPat++;
				}

			}

			cout << contPat << " Contagion Tests and " << triaPat << " Triage records were saved!" << endl;

		}
		else {
			cout << "Cannot open the file!" << endl;
		}
	}


	void PreTriage::registerPatient() {
		Menu theMenu("Select Type of Registration:\n1- Contagion Test\n2- Triage", 1);
		int selection = 0;

		if (m_numPat < maxPat) {
			theMenu.printMenu();
			cin >> selection;
			switch (selection)
			{
			case 1:
				cin.ignore();
				cout << "Please enter patient information: " << endl;
				cin.clear();
				m_patLine[m_numPat] = new TestPatient;

				cin >> *m_patLine[m_numPat];

				m_patLine[m_numPat]->setArrivalTime();

				cout << "\n******************************************\n";
				cout << *m_patLine[m_numPat];
				cout << "Estimated Wait Time : " << getWaitTime(*m_patLine[m_numPat]);
				cout << "\n******************************************\n\n";

				m_numPat++;
				break;

			case 2:
				cin.ignore();
				cout << "Please enter patient information:" << endl;
				cin.clear();

				m_patLine[m_numPat] = new TriagePatient;
				cin >> *m_patLine[m_numPat];
				m_patLine[m_numPat]->setArrivalTime();

				cout << "\n******************************************\n";
				cout << *m_patLine[m_numPat];
				cout << "Estimated Wait Time : " << getWaitTime(*m_patLine[m_numPat]);
				cout << "\n******************************************\n\n";

				m_numPat++;
				break;

			case 0:
				break;
			}
		}
		else {
			cout << "Line up full!" << endl;
		}
	}


	void PreTriage::admit() {
		Menu admitMenu("Select Type of Admittance:\n1- Contagion Test\n2- Triage", 1);
		Time time = U.getTime();
		int selection = 0;
		int index = 0;

		admitMenu.printMenu();
		cin >> selection;
		cout << "\n******************************************\n";

		switch (selection)
		{
		case 1:
			index = indexOfFirstInLine('C');
			if (index != -1) {
				cout << "Call time: [" << time << "]" << endl;
				cout << "Calling at for " << *m_patLine[index];
				setAverageWaitTime(*m_patLine[index]);
				removeDynamicElement(m_patLine, index, m_numPat);

			}
			else
			{
				cout << "Lineup is empty!\n";
			}
			
			break;
			
		case 2:
			index = indexOfFirstInLine('T');

			if (index != -1) {
				cout << "Call time: [" << time << "]" << endl;
				cout << "Calling at for " << *m_patLine[index];
				setAverageWaitTime(*m_patLine[index]);
				removeDynamicElement(m_patLine, index, m_numPat);
			}
			else
			{
				cout << "Lineup is empty!\n";
			}

			break;


		case 0:
			break;
		}
		cout << "******************************************\n\n";


	}

	void PreTriage::lineup() const
	{
		Menu lineup("Select The Lineup:\n1- Contagion Test\n2- Triage", 1);
		int selection = 0;
		int i = 0;
		int num = 1;
		bool found = false;

		lineup.printMenu();
		cin >> selection;
		cout << "Row - Patient name                                          OHIP     Tk #  Time\n";
		cout << "-------------------------------------------------------------------------------\n";

		switch (selection)
		{
		case 1:
			for (i = 0; i < m_numPat; i++) {
				if (m_patLine[i]->type() == 'C') {

					cout.fill(' ');
					cout.width(3);
					cout.setf(ios::left);
					cout << num++;

					cout.unsetf(ios::left);
					cout << "- ";

					m_patLine[i]->write(clog);
					cout << endl;
					found = true;
				}
			}
			if (!found) {
				cout << "Line up is empty!\n";
			}

			break;

		case 2:
			for (i = 0; i < m_numPat; i++) {
				if (m_patLine[i]->type() == 'T') {
					cout.fill(' ');
					cout.width(3);
					cout.setf(ios::left);
					cout << num++;

					cout.unsetf(ios::left);
					cout << "- ";

					m_patLine[i]->write(clog);
					cout << endl;
					found = true;

				}
			}
			if (!found) {
				cout << "Line up is empty!\n";
			}

			break;
		case 0:
			break;
		}
		cout << "-------------------------------------------------------------------------------\n";

	}


	PreTriage::PreTriage(const char* data) : m_tContaigen(15), m_tTriage(5), m_patLine{}
	{
		U.strcpy(m_dataFile, data);
		m_numPat = 0;
		load();
	}

	PreTriage::~PreTriage()
	{
		save();
		for (int i = 0; i < maxPat; ++i) {
			delete m_patLine[i];
		}

	}



	void PreTriage::run() {
		Menu mainMenu("General Healthcare Facility Pre-Triage Application\n1- Register\n2- Admit\n3- View Lineup");
		int selection = 0;

		do {
			mainMenu.printMenu();
			cin >> selection;
			switch (selection)
			{
			case 1:
				registerPatient();
				break;


			case 2:
				admit();
				break;

			case 3:
				lineup();
				break;

			case 0:
				break;
			}
		} while (selection);
	

	}
}
