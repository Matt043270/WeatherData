#include "Record.h"



Record::Record()
{
}

void Record::AddYearRecord(DateTime & dateTime, Data &data)
{
	year_Records[dateTime.GetDate().GetYear()].AddMonthRecord(dateTime, data);
}

YearRecord Record::GetYearRecord(unsigned key)
{
	return year_Records[key];
}

bool Record::CheckYearRecord(unsigned key)
{
	map<unsigned, YearRecord>::iterator it;
	it = year_Records.find(key);

	if (it != year_Records.end())
	{
		return true;
	}

	else
	{
		return false;
	}
}
