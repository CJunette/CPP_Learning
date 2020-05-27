#include "Accumulator.h"

Accumulator::Accumulator(Date const &d, double v):
	lastDate(d), value(v)
{
	sum = 0;
}


double Accumulator::getSum(Date const &d) const
{
	int days = (d.getTotalDays() - lastDate.getTotalDays());
	return sum + value * days;
}

void Accumulator::change(Date const &d, double v)
{
	sum = getSum(d);
	value = v;
	lastDate = d;
}

void Accumulator::reset(Date const &d, double v)
{
	sum = 0;
	value = v;
	lastDate = d;
}