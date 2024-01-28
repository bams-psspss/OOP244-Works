/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:		Saturday 27 January, 2024
**************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "Assessment.h"
using namespace std;

namespace seneca
{
	//Reads one integer from the fptr file
	//Into the value reference
	//Return true if success
	bool read(int& value, FILE* fptr)
	{
		bool valid = false;

		if (fptr != nullptr)
		{
			if (fscanf(fptr, "%d", &value) == 1)
			{
				valid = true;
			}
			else
			{
				valid = false;
			}
		}
		else
		{
			valid = false;
		}
		return valid;
	}

	//Read one Double from the fptr file
	//Into value reference
	//Return True if Sucess
	bool read(double& value, FILE* fptr)
	{
		bool valid = false;

		if (fptr != nullptr)
		{
			if (fscanf(fptr, "%lf", &value) == 1)
			{
				valid = true;
			}
			else
			{
				valid = false;
			}
		}
		else
		{
			valid = false;
		}
		return valid;
	}

	//Skip the comma and then reads a cstring
	//No longer than 60 chars from fptr into ADDRESS
	bool read(char* cstr, FILE* fptr)
	{
		bool valid = false;

		if (fptr != nullptr)
		{
			if(fscanf(fptr, ",%60[^\n]\n", cstr) == 1)
			{
				valid = true;
			}
			else
			{
				valid = false;
			}
		}
		else
		{
			valid = false;
		}
		return valid;

	}

	//Try to read double value for the mark and a string for title
	//Into a temporary local double variable and 60 chard long CString
	//If success, allocate dynamic double and dynamic cString 
	//And copy the the temp data to Assess
	bool read(Assessment& assess, FILE* fptr)
	{
		bool valid = false;
		double tempMark = 0;
		char tempTitle[TITLE_LEN + 1] = {};


		if (fptr != nullptr)
		{
			if (fscanf(fptr, "%lf,%60[^\n]\n", &tempMark, tempTitle) == 2)
			{
				assess.m_mark = new double;
				assess.m_title = new char[strlen(tempTitle) + 1];

				*assess.m_mark = tempMark;
				strcpy(assess.m_title, tempTitle);

				valid = true;
			}
			else
			{
				valid = false;
			}
		}
		else
		{
			valid = false;
		}

		return valid;
	}

	//Receive reference of a dynamic Assessment.
	//Delete dynamic assessment array
	//Dynamic array loop, deletd by goinf through each memeber
	//Delete dynamaic double and cString
	//Then delete itself
	void freeMem(Assessment*& aptr, int size)
	{
		int i;

		if (aptr != nullptr && size > 0)
		{

			for (i = 0; i < size; i++)
			{
				if (aptr[i].m_mark != nullptr)
				{
					delete aptr[i].m_mark;
					aptr[i].m_mark = nullptr;
				}

				if (aptr[i].m_title != nullptr)
				{
					delete[] aptr[i].m_title;
					aptr[i].m_title = nullptr;
				}
			}
			delete[] aptr;
			aptr = nullptr;
		}
		else
		{
			//Nothing to delete, because it is already null!!!!!!!
		}

	}

	//Receives reference of Assessment pointer
	//Read one integer -> number of records to read
	//Allocate dynamic to aptr
	int read(Assessment*& aptr, FILE* fptr)
	{
		int theNumber = 0;
		int sizeOfArr = 0;
		int i = 0;

		//Read one integer
		if (fptr != nullptr)
		{
			if (read(theNumber, fptr))
			{
				//Allocate a dynamic array of Assessments
				aptr = new Assessment[theNumber];

				for (i = 0; i < theNumber && read(aptr[i], fptr); i++)
				{
					sizeOfArr++;
				}
				if (i != theNumber)
				{
					freeMem(aptr, sizeOfArr);
					sizeOfArr = 0;
				}
			}
			else
			{
				sizeOfArr = 0;
			}
		}

		return sizeOfArr;

	}
}
