#pragma once
#include "Date.h"
#include <iostream>
using namespace std;

namespace 
{
	const int maxDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//�������飬���ڷ���ش���ͬ��1��1�յ���ǰ�µ�������
	const int daysBeforeMonth[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
}

Date::Date(int y, int m , int d)
{
	year = y;
	month = m;
	day = d;
	isLeap = isLeapYear();
	//������������Ƿ�����
	if (year < 1)
	{
		cout << "Wrong input of year!" << endl;
		exit(1);
	}
	//�����·������Ƿ�����
	if (month < 0 || month > 12)
	{
		cout << "Wrong input of month!" << endl;		
		exit(1);
	}
	//�����������Ƿ�����
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
	//�������ϵ�����ֻ����һ�д��롣
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
	//��Ϊ������Ǳ���1��1�յ�1/1/1����ݣ���˱�������ڲ�Ӧ�ñ����롣
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
