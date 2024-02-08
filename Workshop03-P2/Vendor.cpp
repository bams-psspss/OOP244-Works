/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:		Thursday 08 February 2024
**************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring> 

#include "Vendor.h"

using namespace std;

namespace seneca {
	void Vendor::setEmpty()
	{		
		int i;
		m_numOfOrders = 0;
		for (i = 0; i < MAX_ORDERS; i++)
		{
			m_icecream[i] = Icecream();
		}

	}
	void Vendor::takeOrders()
	{
		int i;
		
		cout << "Seneca Icecream shop\n";
		
		cout << "          @" << endl;
		cout << "        (' .)" << endl;
		cout << "       (*.`. )" << endl;
		cout << "        \\###/" << endl;
		cout << "         \\#/" << endl;
		cout << "          V" << endl;

		cout << "How many Icecreams?\n";
		cout << "> ";
		cin >> m_numOfOrders;

		for (i = 0; i < m_numOfOrders; i++)
		{
			cout << "Order number " << i + 1 << ":" << endl;
			m_icecream[i].getOrder();
		}
		cout << endl;


	}

	void Vendor::displayOrders()
	{ 
		int i;
		double totalPrice = 0;
		double tax, total;

		cout << "********** Order Summary **********" << endl;

		for (i = 0; i < m_numOfOrders; i++)
		{
			cout << "Order No: " << i + 1 << ":" << endl;
			m_icecream[i].printOrder();
			totalPrice += m_icecream[i].getTotal();
			if (i < m_numOfOrders - 1)
			{
				cout << endl;
			}
			
		}

		cout.width(35); 
		cout.fill('-');
		cout << '-' << endl;

		cout.fill(' ');
		cout.setf(ios::left);
		cout.width(26);
		cout << "Price:";
		cout.setf(ios::right);  
		cout.width(9);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << totalPrice << endl;
		cout.unsetf(ios::right);


		tax = totalPrice * (TAX / 100.0);

		cout.setf(ios::left);
		cout.width(26);
		cout << "Tax:";
		cout.setf(ios::right);  
		cout.width(9);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << tax << endl;
		cout.unsetf(ios::right);


		total = totalPrice + tax;
		cout.setf(ios::left);
		cout.width(26);
		cout << "Total:";
		cout.setf(ios::right);  
		cout.width(9);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << total << endl;
		cout.unsetf(ios::right);
	}

	void Vendor::clearData()
	{
		//I don't have any DMA
		setEmpty();
	}
	
}
