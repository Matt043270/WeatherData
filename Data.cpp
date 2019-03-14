#include "Data.h"



Data::Data()
{
	m_windSpeed = 0.0f;
	m_temp = 0.0f;
	m_solarRad = 0.0f;
}

void Data::SetWindSpeed(float w)
{
	m_windSpeed = w;
}

float Data::GetWindSpeed()
{
	return m_windSpeed;
}

void Data::SetTemperature(float t)
{
	m_temp = t;
}

float Data::GetTemperature()
{
	return m_temp;
}

void Data::SetSolarRadiation(float s)
{
	m_solarRad = s;
}

float Data::GetSolarRadiation()
{
	return m_solarRad;
}