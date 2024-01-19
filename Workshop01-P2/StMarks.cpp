#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "StMark.h"

using namespace std;

namespace seneca
{
	/// <summary>
/// Tries to open the students' mark data file. 
/// If successful it will print a report based on the 
/// date in the file.
/// </summary>
/// <param name="filename">, holds the data file name</param>
/// <returns>True if the date files is opened succesfully, 
/// otherwise returns false</returns>

	bool printReport(const char* filename)
	{
		char fmt[FMT_LEN + 1] = { 0 };
		char newline;
		int i;
		bool open = true;

		StMark 

		FILE* fp = NULL;

		fp = fopen(filename, "r");
		if (fp != NULL)
		{

			sprintf(fmt, "%%d,%%d,%%d[^\n]%%c", F_NAME_LEN, L_NAME_LEN);


			while (i < MAX_NUM_REC && fscanf(fp, fmt,)
			cout << "It indeed open!" << endl;



			fclose(fp);
			fp = NULL;
		}
		else
		{
			open = false;
		}

		return open;
	}



}