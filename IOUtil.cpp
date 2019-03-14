#include "IOUtil.h"

const string monthName[] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

IOUtil::IOUtil()
{
}

void IOUtil::ReadFileNames(string inputFile, Record &rec)
{
	ifstream inFile(inputFile);

	if (!inFile)
	{
		return;
	}

	string tempString;

	do 
	{
		getline(inFile, tempString);
		ReadInData("Data/" + tempString, rec);
	} while (!inFile.eof());
}

bool IOUtil::ReadInData(string fileName, Record &rec)
{
	ifstream inFile(fileName);

	if (!inFile)
	{
		return false;
	}

	cout << "Reading file: " << fileName << " ..." << endl;

	string tempString;
	Date tempDate;
	Time tempTime;
	DateTime tempDateTime;
	Data tempData;

	getline(inFile, tempString);

	do
	{
		getline(inFile, tempString, '/');
		tempDate.SetDay(stoi(tempString.c_str()));

		getline(inFile, tempString, '/');
		tempDate.SetMonth(stoi(tempString.c_str()));

		getline(inFile, tempString, ' ');
		tempDate.SetYear(stoi(tempString.c_str()));

		tempDateTime.SetDate(tempDate);

		getline(inFile, tempString, ':');
		tempTime.SetHour(stoi(tempString.c_str()));

		getline(inFile, tempString, ',');
		tempTime.SetMinute(stoi(tempString.c_str()));

		tempDateTime.SetTime(tempTime);

		for (int i = 0; i < 9; i++)
		{
			getline(inFile, tempString, ',');
		}

		getline(inFile, tempString, ',');
		tempData.SetWindSpeed(stof(tempString.c_str()));

		getline(inFile, tempString, ',');
		tempData.SetSolarRadiation(stof(tempString.c_str()));

		for (int i = 0; i < 5; i++)
		{
			getline(inFile, tempString, ',');
		}

		getline(inFile, tempString);
		tempData.SetTemperature(stof(tempString.c_str()));

		rec.AddYearRecord(tempDateTime, tempData);

	} while (!inFile.eof());

	cout << "Successful." << endl;

	Sleep(2000);

	return true;
}

void IOUtil::DisplayMenu()
{
	std::cout << "****************************************************************************************************" << std::endl;
	std::cout << "1. Calculate the average wind speed and ambient air temperature for a specified month and year." << std::endl;
	std::cout << "2. Calculate the average wind speed and ambient air temperature for each month in a specified year." << std::endl;
	std::cout << "3. Calculate the total solar radiation in kWh/m^2 for each month in a specified year." << std::endl;
	std::cout << "4. Calculate the average wind speed (km/h), average ambient air temperature and total solar radiation" << std::endl;
	std::cout << "   in kWhm^2 for each month in a given year, and output to a file." << std::endl;
	std::cout << "5. Display the times of highest solar radiation for a specified date." << std::endl;
	std::cout << "6. Quit the program." << std::endl;
	std::cout << "****************************************************************************************************" << std::endl;
}

void IOUtil::Menu(Record &rec)
{
	char userChoice;

	do 
	{
		DisplayMenu();
		cout << "Please enter selection: " << endl;
		cin >> userChoice;

		switch (userChoice)
		{
		case '1':
			SelectionOne(rec);
			break;

		case '2':
			SelectionTwo(rec);
			break;

		case '3':
			SelectionThree(rec);
			break;

		case '4':
			SelectionFour(rec);
			break;

		case '5':
			SelectionFive(rec);
			break;

		case '6':
			cout << "Quit" << endl;
			Sleep(2000);
			Quit();
			break;

		default:
			cout << "Invalid input. Try again." << endl;
			break;
		} 
	} while (userChoice != '6');
}

void IOUtil::SelectionOne(Record &rec)
{
	int month = 0;
	int year = 0;
	float wind = 0;
	float temp = 0;

	cout << "Enter month in numbers (mm): " << endl;
	cin >> month;
	cout << "Enter year in numbers (yyyy): " << endl;
	cin >> year;

	wind = CalculateAverageWindSpeed(rec, year, month);
	temp = CalculateAverageTemperature(rec, year, month);

	cout <<"\n" << monthName[month] << " " << year << ": ";

	if (wind <= 0 || temp <= 0)
	{
		cout << "No data available." << endl;
	}
	else
	{
		cout << wind << "km/h, " << temp << " degrees C" << endl;
	}

	cout << endl;

	Continue(rec);
}

void IOUtil::SelectionTwo(Record & rec)
{
	int year = 0;
	float wind = 0;
	float temp = 0;

	cout << "Enter year in numbers (yyyy): " << endl;
	cin >> year;

	cout << "\n" << year << endl;

	for (int i = 1; i <= 12; i++)
	{
		cout << monthName[i] << ": ";
		wind = CalculateAverageWindSpeed(rec, year, i);
		temp = CalculateAverageTemperature(rec, year, i);
		
		if (wind <= 0 || temp <= 0)
		{
			cout << "No data available." << endl;
		}
		else
		{
			cout << wind << "km/h, " << temp << " degrees C" << endl;
		}
	}

	cout << endl;

	Continue(rec);
}

