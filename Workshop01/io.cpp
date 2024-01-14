#include <iostream>
#include "io.h"
using namespace std;

namespace seneca
{

	//Draw on the screen a line of dashes of specified length; 
	//  first and last symbols is +
	void drawLine(int length)
	{
		cout << '+';
		for (int i = 0; i < length - 2; ++i)
			cout << '-';
		cout << '+' << '\n';
	}

	// Count how many times the number can be divided by 10 before the result is 0.
	int intDigits(int value)
	{
		int count = 0;
		do
		{
			value /= 10;
			++count;
		} while (value != 0);

		return count;
	}

	//Prints to screen an integer in a field of specified size.
	// If the integer has fewer digits than the field size, 
	// the rest of the field will be filled withspaces.
	void printInt(int value, int fieldWidth)
	{
		
		cout << value;

		int extraSpaces = fieldWidth - intDigits(value);

		for (int i = 0; i < extraSpaces; ++i)
			cout << ' ';
	}

	/// Moves the screen cursor backwards a specified number of positions.
	void moveCursorBack(int n)
	{
		for (int i = 0; i < n; ++i)
			cout << '\b';
	}

	//
	void drawLineWithLabel(int length, const char* text)
	{
		cout << '+';
		for (int i = 0; i < length - 2; ++i)
			cout << '-';
		cout << '+';


		if (text)
		{
			moveCursorBack(length - 4);
		
			cout << ' ' << text << ' ';
		}

		cout << endl;
	}

	int getInt(int min, int max)
	{
		int val = min - 1;
		bool done = false;
		while (!done)
		{
		
			cin >> val;
			if (val < min || max < val)
			{

				cout << "  Invalid value! The value must be between "
					<< min << " and " << max << ".\n  Try again: ";
			}
			else
			{
				done = true;
			}
		}
		return val;
	}

	// Prints the text received as a parameter to the screen.
	void printMsg(const char* msg)
	{
		cout << "  " << msg;
	}

	//Prints an error to the screen, with the text received as a parameter.
	void printErrorMsg(const char* msg)
	{
		cout << "  ERROR: " << msg << endl;
	}

	//Displays the user interface menu. Each menu item will have a number
	//in front of it; the user chooses an item by typing the number
	//and then pressing <kbd>enter</kbd>.
	int menu(int noOfSamples)
	{
		{
			cout << endl;
			drawLine(GRAPH_WIDTH);
			cout << "| Number of Samples: ";

			printInt(noOfSamples, GRAPH_WIDTH - 21 - 2);
			cout << " |" << endl;

			drawLine(GRAPH_WIDTH);
		}

		cout << "| 1- Set Number of Samples                                      |" << endl;
		cout << "| 2- Enter Samples                                              |" << endl;
		cout << "| 3- Graphs                                                     |" << endl;
		cout << "| 0- Exit                                                       |" << endl;
		cout << "\\ >>                                                            /";
		moveCursorBack(GRAPH_WIDTH - 5);

		return getInt(0, 3);
	}
}

