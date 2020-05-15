#pragma once
class Date
{
	public:
	//初始化需要完成的工作：
	//1.初始化年月日。并确定年月日是否为合法的年月日。
	//2.确定是否为闰年。
	//3.计算totalDays。
	Date(int y = 0, int m = 0, int d = 0);		

	void show() const;

	//getTotalDays()需要完成的工作：
	//1.计算当前年到1/1/1的年份差，要注意根据闰年数调整数量。
	//2.计算当前月份到当年1/1的月份差，注意要根据闰年调整2月天数。
	//3.计算当前日到当月1日的日差。
	int getTotalDays() const;

	bool isLeap;
	//getYears()需要完成的工作：
	//1.计算365*(year-1)。
	//2.加上所有除以4余0的年数。
	//3.减去所有除以100余0的年数。
	//4.加上所有除以400余0的年数。
	int getYears() const;

	private:
	int day, month, year;
	int mutable totalDays;

	//isLeapYear()需要完成的工作：
	//1.计算当前年是否逢4。
	//2.计算当前年是否逢100。
	//3.计算当前年逢100的情况下是否逢400。
	bool isLeapYear() const;
	
	//getMonths()需要完成的工作：
	//1.确定当前年份是否是闰年。
	//2.用数组保存当前月份总日数表，根据闰年与否确定是否加一。
	int getMonths() const;
	//getDays()需要完成的工作：
	//1.返回当月1日到当前日的日数。
	int getDays() const;
};