void IOUtil::SelectionThree(Record & rec)
{
	int year = 0;
	float solar = 0;

	cout << "Enter year in numbers (yyyy): " << endl;
	cin >> year;
	cout << "\n" << year << endl;

	for (int i = 1; i <= 12; i++)
	{
		solar = CalculateTotalSolarRadiation(rec, year, i);
		cout << monthName[i] << ": ";

		if (solar <= 0)
		{
			cout << "No data available." << endl;
		}
		else
		{
			cout << solar << " kWh/m^2" << endl;
		}
	
	}

	cout << endl;

	Continue(rec);
}

void IOUtil::SelectionFour(Record & rec)
{
	ofstream output;
	output.open("Data/windTempSolar.csv");
	
	int year = 0;
	float wind = 0;
	float temp = 0;
	float solar = 0;

	cout << "Enter year in numbers (yyyy): " << endl;
	cin >> year;

	output << "Year\n";
	output << "Month, Average Wind Speed, Average Temperature, Solar Radiation\n";
	output << year << '\n';

	if (!rec.CheckYearRecord(year))
	{
		output << "No data.";
	}

	else
	{
		for (int i = 1; i <= 12; i++)
		{
			wind = CalculateAverageWindSpeed(rec, year, i);

			if (wind > 0)
			{
				temp = CalculateAverageTemperature(rec, year, i);
				solar = CalculateTotalSolarRadiation(rec, year, i);

				output << monthName[i] << ',' << wind << ',' << temp << ',' << solar << '\n';
			}

		}
	}

	output.close();

	cout << endl;

	Continue(rec);

}

void IOUtil::SelectionFive(Record & rec)
{
	int year = 0;
	int month = 0;
	int day = 0;
	string tempString;
	string userInput;

	cout << "Enter a date (dd/mm/yyyy): " << endl;
	cin >> userInput;

	stringstream stream(userInput);

	getline(stream, tempString, '/');
	day = stoi(tempString.c_str());

	getline(stream, tempString, '/');
	month = stoi(tempString.c_str());

	getline(stream, tempString);
	year = stoi(tempString.c_str());


	cout << "\nDate: " << userInput << endl;

	rec.GetYearRecord(year).GetMonthRecord(month).GetDayRecord(day).GetSolarTree().Max();

	Continue(rec);

}

void IOUtil::Continue(Record & rec)
{
	char userChoice;
	bool flag = false;

	do
	{
		cout << "Do you wish to continue? [Y/N]: " << endl;
		cin >> userChoice;

		switch (userChoice)
		{
		case 'Y':
		case 'y':
			flag = true;
			system("CLS");
			Menu(rec);
			break;

		case 'N':
		case 'n':
			flag = true;
			cout << "You quit." << endl;
			Sleep(2000);
			Quit();
			break;

		default:
			cout << "Invalid entry." << endl;
			break;
		}
	} while (!flag);
}

int IOUtil::Quit()
{
	exit(0);
}


float IOUtil::CalculateAverageWindSpeed(Record &rec, int year, int month)
{
	float aveWindSpeed = 0;
	float totalWind = 0;
	int totalCount = 0;

	for (int i = 1; i <= 31; i++)
	{
		totalWind += rec.GetYearRecord(year).GetMonthRecord(month).GetDayRecord(i).GetTotalWindSpeed();
		totalCount += rec.GetYearRecord(year).GetMonthRecord(month).GetDayRecord(i).GetWindCount();
	}


	if (totalWind <= 0.0f)
	{
		return aveWindSpeed;
	}
	else
	{
		aveWindSpeed = ceil(((totalWind / totalCount) * pow(10, 1)) - 0.49) / pow(10, 1);
		return aveWindSpeed;
	}

}


float IOUtil::CalculateAverageTemperature(Record & rec, int year, int month)
{
	float aveTemp = 0;
	float totalTemp = 0;
	int totalCount = 0;

	for (int i = 1; i <= 31; i++)
	{
		totalTemp += rec.GetYearRecord(year).GetMonthRecord(month).GetDayRecord(i).GetTotalTemp();
		totalCount += rec.GetYearRecord(year).GetMonthRecord(month).GetDayRecord(i).GetTemperatureCount();
	}


	if (totalTemp <= 0.0f)
	{
		return aveTemp;
	}
	else
	{
		aveTemp = ceil(((totalTemp / totalCount) * pow(10, 1)) - 0.49) / pow(10, 1);
		return aveTemp;
	}
}

float IOUtil::CalculateTotalSolarRadiation(Record & rec, int year, int month)
{
	float solarRadiation = 0;

	for (int i = 1; i <= 31; i++)
	{
		solarRadiation += rec.GetYearRecord(year).GetMonthRecord(month).GetDayRecord(i).GetTotalSolarRadiation();
	}

	if (solarRadiation <= 0)
	{
		return solarRadiation;
	}
	else
	{
		solarRadiation = ceil((((solarRadiation * (1.0f / 6.0f)) / 1000.0f) * pow(10, 1)) - 0.49) / pow(10, 1);
		return solarRadiation;
	}

}
