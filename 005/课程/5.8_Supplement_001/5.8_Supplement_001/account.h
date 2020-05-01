#pragma once
#include <iostream>

class SavingAccount
{
	public:
	//初始化各参数，balance = 0， accumulation = 0。
	SavingAccount(int date, int id, double rate);
	//返回id。
	const int getId();
	//返回存款。
	const double getBalance();
	//返回利率。
	const double getRate();
	//显示账户信息。
	const void show();
	//存款操作。
	void deposit(int date, double amount);
	//取款操作。
	void withdraw(int date, double amoumt);
	//计息操作。
	void settle(int date);
	//查询银行总存款。
	static double getTotal();

	private:
	int id, lastDate;
	double balance, rate, accumulation;
	//银行总存款。
	static double total;
	//做单笔记录。
	void record(int date, double amount);
	//记期内收益。
	const double accumulate(int date);	
};