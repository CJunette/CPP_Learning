#pragma once

#include "Date.h"

class Accumulator
{
	public:
	Accumulator(const Date &date);
	double getAccumulation(const Date &date);
	void change(const Date &date, double amount);
	void reset(const Date &date, double amount);

	private:
	Date lastDate;
	double accumulation, value;
};