#pragma once
#include <iostream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

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

	template<class Archive>
	void serialize(Archive &ar, unsigned int version);

	private:
	int year, month, day;
	bool isLeapYear() const;
	int countDays() const;
	int countMonths() const;
	int countYears() const;
};

std::istream &operator >> (std::istream &in, Date &date);
std::ostream &operator << (std::ostream &out, const Date &date);

template<class Archive>
void Date::serialize(Archive &ar, unsigned int version)
{
	//����һ��Ҫ��ס��isLeapҲ�Ž�ȥ����Ȼ���ļ���ȡ��ʱ���ȱ���ⲿ�����ݣ�����isLeap���Ĭ�Ϲ��캯����Ӧ��ݵĶ�Ӧֵ�ġ�
	ar &year &month &day &isLeap;
}