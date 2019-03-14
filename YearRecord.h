#ifndef YEARRECORD_H
#define YEARRECORD_H

#include "Data.h"
#include "DateTime.h"
#include "MonthRecord.h"
#include <map>

	/**
	* @class	YearRecord
	* @brief	A class that contains month records.
	*
	* @author	Matt Smooker
	* @version	01
	*/
class YearRecord
{
public:

		/**
		* @brief	The default constructor for the YearRecord.
		*/
	YearRecord();

		/**
		* @brief	Adds a month record to the map.
		*
		* @param	dateTime - the date and time information to be added to the map.
		* @param	data - the data to be added to the map.
		* @return	void
		*/
	void AddMonthRecord( DateTime &dateTime, Data &data);

		/**
		* @brief	Retrieves a month record from the map.
		*
		* @param	key
		* @return	MonthRecord
		*/
	MonthRecord GetMonthRecord(unsigned key);

private:

		/// A map of month records.
	std::map<unsigned, MonthRecord> month_Records;
};


#endif // !YEARRECORD_H