#pragma once
#include "Date.h"

class Accumulator
{
	public:
	Accumulator(Date const &date, double value);
	double getSum(Date const &date) const;
	void change(Date const &date, double value);
	void reset(Date const &date, double value);

	private:
	Date lastDate;
	double value, sum;

	protected:

};