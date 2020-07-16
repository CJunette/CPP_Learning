#include "Date.h"
#include <iostream>
#include <stdexcept>
using namespace std;

namespace
{
	const int daysForMonth[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
}

Date::Date(int y, int m, int d)
{
	if(y < 1)
	{
		throw runtime_error("Invalid date! Year can't be less than 1.");
	}
	year = y;
	isLeap = isLeapYear();

	if(m < 1 || m > 12)
	{
		throw runtime_error("Invalid date! Month can't be less than 1 or larger than 12.");
	}
	month = m;

	if(d < 1)
	{
		throw runtime_error("Invalid date! Day can't be less than 1.");
	}
	else
	{
		if(isLeap && month == 2)
		{
			if(d > 29)
			{
				throw runtime_error("Invalid date! Day can't be larger than the maximum day of corresponding month.");
			}
		}
		else
		{
			if(day > daysForMonth[month] - daysForMonth[month - 1])
			{
				throw runtime_error("Invalid date! Day can't be larger than the maximum day of corresponding month.");
			}
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

int Date::getMonthDays() const
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

int Date::totalDays() const
{
	int y = countYears();
	int m = countMonths();
	int d = countDays();
	return y + m + d;
}

int Date::operator -(const Date &d) const
{
	int td = totalDays() - d.totalDays();
	return td;
}

int Date::operator <(const Date &d) const
{
	return *this - d < 0;
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
	if(isLeap && month > 1)
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

istream &operator >> (istream &in, Date &date)
{
	int y, m, d;
	char c1, c2;
	in >> y >> c1 >> m >> c2 >> d;
	date = Date(y, m, d);
	return in;
}

ostream &operator << (ostream &out, const Date &date)
{
	out << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();
	return out;
}