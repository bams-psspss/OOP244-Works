#ifndef SENECA_GRAPH_H
#define SENECA_GRAPH_H

namespace seneca
{
	//Fills the samples array with the values read from keyboard.
	void getSamples(int samples[], int noOfSamples);

	//Search in a collection of numbers, the biggest value.
	int findMax(int arr[], int arrSize);

	//Prints a scaled bar relevant to the maximum value in the samples array.
	void printSampleBar(int val, int max);

	//Draw a graph, allowing the user to visually compare the samples.
	void printGraph(int samples[], int noOfSamples, const char* label);
}
#endif