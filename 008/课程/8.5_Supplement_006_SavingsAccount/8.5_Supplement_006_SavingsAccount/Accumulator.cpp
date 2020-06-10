#include "Accumulator.h"

Accumulator::Accumulator(Date d):
	lastDate(d), value(0), sum(0)
{
}

double Accumulator::getSum(Date d) const
{
	//����дgetSum()����Ϊ����settle()��ʱ�����ٵ���change()��
	return sum + value * (d - lastDate);
}

void Accumulator::change(Date d, double v)
{
	sum = getSum(d);
	lastDate = d;
	value = v;
}

void Accumulator::reset(Date d, double v)
{
	sum = 0;
	value = v;
	lastDate = d;
}