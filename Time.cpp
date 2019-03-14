#include "Time.h"

Time::Time()
{
	m_hour = 0;
	m_minute = 0;
}

void Time::SetHour(int h)
{
	m_hour = h;
}

int Time::GetHour()
{
	return m_hour;
}

void Time::SetMinute(int m)
{
	m_minute = m;
}

int Time::GetMinute()
{
	return m_minute;
}