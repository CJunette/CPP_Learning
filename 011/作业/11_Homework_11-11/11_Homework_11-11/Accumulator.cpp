#include "Accumulator.h"

Accumulator::Accumulator(const Date &date):
	lastDate(date), accumulation(0), value(0)
{}

double Accumulator::getAccumulation(const Date &date)
{
	return accumulation + value * (date - lastDate);
}

void Accumulator::change(const Date &date, double amount)
{
	accumulation = getAccumulation(date);
	lastDate = date;
	value = amount;
}

void Accumulator::reset(const Date &date, double amount)
{
	lastDate = date;
	accumulation = 0;
	value = amount;
}