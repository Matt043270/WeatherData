#ifndef DATE_H
#define DATE_H

	/**
	* @class	Date
	* @brief	Class that stores date information.
	*
	* @author	Matt Smooker
	* @version	01
	*/
class Date
{
public:

		/**
		* @brief	The default constructor for the Date class.
		*/
	Date();

		/**
		* @brief	Sets the day variable.
		*
		* @param	d - the day to be stored.
		* @return	void
		*/
	void SetDay(int d);

		/**
		* @brief	Retrieves the day variable.
		*
		* @return	int
		*/
	int GetDay();

		/**
		* @brief	Sets the month variable.
		*
		* @param	m - the month to be stored. 
		* @return	void
		*/
	void SetMonth(int m);

		/**
		* @brief	Retrieves the month variable.
		*
		* @return	int
		*/
	int GetMonth();

		/**
		* @brief	Sets the year variable.
		*
		* @param	y - the year to be stored.
		* @return	void
		*/
	void SetYear(int y);

		/**
		* @brief	Retrieves the year variable.
		*
		* @return	int
		*/
	int GetYear();

private:
		/// The day number.
	int m_day;

		/// The month number.
	int m_month;

		/// The year.
	int m_year;
};

#endif // !DATE_H