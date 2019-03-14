#ifndef MONTHRECORD_H
#define MONTHRECORD_H

#include "DayRecord.h"
#include <map>

	/**
	* @class	MonthRecord
	* @brief	A class that contains all the day records for a certain month.
	*
	* @author	Matt Smooker
	* @version	01
	*/
class MonthRecord
{
public:

		/**
		* @brief	The default constructor of the MonthRecord class.
		*/
	MonthRecord();

		/**
		* @brief	Adds a day record to the map
		*
		* @param	dateTime - the date and time data to be added to the map
		* @param	data - the data to be added to the map
		* @return	void
		*/
	void AddDayRecord(DateTime &dateTime, Data &data);

		/**
		* @brief	Retrieves a day record
		*
		* @param	key - the number of the day to be returned.
		* @return	DayRecord
		*/
	DayRecord GetDayRecord(unsigned key);

private:
		/// A map of the day records.
	std::map<unsigned, DayRecord> day_Records;
};


#endif // !MONTHRECORD_H