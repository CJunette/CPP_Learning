#include "Date.h"
#include <iostream>

namespace
{
	const int daysForMonth[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
}

Date::Date(int y, int m, int d):
	year(y), month(m), day(d)
{
	isLeap = isLeapYear();
	if(y < 1)
	{
		std::cout << "Wrong input of year." << std::endl;
		exit(1);
	}
	if(m < 1 || m > 12)
	{
		std::cout << "Wrong input of month." << std::endl;
		exit(1);
	}

	if(day < 1)
	{
		std::cout << "Wrong input of day." << std::endl;
		exit(1);
	}
	else
	{
		if(isLeap && m == 2 && day > daysForMonth[m] - daysForMonth[m - 1] + 1)
		{			
			std::cout << "Wrong input of day." << std::endl;
			exit(1);
		}
		else
		{
			if(day > daysForMonth[m] - daysForMonth[m - 1])
			{
				std::cout << "Wrong input of day." << std::endl;
				exit(1);
			}
		}
	}
}

bool Date::isLeapYear() const
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int Date::getYearDays() const
{
	return 365 * (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
}

//注意这里，当闰年且月份大于2时，需要加一天。
int Date::getMonthDays() const
{
	if(isLeap && month > 2)
	{
		return daysForMonth[month - 1] + 1;
	}
	else
	{
		return daysForMonth[month - 1];
	}
}

int Date::getDayDays() const
{
	return day - 1;
}

int Date::getTotalDays() const
{
	int y = getYearDays();
	int m = getMonthDays();
	int d = getDayDays();
	return y + m + d;
}

void Date::show() const
{
	std::cout << year << "-" << month << "-" << day;
}

int Date::getYear() const
{
	return year;
}

int Date::getMonth() const
{
	return month;
}