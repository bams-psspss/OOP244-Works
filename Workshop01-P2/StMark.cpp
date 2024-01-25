/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:		Wednesday 24 January 2024
**************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

#include "StMark.h"
#include "file.h"
#include "graph.h"

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
		StMark student[MAX_NUM_REC + 1] = { {0} };		
		int score[RANGE + 1] = { };

		bool success = false;
		int numOfRec;
		int i;

		if (openFile(filename))
		{
			numOfRec = readMarks(student);

		
			groupingScore(student, numOfRec, score, RANGE);

			//Print the graph
			printGraph(score, RANGE, "Students' mark distribution");

			//Sorting the Score
			sortingScore(student, numOfRec);


			for (i = 0; i < numOfRec; i++)
			{
				cout << i + 1;

				if (i + 1 > 0 && i + 1 < 10)
				{
					cout << "  ";
				}
				else if (i + 1 >= 10 && i + 1 < 100)
				{
					cout << " ";
				}
				cout << ": " << "[" << student[i].mark;
				if (student[i].mark < 100 && student[i].mark > 9)
				{
					cout << " ";
				}
				else if (student[i].mark < 10 && student[i].mark >= 0)
				{
					cout << "  ";
				}
				cout << "] ";
				cout << student[i].name << " " << student[i].surname << endl;
			}
			closeFile();
			success = true;
		}
		else
		{
			closeFile();
		}

		cout << "----------------------------------------" << endl;
		return success;
	}

	//Grouping the score into group from 100-0
	//Start from index 9
	//index 9 = 91 - 100 score
	void groupingScore(StMark* student, int numOfRec, int* score, int range)
	{
		int i;
		int whole, remain;

		for (i = 0; i < numOfRec; i++)
		{
			whole = 0;
			remain = 0;

			whole = student[i].mark / 10;

			remain = student[i].mark % 10;
						
			if (whole)
			{
				if (!remain)
				{
					score[whole - 1]++;
				}
				else
				{
					score[whole]++;
				}
			}
			else
			{
				score[0]++;
			}
		}
	}

	//Sorting student according to the mark
	//Descending order
	void sortingScore(StMark* student, int numOfRec)
	{
		int i, j;

		for (i = 0; i < numOfRec - 1; i++)
		{
			for (j = 0; j < numOfRec - 1 - i; j++)
			{
				if (student[j].mark < student[j + 1].mark)
				{
					swap(student[j], student[j + 1]);
				}
			}
		}
	}



}


