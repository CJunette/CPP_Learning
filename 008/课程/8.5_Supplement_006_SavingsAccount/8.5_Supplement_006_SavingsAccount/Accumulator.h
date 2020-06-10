#pragma once
#include "Date.h"

class Accumulator
{
	public:
	//这里Accumulator的构造函数我稍微修改了一下，将第二个参数value去掉了。
	//因为即使有那个参数，构造的时候也都是输入0的，还不如直接去掉。
	Accumulator(Date date);
	double getSum(Date date) const;
	void change(Date date, double value);
	void reset(Date date, double value);

	private:
	Date lastDate;
	//这里不用value也是可以的。只是那样的话，所有的change()必须在balance发生改变前执行。
	//另外，在settle()时，必须先执行change()再执行getSum()。
	//如果按现在的做法，就会简单一些，计息时只要执行getSum()即可。
	double value;
	double sum;
};