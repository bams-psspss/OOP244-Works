/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:		Saturday 27 January, 2024
**************************************************/

#ifndef SENECA_ASSESSMENT_H
#define SENECA_ASSESSMENT_H

#define TITLE_LEN 60
#define FMT_LEN 40

namespace seneca
{
	//Hold Dynamically
	struct Assessment
	{
		double* m_mark;
		char* m_title;
	 };


	//Reads one integer from the fptr file
	//Into the value reference
	//Return true if success
	bool read(int& value, FILE* fptr);


	//Read one Double from the fptr file
	//Into value reference
	//Return True if Sucess
	bool read(double& value, FILE* fptr);

	//Skip the comma and then reads a cstring
	//No longer than 60 chars from fptr into ADDRESS
	//fmt = ",%60[^\n]\n"
	bool read(char* cstr, FILE* fptr);


	//Try to read double value for the mark and a string for title
	//Into a temporary local double variable and 60 chard long CString
	//If success, allocate dynamic double and dynamic cString 
	//And copy the the temp data to Assess
	bool read(Assessment& assess, FILE* fptr);


	//Receive reference of a dynamic Assessment.
	//Delete dynamic assessment array
	//Dynamic array loop, deletd by goinf through each memeber
	//Delete dynamaic double and cString
	//Then delete itself
	void freeMem(Assessment*& aptr, int size);

	//receives reference of Assessment pointer
	//Read one integer -> number of records to read
	//Allocate dynamic to aptr
	int read(Assessment*& aptr, FILE* fptr);

}

#endif