#ifndef DAYRECORD_H
#define DAYRECORD_H

#include "BST.h"
#include <vector>
#include "Data.h"
#include "DateTime.h"
#include "Time.h"
#include <iostream>

using namespace std;

	/**
	* @class	DayRecord
	* @brief	A class that handles the data for a single day.
	*
	*	The DayRecord class contains the data structures for handling the data
	*	for a single day. 
	*
	* @author	Matt Smooker
	* @version 01
	*/
class DayRecord
{
public:

		/**
		* @brief	Default constructor for the DayRecord class.
		*/
	DayRecord();

		/**
		* @brief	Inserts the data into the data structures.
		*
		*	The time and the data are inserted into the relevent Binary Search Trees.
		*	The solar radiation is checked, and only if the value exceeds 100 is it
		*	inserted.
		*
		* @param	dateTime - the dateTime information to be inserted.
		* @param	data - the data information to be inserted.
		* @return	void
		*/
	void InsertData(DateTime &dateTime, Data &data);

		/**
		* @brief	Retrieves the total wind speed.
		*
		* @return	float
		*/
	float GetTotalWindSpeed();

		/**
		* @brief	Retrieves the total solar radiation.
		*
		* @return	float
		*/
	float GetTotalSolarRadiation();

		/**
		* @brief	Retrieves the total temperature.
		*
		* @return	float
		*/
	float GetTotalTemp();
	
		/**
		* @brief	Retrives the windSpeedTree size.
		*
		* @return	int
		*/
	int GetWindCount();

		/**
		* @brief	Retrieves the solarRadiationTree size.
		*
		* @return	int
		*/
	int GetSolarCount();

		/**
		* @brief	Retrieves the temperatureTree size.
		*
		* @return	int
		*/
	int GetTemperatureCount();

		/**
		* @brief	Retrievs the solarRadiationTree
		*
		* @return	BST<float, Time>
		*/
	BST<float, Time> GetSolarTree();

private:
		/// A BST of wind speed and Time.
	BST<float, Time> windSpeedTree;
		/// A BST of solar radiation and Time.
	BST<float, Time> solarRadiationTree;
		/// A BST of temperature and Time.
	BST<float, Time> temperatureTree;
};


#endif // !DAYRECORD_H