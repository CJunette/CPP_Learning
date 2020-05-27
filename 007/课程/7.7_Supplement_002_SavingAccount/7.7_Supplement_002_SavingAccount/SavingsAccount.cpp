#include "SavingsAccount.h"


SavingsAccount::SavingsAccount(Date const &d, std::string i, double r):
	Account(d, i), acc(d, 0), rate(r)
{
}

double SavingsAccount::getRate() const
{
	return rate;
}

void SavingsAccount::deposit(Date const &d, double a, std::string desc)
{
	record(d, a, desc);
	acc.change(d, getBalance());
}

void SavingsAccount::withdraw(Date const &d, double a, std::string desc)
{
	if(a > getBalance())
	{
		error("Not enough mineral!");
	}
	else
	{
		record(d, -a, desc);
		acc.change(d, getBalance());
	}
}

void SavingsAccount::settle(Date const &d)
{
	Date lastYear(d.getYear() - 1, 1, 1);
	int days = (d.getTotalDays() - lastYear.getTotalDays());
	double interest = acc.getSum(d) / days * rate;
	if(interest != 0)
	{
		record(d, interest, "interest");
	}
	acc.reset(d, getBalance());
}