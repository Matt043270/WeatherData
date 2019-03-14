#include "DayRecord.h"


DayRecord::DayRecord()
{

}

void DayRecord::InsertData(DateTime & dateTime, Data &data)
{
	windSpeedTree.Insert(data.GetWindSpeed(), dateTime.GetTime());

	temperatureTree.Insert(data.GetTemperature(), dateTime.GetTime());

	// If the solar radiation is <100, it is not counted.
	if (data.GetSolarRadiation() >= 100.0f)
	{
		solarRadiationTree.Insert(data.GetSolarRadiation(), dateTime.GetTime());
	}

}

float DayRecord::GetTotalWindSpeed()
{
	return windSpeedTree.GetTotal();
}

float DayRecord::GetTotalSolarRadiation()
{
	return solarRadiationTree.GetTotal();
}

float DayRecord::GetTotalTemp()
{
	return temperatureTree.GetTotal();
}

int DayRecord::GetWindCount()
{
	return windSpeedTree.GetCount();
}

int DayRecord::GetSolarCount()
{
	return solarRadiationTree.GetCount();
}

int DayRecord::GetTemperatureCount()
{
	return temperatureTree.GetCount();
}

BST<float, Time> DayRecord::GetSolarTree()
{
	return solarRadiationTree;
}
