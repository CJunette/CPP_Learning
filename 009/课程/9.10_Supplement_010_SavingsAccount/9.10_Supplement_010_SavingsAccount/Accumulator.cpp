#include "Accumulator.h"

Accumulator::Accumulator(Date date):
	lastDate(date), accumulation(0), value(0)
{}

double Accumulator::getAccumulation(Date date)
{
	return accumulation + value * (date - lastDate);
}

void Accumulator::change(Date date, double amount)
{
	accumulation = getAccumulation(date);
	value = amount;
	lastDate = date;
}

void Accumulator::reset(Date date, double amount)
{
	accumulation = 0;
	value = amount;
	lastDate = date;
}