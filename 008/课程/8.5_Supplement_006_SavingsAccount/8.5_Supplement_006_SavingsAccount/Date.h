#pragma once

class Date
{
	public:
	Date(int year, int month, int day);
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	void show() const;
	int totalDays() const;
	int getMaxDays() const;
	int operator -(Date date) const;
	bool isLeap;

	private:
	int year, month, day;	
	bool isLeapYear() const;
	int countDays() const;
	int countMonths() const;
	int countYears() const;
};