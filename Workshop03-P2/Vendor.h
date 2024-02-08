/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:		Thursday 08 February 2024
**************************************************/

#ifndef SENECA_VENDOR_H
#define SENECA_VENDOR_H

#include "Icecream.h"

#define MAX_ORDERS 50
#define TAX 13

namespace seneca {
	class Vendor {
		int m_numOfOrders;
		Icecream m_icecream[MAX_ORDERS];
	
	public:
		//Set vendor object to an empty state
		void setEmpty();

		//Get the number of orders for icecreams
		//Get each order from the Icecream
		void takeOrders();

		//Print details of all the orders
		//Print the total price, tax(13%)
		//Total orice after tax
		void displayOrders();

		//Delete the Vendor object
		//To prevent the memory leak
		void clearData();

	};






}
#endif // !SENECA_VENDOR_H
