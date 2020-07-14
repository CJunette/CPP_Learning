#pragma once

#include "Date.h"
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

class Accumulator
{
	public:
	Accumulator(const Date &date);
	double getAccumulation(const Date &date);
	void change(const Date &date, double amount);
	void reset(const Date &date, double amount);

	template<class Archive>
	void serialize(Archive &ar, unsigned int version);

	private:
	Date lastDate;
	double accumulation, value;
};

template<class Archive>
void Accumulator::serialize(Archive &ar, unsigned int version)
{
	ar &lastDate &accumulation &value;
}