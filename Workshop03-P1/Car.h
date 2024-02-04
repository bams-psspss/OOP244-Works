/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:		Saturday 03, February 2024
**************************************************/
#ifndef SENECA_CAR_H
#define SENECA_CAR_H

#define MAX_LICENSE	8

namespace seneca {

	class Car {
	private:
		char m_licencePlat[MAX_LICENSE + 1];
		char* m_makeModel;
		char* m_serviceDesc;
		double m_cost;

	public:
		//Check if the object is in safe empty state
		//Car is empty either makemode or service is empty
		bool isEmpty() const;


		//Sets object to safe empty state;
		//Setting attributed to empty cstring and nullptr
		void setEmpty();

		//Deaalocate mem for makemodel and servicedesc
		void deallocateMemory();

		//Deallocates memory and sets to empty state
		//If not null copies argument to attribute
		//Allocates memory and copies the data for car makenmodel
		void set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost);

		//Display car function
		void display() const;
	};
}
#endif