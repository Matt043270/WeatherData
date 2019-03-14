#include "Date.h"

Date::Date()
{
	m_day = 0;
	m_month = 0;
	m_year = 0;
}

void Date::SetDay(int d)
{
	m_day = d;
}

int Date::GetDay()
{
	return m_day;
}

void Date::SetMonth(int m)
{
	m_month = m;
}

int Date::GetMonth()
{
	return m_month;
}

void Date::SetYear(int y)
{
	m_year = y;
}

int Date::GetYear()
{
	return m_year;
}