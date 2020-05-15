#pragma once
#include "SavingsAccount.h"

double SavingsAccount::accumulate(const Date &d) const
{
	return accumulation + balance * (d.getTotalDays() - lastDate.getTotalDays());
}

void SavingsAccount::record(const Date &d, double a,const string &desc)
{
	accumulation = accumulate(d);
	lastDate = d;
	a = a >= 0 ? (floor(a * 100 + 0.5) / 100) : (ceil(a * 100 - 0.5) / 100);
	balance += a;
	total += a;
	d.show();
	cout << "#" << id << "\t" << a << "\t" << desc << endl;
}

void SavingsAccount::deposit(const Date &d, double a, const string &desc)
{	
	record(d, a, desc);
}

void SavingsAccount::withdraw(const Date &d, double a, const string &desc)
{
	if (a > balance)
	{
		error("Not enough minerals.");
	}
	else
	{
		record(d, -a, desc);
	}
}

void SavingsAccount::error(const string &msg) const
{
	cout << "Error: " + msg << endl;
}

void SavingsAccount::settle(const Date &d)
{
	accumulation = accumulate(d);
	//本年计息算的是上一年的总天数。
	Date lastyear(d.getYears() - 1, 1, 1);
	int days = lastyear.isLeap ? 366 : 365;
	double interest = accumulation / days * rate;
	accumulation = 0;
	lastDate = d;
	record(d, interest, "Settle");
}

string SavingsAccount::getID() const
{
	return id;
}

double SavingsAccount::getRate() const
{
	return rate;
}

double SavingsAccount::getBalance() const
{
	return balance;
}

void SavingsAccount::show() const
{
	cout << "ID: " << id << "\tBalance: " << balance << endl;
}

double SavingsAccount::getTotal()
{
	return total;
}

double SavingsAccount::total = 0;