/*************************************************
Name:				Pattarawan Saravaneeyawong
Seneca Email:		psaravaneeyawong@myseneca.ca
Student ID:			130618234
Date Completed:		Wednesday 17 January 2024
*************************************************
 I have done all the coding by myself and only copied the code that
 my professor provided to complete my workshops and assignments.
*************************************************/

#ifndef SENECA_GRAPH_H
#define SENECA_GRAPH_H

namespace seneca
{
	// Fills the samples array with the statistic samples
	void getSamples(int samples[], int noOfSamples);

	// Finds the largest sample in the samples array, if it is larger than 70,
// therwise it will return 70. 
	int findMax(int samples[], int noOfSamples);

	// Prints a scaled bar relevant to the maximum value in samples array
	void printBar(int val, int max);

	// Prints a graph comparing the sample values visually 
	void printGraph(int samples[], int noOfSamples, const char* label);

}
#endif
