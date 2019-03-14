#include "DateTime.h"

DateTime::DateTime()
{
}

void DateTime::SetTime(Time t)
{
	m_time = t;
}

Time DateTime::GetTime()
{
	return m_time;
}

void DateTime::SetDate(Date d)
{
	m_date = d;
}

Date DateTime::GetDate()
{
	return m_date;
}