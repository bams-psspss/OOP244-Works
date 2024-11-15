/***********************************************************************
OOP244 Workshop # p2:
Version 1.0
Date	   winter 2024
Author	Fardad Soleimanloo
Description
  tests the file module of workshop 1 part 2(DIY)
Revision History
-----------------------------------------------------------
Name            Date            Reason
***********************************************************************/

/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:		Wednesday 24 January 2024
**************************************************/

#ifndef SENECA_STMARK_H
#define SENECA_STMARK_H

#define F_NAME_LEN 20
#define L_NAME_LEN 30
#define MAX_NUM_REC 1000
#define RANGE 10
namespace seneca 
{

    /// <summary>
    /// Record of a mark received by a student.
    /// </summary>
    struct StMark 
    {
        char name[F_NAME_LEN + 1];
        char surname[L_NAME_LEN + 1];
        int mark;
    };
   


    /// <summary>
    /// Tries to open the students' mark data file. 
    /// If successful it will print a report based on the 
    /// date in the file.
    /// </summary>
    /// <param name="filename">, holds the data file name</param>
    /// <returns>True if the date files is opened succesfully, 
    /// otherwise returns false</returns>
    bool printReport(const char* filename);

    //Grouping the score into group from 100-0
    //Start from index 9
    //index 9 = 91 - 100 score
    void groupingScore(StMark* student, int numOfRec, int* score, int range);

    //Sorting student according to the mark
    //Descending order  
    void sortingScore(StMark* student, int numOfRec);

}
#endif // !SENECA_STMARK_H


