/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:		Saturday 03, February 2024
**************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Car.h"

using namespace std;

namespace seneca 
{

	bool Car::isEmpty() const
	{
		bool isEmpty = false;

		if (m_makeModel == nullptr || m_makeModel[0] == '\0' ||
			m_serviceDesc == nullptr || m_serviceDesc[0] == '\0') {

			isEmpty = true;
		}

		return isEmpty;
	}

	void Car::setEmpty()
	{
			m_licencePlat[0] = '\0';

			m_makeModel = nullptr;
			m_serviceDesc = nullptr;

			m_cost = 0.0;
	}

	void Car::deallocateMemory() 
	{
			delete[] m_makeModel;
			m_makeModel = nullptr;

			delete[] m_serviceDesc;
			m_serviceDesc = nullptr;
	}

	void Car::set(const char plateNo[], const char* carMakeModel, 
		const char* serviceDesc, double serviceCost)
	{
		deallocateMemory();
		
		if(plateNo[0] != '\0' && carMakeModel!= nullptr && carMakeModel[0] != '\0' &&
							     serviceDesc != nullptr && serviceDesc[0] != '\0')
		{
			strcpy(m_licencePlat, plateNo);
			m_makeModel = new char[strlen(carMakeModel) + 1];
			strcpy(m_makeModel, carMakeModel);

			m_serviceDesc = new char[strlen(serviceDesc) + 1];
			strcpy(m_serviceDesc, serviceDesc);

			m_cost = serviceCost;
		}
	}

	void Car::display() const
	{
		if (!isEmpty()) {

			cout.setf(ios::left); cout.width(15);
			cout << "License Plate:";
			cout.setf(ios::right);  cout.width(20);
			cout << m_licencePlat;

			cout << endl;

			cout.unsetf(ios::right); cout.width(15);
			cout << "Model:";
			cout.setf(ios::right); cout.width(20);
			cout << m_makeModel << endl;

			cout.unsetf(ios::right); cout.width(15);
			cout << "Service Name:";
			cout.setf(ios::right); cout.width(20);
			cout << m_serviceDesc << endl;

			cout.unsetf(ios::right); cout.width(15);
			cout << "Service Cost:";
			cout.setf(ios::right); cout.width(20);
			cout.precision(2);
			cout << fixed << m_cost << endl;

		}

	}
}