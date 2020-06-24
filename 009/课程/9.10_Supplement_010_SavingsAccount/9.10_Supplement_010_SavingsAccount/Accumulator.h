#pragma once

#include "Date.h"

class Accumulator
{
	public:
	Accumulator(Date date);
	double getAccumulation(Date date);
	void change(Date date, double amount);
	void reset(Date date, double amount);

	private:
	double accumulation, value;
	Date lastDate;
};