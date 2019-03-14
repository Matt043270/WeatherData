#include "MonthRecord.h"

MonthRecord::MonthRecord()
{

}

void MonthRecord::AddDayRecord(DateTime & dateTime, Data &data)
{
	day_Records[dateTime.GetDate().GetDay()].InsertData(dateTime, data);
}

DayRecord MonthRecord::GetDayRecord(unsigned key)
{
	return day_Records[key];
}
