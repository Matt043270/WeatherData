#ifndef RECORD_H
#define RECORD_H

#include "YearRecord.h"
#include "Data.h"
#include "DateTime.h"
#include <map>

	/**
	* @class	Record
	* @brief	A class that contains a map of the year records.
	*
	* @author	Matt Smooker
	* @version	01
	*/
class Record
{
public:

		/**
		* @brief	The default constructor for the Record class.
		*/
	Record();

		/**
		* @brief	Adds a year record to the map.
		*
		* @param	dateTime - the date and time information to be added to the map.
		* @param	data - The data to be added to the map.
		* @return	void
		*/
	void AddYearRecord(DateTime &dateTime, Data &data);

		/**
		* @brief	Retrieves a year record.
		*
		* @param	key - the key of the year record to be retrieved.
		* @return	YearRecord
		*/
	YearRecord GetYearRecord(unsigned key);

		/**
		* @brief	Checks if a year record exists in the map.
		*
		* @param	key - the key of the year record to be checked.
		* @return	bool
		*/
	bool CheckYearRecord(unsigned key);
	
private:
		/// A map of year records.
	std::map<unsigned, YearRecord> year_Records;
};

#endif // !RECORD_H