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
		StMark student[MAX_NO_RECS + 1] = { {0} };

		bool success = false;
		int numOfRec;
		int score[RANGE + 1] = { 0 };
		int i, j;


		if (openFile(filename))
		{
			numOfRec = readMarks(student);
			groupingScore(student, numOfRec, score);
			//whatIf(student, numOfRec, score);


			//Delete 
			//printf("%d\n", numOfRec);
			//for (i = 0; i < RANGE; i++)
			//{
				//printf("%d\n", score[i]);
			//}
			//This block after done!!!!

			//Print the graph OK!!!
			printGraph(score, 10, "Students' mark distribution");

			for (i = 0; i < numOfRec - 1; i++)
			{
				for (j = 0; j < numOfRec - 1 - i; j++)
				{
					if (student[j].mark < student[j + 1].mark)
					{
						swap(student[j].mark, student[j + 1].mark);
					}
				}
			}
			
			for (i = 0; i < numOfRec; i++)
			{
				cout << i + 1;
				if (i + 1 > 0 && i + 1 < 10)
				{
					cout << " ";
				}
				cout << " : " << "[" << student[i].mark << " ]";
				cout << student[i].name << " " << student[i].surname << endl;
			}
			
			
			closeFile();

			success = true;
		}
		else
		{
			closeFile();
		}


		return success;
	}


	void whatIf(StMark* student, int numOfRec, int* score)
	{
		int i, j;
		int whole, remainder;

		for (i = 0; i < numOfRec; i++)
		{
			whole = student[i].mark / 10;
			remainder = student[i].mark % 10;

			for (j = 100; j > 0; j -= 10)
			{
				if (whole == 10)
				{
					score[whole]++;
				}
				else if (whole >= (j / 10) && remainder)
				{
					score[j / 10]++;
				}
			}
		}
	}



	void groupingScore(StMark* student, int numOfRec, int* score)
	{
		int i;

		for (i = 0; i < numOfRec; i++)
		{

			if (student[i].mark > 90 && student[i].mark <= 100)
			{
				score[0]++;
			}
			else if (student[i].mark > 80 && student[i].mark <= 90)
			{
				score[1]++;
			}
			else if (student[i].mark > 70 && student[i].mark <= 80)
			{
				score[2]++;
			}
			else if (student[i].mark > 60 && student[i].mark <= 70)
			{
				score[3]++;
			}
			else if (student[i].mark > 50 && student[i].mark <= 60)
			{
				score[4]++;
			}
			else if (student[i].mark > 40 && student[i].mark <= 50)
			{
				score[5]++;
			}
			else if (student[i].mark > 30 && student[i].mark <= 40)
			{
				score[6]++;
			}
			else if (student[i].mark > 20 && student[i].mark <= 30)
			{
				score[7]++;
			}
			else if (student[i].mark > 10 && student[i].mark <= 20)
			{
				score[8]++;
			}
			else
			{
				score[9]++;
			}

		}
	}
}


