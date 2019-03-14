#include "YearRecord.h"



YearRecord::YearRecord()
{
}

void YearRecord::AddMonthRecord(DateTime &dateTime, Data &data)
{
	month_Records[dateTime.GetDate().GetMonth()].AddDayRecord(dateTime, data);
}

MonthRecord YearRecord::GetMonthRecord(unsigned key)
{
	return month_Records[key];
}
