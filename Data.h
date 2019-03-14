#ifndef DATA_H
#define DATA_H

	/**
	* @class	Data
	* @brief	A class that stores weather data.
	*
	* Data consists of wind speed, ambient air temperature, and solar radiation.
	*
	* @author	Matt Smooker
	* @version	01
	*/
class Data
{
public:
	
		/**
		* @brief	Default constructor for the Data class.
		*/
	Data();

		/**
		* @brief	Sets the windSpeed variable. 
		*
		* @param	w - The wind speed to be stored.
		* @return	void
		*/
	void SetWindSpeed(float W);

		/**
		* @brief	Retrieves the windSpeed variable. 
		*
		* @return	float
		*/
	float GetWindSpeed();

		/**
		* @brief	Sets the temperature variable.
		*
		* @param	t - The temperature to be stored.
		* @return	void
		*/
	void SetTemperature(float t);

		/**
		* @brief	Retrieves the temperature variable. 
		*
		* @return	float
		*/
	float GetTemperature();

		/**
		* @brief	Sets the solarRadiation variable.
		*
		* @param	s - The solar radiation to be stored. 
		* @return	void
		*/
	void SetSolarRadiation(float s);

		/**
		* @brief	Retrieves the solarRadiation variable.
		*
		* @return	float 
		*/
	float GetSolarRadiation();

private:
		/// The wind speed.
	float m_windSpeed;

		/// The ambient air tempeerature.
	float m_temp;

		/// The solar radiation, stored in W/m^2.
	float m_solarRad;
};

#endif // !DATA_H