#ifndef SENECA_IO_H
#define SENECA_IO_H

namespace seneca
{
	const int MAX_NO_OF_SAMPLES = 20;
	const int GRAPH_WIDTH = 65;

	//Draw on the screen a line of dashes of specified length; 
	//  first and last symbols is +
	void drawLine(int length);

	// Count how many times the number can be divided by 10 before the result is 0.
	int intDigits(int value);

	//Prints to screen an integer in a field of specified size.
	// If the integer has fewer digits than the field size, 
	// the rest of the field will be filled withspaces.
	void printInt(int value, int fieldWidth);

	/// Moves the screen cursor backwards a specified number of positions.
	void moveCursorBack(int n);

	//
	void drawLineWithLabel(int length, const char* text);

	//
	int getInt(int min, int max);

	// Prints the text received as a parameter to the screen.
	void printMsg(const char* msg);

	//Prints an error to the screen, with the text received as a parameter.
	void printErrorMsg(const char* msg);

	//Displays the user interface menu. Each menu item will have a number
	//in front of it; the user chooses an item by typing the number
	//and then pressing <kbd>enter</kbd>.
	int menu(int noOfSamples);

}
#endif