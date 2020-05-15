#pragma once
#include "Date.h"
#include <iostream>
using namespace std;

namespace 
{
	const int maxDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//建立数组，用于方便地储存同年1月1日到当前月的日数。
	const int daysBeforeMonth[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
}

Date::Date(int y, int m , int d)
{
	year = y;
	month = m;
	day = d;
	isLeap = isLeapYear();
	//检验年份输入是否有误。
	if (year < 1)
	{
		cout << "Wrong input of year!" << endl;
		exit(1);
	}
	//检验月份输入是否有误。
	if (month < 0 || month > 12)
	{
		cout << "Wrong input of month!" << endl;		
		exit(1);
	}
	//检验日收入是否有误。
	if (isLeap)
	{
		if (month == 2)
		{
			if (day < 1 || day > maxDays[1] + 1)
			{
				cout << "Wrong input of day!" << endl;
				exit(1);
			}
		}
	}
	else
	{
		if (day < 1 || day > maxDays[month - 1])
		{
			cout << "Wrong input of day!" << endl;
			exit(1);
		}
	}
}

bool Date::isLeapYear() const
{
	//这里书上的例子只用了一行代码。
	/*
	return year % 4 == 0 && year % 4 != 0 || year % 400 == 0;
	*/
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

int Date::getYears() const
{
	//因为计算的是本年1月1日到1/1/1的年份，因此本年的日期不应该被算入。
	return 365 * (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
}

int Date::getMonths() const
{
	if (month > 2)
	{
		return isLeap ? daysBeforeMonth[month - 1] + 1 : daysBeforeMonth[month - 1];
	}
	else
	{
		return daysBeforeMonth[month - 1];
	}
}

int Date::getDays() const
{
	return day - 1;
}

int Date::getTotalDays() const
{
	int y = getYears();
	int m = getMonths();
	int d = getDays();
	return y + m + d;
}

void Date::show() const
{
	std::cout << year << "-" << month << "-" << day << '\t';
}
