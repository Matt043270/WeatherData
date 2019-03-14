#ifndef DATETIME_H
#define DATETIME_H

#include "Date.h"
#include "Time.h"

	/**
	* @class	DateTime
	* @brief	A class that manages Date and Time objects.
	*
	* @author	Matt Smooker
	* @version	01
	*/
class DateTime
{
public:

		/**
		* @brief	The default constructor for the DateTime class.
		*/
	DateTime();

		/**
		* @brief	Sets the Time object.
		*
		* @param	t - The Time object to be set.
		* @return	void
		*/
	void SetTime(Time t);

		/**
		* @brief	Retrieves the Time object.
		*
		* @return	Time object.
		*/
	Time GetTime();

		/**
		* @brief	Sets the Date object.
		*
		* @param	d - The Date object to be set.
		* @return	void
		*/
	void SetDate(Date d);

		/**
		* @brief	Retrievs the Date object.
		*
		* @return	Date object.
		*/
	Date GetDate();

private:
		/// Date object
	Date m_date;
		
		/// Time object
	Time m_time;
};


#endif // !DATETIME_H
