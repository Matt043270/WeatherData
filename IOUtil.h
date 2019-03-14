#ifndef IOUTIL_H
#define IOUTIL_H

#include "Data.h"
#include "Date.h"
#include "DateTime.h"
#include "Record.h"
#include "YearRecord.h"
#include "MonthRecord.h"
#include "DayRecord.h"
#include "Time.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>

using namespace std;

	/**
	* @class	IOUtil
	* @brief	The IOUtil class handles program input and output.
	*
	* @author	Matt Smooker
	* @version	02
	*/
class IOUtil
{
public:

		/**
		* @brief	The default constructor for the IOUtil class.
		*/
	IOUtil();

		/**
		* @brief	Reads the filenames from a text file.
		*
		*	Reads the file names from a text file, and passes the file name
		*	to the ReadInData method.
		*
		* @param	inputFile - the name of the text file containing the filenames.
		* @param	rec - the Record.
		* @return	void
		*/
	void ReadFileNames(string inputFile, Record &rec);

		/**
		* @brief	Reads in the data from a csv file.
		*
		*	Reads in data from a csv file, and inserts the data into the record maps.
		*
		* @param	fileName - the name of the csv file.
		* @param	rec - the Record.
		* @return	bool
		*/
	bool ReadInData(string fileName, Record &rec);

		/**
		* @brief	Displays the menu text on the screen.
		*
		* @return	void
		*/
	void DisplayMenu();

		/**
		* @brief	Calls the appropriate method based on the user selection.
		*
		*	Prompts the user for input, and calls the appropriate method. Continues to run
		*	until the user chooses to quit.
		*
		* @param	rec - the Record.
		* @return	void
		*/
	void Menu(Record &rec);

		/**
		* @brief	Menu selection one.
		*
		*	Prompts the user for a month and a year. Displays the average wind speed (km/h)
		*	and	average ambient air temperature (degrees C) for that month.
		*
		* @param	rec - the Record.
		* @return	void
		*/
	void SelectionOne(Record &rec);

		/**
		* @brief	Menu selection two.
		*
		*	Prompts the user for a year. Displays the average wind speed (km/h) and average
		*	ambient air temperature (degrees C) for each month in that year. If no information
		*	is available for a month, "No data available" is displayed. 
		*
		* @param	rec - the Record.
		* @return	void
		*/
	void SelectionTwo(Record &rec);

		/**
		* @brief	Menu selection three.
		*
		*	Prompts the user for a year. Displays the total solar radiation (kwh/m^2) for 
		*	each month in that year. If no information is available for a month, "No data
		*	available" is displayed.
		*
		* @param	rec - the Record.
		* @return	void
		*/
	void SelectionThree(Record &rec);

		/**
		* @brief	Menu selection four.
		*
		*	Prompts the user for a year. Outputs the year, month, average monthly wind
		*	speed (km/h), monthly average ambient air temperature (degrees C), and 
		*	total monthly solar radiation (kwh/m^2) to a file called windTempSolar.csv
		*
		*	If no information for the year is available, "No data." is written to the file.
		*	If there are any months in the year that contain no information, they are omitted
		*	from the output file.
		*
		* @param	rec - the Record. 
		* @return	void
		*/
	void SelectionFour(Record &rec);

		/**
		* @brief	Menu selection five.
		*
		*	Prompts the user to enter a date in format dd/mm/yyyy. Outputs to the screen the
		*	highest solar radiation value for that date and the times which it occurred.
		*
		* @param	rec - the Record.
		* @return	void
		*/
	void SelectionFive(Record &rec);

		/**
		* @brief	Checks if the user wishes to continue using the program.
		*
		*	After successfully completing a menu option, the user is prompted whether they would
		*	like to continue. If so, the menu is redisplayed, otherwise the message "You quit." 
		*	is displayed, and the program exits. 
		*
		* @param	rec - the Record.
		* @return	void
		*/
	void Continue(Record &rec);

		/**
		* @brief	Exits the program.
		*
		* @return	int
		*/
	int Quit();

	//void Print(float key, vector<Time> value);

private:
	
		/**
		* @brief	Calculates the average wind speed.
		*
		*	Iterates through every day in the month, and calculates the average wind speed. 
		*	If there is no information, 0 is returned, otherwise the method rounds the average
		*	to one decimal place and returns.
		*
		* @param	rec - the Record.
		* @param	year - the year given by the user.
		* @param	month - the month given by user.
		* @return	float
		*/
	float CalculateAverageWindSpeed(Record &rec, int year, int month);

		/**
		* @brief	Calculates the average ambient air temperature.
		*
		*	Iterates through every day in the month, and calculates the average ambient
		*	air temperature. If there is no inforamtion, 0 is returned,  otherwise the method
		*	rounds the average to one decimal place and returns.
		*
		* @param	rec - the Record. 
		* @param	year - the year given by the user.
		* @param	month - the month given by the user. 
		* @return	float
		*/
	float CalculateAverageTemperature(Record &rec, int year, int month);

		/**
		* @brief	Calculates the total solar radiation for a month.
		*
		*	Iterates through every day in the month, and calculates the total solar radiation.
		*	If there is no information, a 0 is returned, otherwise the method rounds the total
		*	to one decimal place.
		*
		* @param	rec - the Record.
		* @param	year - the year given by the user.
		* @param	month - the month given by the user.
		* @return	float
		*/
	float CalculateTotalSolarRadiation(Record &rec, int year, int month);
};

#endif // !IOUTIL_H