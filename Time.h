#ifndef TIME_H
#define TIME_H

	/**
	* @class	Time
	* @brief	A class that contains time data.
	*
	* @author	Matt Smooker
	* @version	01
	*/
class Time
{
public:

		/**
		* @brief	The default constructor for the Time class.
		*/
	Time();

		/**
		* @brief	Sets the hour variable.
		*
		* @param	h - the hour to be set.
		* @return	void
		*/
	void SetHour(int h);

		/**
		* @brief	Retrieves the hour variable.
		*
		* @return	int
		*/
	int GetHour();

		/**
		* @brief	Sets the minute variable.
		*
		* @param	m - the minute to be set.
		* @return	void
		*/
	void SetMinute(int m);

		/**
		* @brief	Retrieves the minute variable.
		*
		* @return	int
		*/
	int GetMinute();

private:

		/// The hour.
	int m_hour;

		/// The minute.
	int m_minute;
};

#endif // ! TIME_H