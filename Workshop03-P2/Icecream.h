/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:	T	hursday 08 February 2024
**************************************************/

#ifndef SENECA_ICECREAM_H
#define SENECA_ICECREAM_H


#define MAX_MENU 5
#define MIN 1
#define MAX_SCOOPS 3
#define JIC_LEN 60

#define COST_SCOOP 5
#define COST_WAFFER 5
#define FLAVOURS 25

namespace seneca {
	class Icecream {
		char m_flavourChoice[FLAVOURS + 1];
		int m_noOfScoop;
		bool m_waffer;
		double m_priceOfScoop;
		double m_priceOfFlavour;
		double m_priceOfWaffer;
		double m_total;

		
	public:

		//Construct the object to Empty
		Icecream();

		//Get Flavour, No. Of scoope, and Waffer Cone
		//And set it into the IceCream
		void getOrder();

		//Print order details
		void printOrder();

		//show menu
		//agrument is for part of menu
		void displayMenu(int part);

		//Get the validate number range max and min.
		//Check if it is int not char.
		//Return validate number
		int inputValidIntAndRange(int max, int min);

		//arrOfString is string we want to compare
		//Validate the y or n question
		bool getandcheckYN();

		//Receive the inpt from getOrder and set it into the object
		void set(int flavour, int scoop, bool waffer);

		//Calculate prices for every field
		//Per ORDER!
		void calculate(int flavour, int scoop, bool waffer);

		//Get the total out of the class
		//For vendor to use it
		double getTotal() const;
		
	};


}



#endif // !SENECA_ICECREAM_H
