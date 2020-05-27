#include "CreditAccount.h"

namespace
{
	const int daysForMonth[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
}

CreditAccount::CreditAccount(Date const &d, std::string i, double c, double r, double f):
	Account(d, i), credit(c), rate(r), fee(f), acc(d, 0)
{
}


double CreditAccount::getCredit() const
{
	return credit;
}

double CreditAccount::getRate() const
{
	return rate;
}

double CreditAccount::getFee() const
{
	return fee;
}

double CreditAccount::getDebt() const
{
	double balance = getBalance();
	return (balance < 0) ? balance : 0;
}

double CreditAccount::getAvailableCredit() const
{
	double balance = getBalance();
	return (balance < 0) ? balance + credit : credit;
}

void CreditAccount::deposit(Date const &d, double a, std::string desc)
{
	record(d, a, desc);
	acc.change(d, getBalance());
}

void CreditAccount::withdraw(Date const &d, double a, std::string desc)
{
	if(a - getBalance() > credit)
	{
		error("Not enough credit!");
	}
	else
	{
		record(d, -a, desc);
		acc.change(d, getBalance());
	}
}

void CreditAccount::settle(Date const &d)
{
	//信用卡用日利率，因此不需要下面这些计算上月天数的代码。
	/*
	int lastMonthDays;
	if(d.getMonth() == 1)
	{
		lastMonthDays = 12;
	}
	else
	{
		lastMonthDays = daysForMonth[d.getMonth() - 1] - daysForMonth[d.getMonth() - 2];
	}
	*/
	double interest = acc.getSum(d) * rate;
	if(interest < 0)
	{
		record(d, interest, "interest");
	}
	if(d.getMonth() == 1)
	{
		record(d, -fee, "annual fee");
	}
	acc.reset(d, getBalance());
}

void CreditAccount::show() const
{
	
	std::cout << "#" << id << "\t Balance: " << balance << "\t Available Credit: " << getAvailableCredit() << std::endl;	
}