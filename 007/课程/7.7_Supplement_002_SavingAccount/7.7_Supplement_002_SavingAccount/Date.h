#pragma once

class Date
{
	public:
	Date(int y = 0, int m = 0, int d = 0);	

	void show() const;
	int getTotalDays() const;
	int getYear() const;
	int getMonth() const;

	bool isLeapYear() const;

	private:
	int year, month, day;

	protected:
	int getYearDays() const;
	int getMonthDays() const;
	int getDayDays() const;	

	bool isLeap;
};