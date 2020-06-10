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
	//check year.
	if(year <= 0)
	{
		std::cout << "Wrong input for year" << std::endl;
		exit(1);
	}
	//check month.
	if(month <= 0 || month > 12)
	{
		std::cout << "Wrong input for month" << std::endl;
		exit(1);
	}
	//check day.
	if((!isLeap) || (isLeap && month != 2))
	{
		if(day <= 0 || day > daysForMonth[month] - daysForMonth[month -1])
		{
			std::cout << "Wrong input for day" << std::endl;
			exit(1);
		}
	}
	else
	{
		if(day <0 || day > 29)
		{
			std::cout << "Wrong input for day" << std::endl;
			exit(1);
		}
	}
}

int Date::getYear() const
{
	return year;
}

int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

void Date::show() const
{
	std::cout << year << "-" << month << "-" << day << '\t';
}

int Date::totalDays() const
{
	int days = countDays();
	int months = countMonths();
	int years = countYears();
	return days + months + years;
}

int Date::getMaxDays() const
{
	if(isLeap && month == 2)
	{
		return 29;
	}
	else
	{
		return daysForMonth[month] - daysForMonth[month - 1];
	}
}

int Date::operator -(Date date) const
{
	return this->totalDays() - date.totalDays();
}

bool Date::isLeapYear() const
{
	return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
}

int Date::countDays() const
{
	return day - 1;
}

int Date::countMonths() const
{
	if(isLeap && month > 2)
	{
		//闰年要多返回一天。
		//就这个问题我查了半天才发现错误。
		return daysForMonth[month - 1] + 1;
	}
	else
	{
		return daysForMonth[month - 1];
	}
}

int Date::countYears() const
{
	return 365 * (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
}