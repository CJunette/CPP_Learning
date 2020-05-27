#pragma once

#include "Account.h"
#include "Accumulator.h"
#include <iostream>

class CreditAccount: public Account
{
	public:
	CreditAccount(Date const &date, std::string id, double credit, double rate, double fee);
	
	double getCredit() const;
	double getRate() const;
	double getFee() const;
	
	double getAvailableCredit() const;
	//这里除了账户名和余额外，还希望输出信用卡可用额度，因此重写了show()函数。
	void show() const;

	void deposit(Date const &date, double amount, std::string desc);
	void withdraw(Date const &date, double amount, std::string desc);
	void settle(Date const &date);

	private:
	double credit, rate, fee;
	//这里的acc和SavingsAccount中的acc是不是都可以写进基类里？
	Accumulator acc;

	double getDebt() const;

	protected:

};