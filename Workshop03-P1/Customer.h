/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:		Saturday 03, February 2024
**************************************************/
#ifndef SENECA_CUSTOMER_H
#define SENECA_CUSTOMER_H

#include "Car.h"

namespace seneca
{
	class Customer {
	private:
		int m_id;
		char* m_name;
		const Car* m_car;

	public:
		
		//Check if the object is in safe empty state
		//Check for m_name and m_car
		bool isEmpty() const;

		//Set name and id to empty
		void setEmpty();

		//Deallocate the name
		void deallocateMemory();

		//Set input into the strcut
		void set(int customerId, const char* name, const Car* car);

		//Display the summarize on screen
		void display() const;

		//returns the car object pointed to by m_car pointer by dereferencing it
		const Car& car() const;

	};

}

#endif  SENECA_CUSTOMER_H
