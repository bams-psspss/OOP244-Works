#include <iostream>
#include "io.h"
#include "graph.h"
using namespace std;

namespace seneca
{
	//Fills the samples array with the values read from keyboard.
	void getSamples(int samples[], int noOfSamples)
	{
		for (int i = 0; i < noOfSamples; ++i)
		{
			cout << "  >> " << (i + 1) << "/";
			printInt(noOfSamples, 2);
			cout << ": ";
			samples[i] = getInt(1, 1000000);
		}
	}

	//Search in a collection of numbers, the biggest value.
	int findMax(int arr[], int arrSize)
	{
		int max = arr[0];
		for (int i = 1; i < arrSize; i++)
			if (max < arr[i])
				max = arr[i];

		return max;
	}

	//Prints a scaled bar relevant to the maximum value in the samples array.
	void printSampleBar(int val, int max)
	{
		int barLength = (GRAPH_WIDTH - 5 - intDigits(max)) * val / max;
		cout << "| ";
		for (int i = 0; i < barLength; ++i)
			cout << '*';
		cout << ' ';
		printInt(val, GRAPH_WIDTH - 5 - barLength);
		cout << " |" << endl;
	}

	//Draw a graph, allowing the user to visually compare the samples.
	void printGraph(int samples[], int noOfSamples, const char* label)
	{
		int max = findMax(samples, noOfSamples);

		printMsg("\n");
		drawLineWithLabel(GRAPH_WIDTH, label);
		for (int i = 0; i < noOfSamples; ++i)
			printSampleBar(samples[i], max);
		drawLine(GRAPH_WIDTH);
	}
}