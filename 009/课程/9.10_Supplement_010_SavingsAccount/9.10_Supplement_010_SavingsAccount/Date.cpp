#include "Date.h"
#include <iostream>
using namespace std;

namespace
{
	const int daysForMonth[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
}

Date::Date(int y, int m, int d)
{
	if(y <= 0)
	{
		cerr << "Wrong year" << endl;
		exit(1);
	}
	year = y;
	isLeap = isLeapYear();

	if(m < 1 || m > 12)
	{
		cerr << "Wrong month" << endl;
		exit(1);
	}
	month = m;

	if(d < 0)
	{
		cerr << "Wrong day" << endl;
		exit(1);
	}
	if(isLeap && m == 2)
	{
		if(d > 29)
		{
			cerr << "Wrong day" << endl;
			exit(1);
		}
	}
	else
	{
		if(d > daysForMonth[month] - daysForMonth[month - 1])
		{
			cerr << "Wrong day" << endl;
			exit(1);
		}
	}
	day = d;
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
	cout << year << "-" << month << "-" << day << "\t";
}

int Date::totalDays() const
{
	int d = countDays();
	int m = countMonths();
	int y = countYears();
	return d + m + y;
}

int Date::getMonthDays() const
{
	if(month == 2 && isLeap)
	{
		return 29;
	}
	else
	{
		return daysForMonth[month] - daysForMonth[month - 1];
	}
}

int Date::operator-(const Date &d) const
{
	return totalDays() - d.totalDays();
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
		return daysForMonth[month - 1] + 1;
	}
	else
	{
		return daysForMonth[month - 1];
	}
}

int Date::countYears() const
{
	return (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
}