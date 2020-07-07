#pragma once

class Date
{
	public:
	Date(int year = 1, int month = 1, int day = 1);
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	void show() const;
	int totalDays() const;
	int getMonthDays() const;
	int operator -(const Date &d) const;
	bool isLeap;
	
	//�����ȡ���ڵĺ���ʵ����Ҳ�ǿ��п��޵ġ���������ж���ͼ������������ĸ��ӳ̶ȡ�
	static Date read();
	bool operator < (Date const &date) const;

	private:
	int year, month, day;
	bool isLeapYear() const;
	int countDays() const;
	int countMonths() const;
	int countYears() const;
};