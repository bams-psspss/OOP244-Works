/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:		Thursday 08 February 2024
**************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring> 
#include "Icecream.h"

using namespace std;

namespace seneca {
	Icecream::Icecream()
	{
		m_flavourChoice[0] = '\0';
		m_noOfScoop = 0;
		m_waffer = false;
		m_priceOfScoop = 0.0;
		m_priceOfFlavour = 0.0;
		m_priceOfWaffer = 0.0;
		m_total = 0.0;

	}

	void Icecream::getOrder()
	{
		int flavour;
		int scoop;
		bool waffer;


		displayMenu(1);
		flavour = inputValidIntAndRange(MAX_MENU, MIN);
		

		displayMenu(2);
		scoop = inputValidIntAndRange(MAX_SCOOPS, MIN);
		

		displayMenu(3);
		waffer = getandcheckYN();

		set(flavour, scoop, waffer);

		calculate(flavour, scoop, waffer);
		
	}

	void Icecream::printOrder()
	{
		cout.setf(ios::left) << cout.width(25) << cout.fill(' ');
		cout << "Order details:";

		cout.setf(ios::right) << cout.width(10);
		cout << "Price" << endl;
		cout.unsetf(ios::right);

		cout.width(35);
		cout.fill('-');
		cout << '-' << endl;

		cout.fill(' ');

		
		cout << "Number of scoops, " << m_noOfScoop << " total:";
		cout.setf(ios::left) << cout.width(26);
		cout.setf(ios::right);  cout.width(9);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << m_priceOfScoop << endl;
		cout.unsetf(ios::right);

		
		cout << m_flavourChoice << " flavour:";
		cout.setf(ios::left) << cout.width(26);
		
		if (m_priceOfFlavour)
		{
			cout.setf(ios::right) << cout.width(17);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << m_priceOfFlavour;
			cout.unsetf(ios::right);
		}
		cout << endl;

		cout.setf(ios::left) << cout.width(26);
		cout << "Vanilla Waffer:";
		cout.setf(ios::right) << cout.width(9);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << m_priceOfWaffer << endl;
		cout.unsetf(ios::right);

		cout.setf(ios::left) << cout.width(26);
		cout << "Price:";
		cout.setf(ios::right) << cout.width(9);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << m_total << endl;
		cout.unsetf(ios::right);

	}

	void Icecream::displayMenu(int part)
	{
		switch (part){ 
		case 1:
			cout << "Select flavour:" << endl;
			cout.width(16) << cout.fill('-');
			cout << "" << endl;
			cout << "1: Chocolate\n";
			cout << "2: Strawberry\n";
			cout << "3: Mango\n";
			cout << "4: Tutti fruit\n";
			cout << "5: Almond crunch\n";
			cout.width(16) << cout.fill('-');
			cout << "" << endl;			
			break;

		case 2:
			cout << "Number of Scoops (max 3)\n";
			break;

		case 3:
			cout << "Vanilla waffer cone?\n";
			break;

		default:
			cout << "You enter number of Part Wrong\n!";
			break;
		}

	}

	int Icecream::inputValidIntAndRange(int max, int min)
	{
		int inputNum = 0;
		int validNum = 0;
	
		do 
		{
			inputNum = 0;
			cout << "> ";
			cin >> inputNum;

			if (cin) 
			{
				if (inputNum <= max && inputNum >= min)
				{
					validNum = inputNum;
				}
				else
				{
					cout << "Invalid value(" << min << "<=val<=" << max << ")" << endl;
				
				}
			}
			else
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid entry, retry" << endl;

			}

		} while (!validNum);

		return validNum;
	}

	bool Icecream::getandcheckYN()
	{
		char inputChar[JIC_LEN + 1]{};
		bool answer;
		int valid = 0;
		//But i want it to like getchar or sum not the strlen
		cout << "(Y)es/(N)o ";
		do {

			inputChar[0] = '\n';
			cout << "> ";
			cin >> inputChar;

			if (strlen(inputChar) == 1)
			{
				if (inputChar[0] == 'Y' || inputChar[0] == 'y')
				{
					answer = true;
					valid = 1;
				}
				else if (inputChar[0] == 'N' || inputChar[0] == 'n')
				{
					answer = false;
					valid = 1;
				}
				else
				{
					cout << "Only Y or N are acceptable:" << endl;
					cin.clear();
				}
			}
			else
			{
				cout << "Only Y or N are acceptable:" << endl;
				cin.clear();
			}

		} while (!valid);
		

		return answer;
	}

	void Icecream::set(int flavour, int scoop, bool waffer)
	{
		switch (flavour) {
		case 1:
			strcpy(m_flavourChoice,"Chocolate");
			break;

		case 2:
			strcpy(m_flavourChoice, "Strawberry");
			break;

		case 3:
			strcpy(m_flavourChoice, "Mango");
			break;

		case 4:
			strcpy(m_flavourChoice, "Tutti fruit");
			break;

		case 5:
			strcpy(m_flavourChoice, "Almond crunch");
			break;
		
		default:
			strcpy(m_flavourChoice, " ");
			break;
		}

		m_noOfScoop = scoop;
		m_waffer = waffer;

	}

	void Icecream::calculate(int flavour, int scoop, bool waffer)
	{
		m_priceOfScoop = COST_SCOOP * scoop;
		
		if (flavour == 1)
		{
			m_priceOfFlavour = scoop;
		}
		if (waffer)
		{
			m_priceOfWaffer = COST_WAFFER;
		}

		m_total = m_priceOfScoop + m_priceOfFlavour + m_priceOfWaffer;
	}

	double Icecream::getTotal() const
	{
		return m_total;
	}



}