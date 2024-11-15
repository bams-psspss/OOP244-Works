/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:		Tuesday 30 January 2024
**************************************************/

#ifndef SENECA_GUEST_H
#define SENECA_GUEST_H

#define MAX_NAME 50
#define LEGAL_LEN 5


namespace seneca
{
	struct Guest
	{
		char* m_firstName;
		char* m_lastName;
		bool m_adult;
	};


	// sets the Guest variables and sets the m_adult flag to true if the age is greater than or equal to 18
	void set(Guest& guest, const char* first, const char* last, int age);

	// Prints the guest name:
	// "Name Surname(child)"
	// The child flag is printed if the guest is not an adult
	// and if the names are not set, "Vacated!" is printed.
	void print(const Guest& guest);

	// books the guest information from the console:
	// Name: Jake<ENTER>
	// Lastname: Doe<ENTER>
	// Age: 10<ENTER>
	void book(Guest& guest);

	// vacates the guest by dallocating its memory.
	void vacate(Guest& guest);

	//Check the member in the Guest if its null or not
	bool checkForNotNull(Guest guest);
	
	//Check if the guess is over 18 or not
	bool legalAge(int age);

}
#endif