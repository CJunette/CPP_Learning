#pragma once
#include <iostream>

class Date
{
	public:
	Date(int year = 1, int month = 1, int day = 1);
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	void show() const;
	int getMonthDays() const;
	bool isLeap;

	int totalDays() const;
	int operator -(const Date &date) const;

	int operator <(const Date &date) const;

	private:
	int year, month, day;
	bool isLeapYear() const;
	int countDays() const;
	int countMonths() const;
	int countYears() const;
};

std::istream &operator >> (std::istream &in, Date &date);
std::ostream &operator << (std::ostream &out, const Date &date);