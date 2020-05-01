#pragma once
#include "account.h"
#include <cmath>
using namespace std;

double SavingAccount::total = 0;

const double SavingAccount::accumulate(int d)
{
	return accumulation + balance * (d - lastDate);
}

void SavingAccount::record(int d, double a)
{
	accumulation = accumulate(d);
	a = (a > 0) ? floor((a * 100 + 0.5)) / 100 : ceil((a * 100 - 0.5)) / 100;
	lastDate = d;
	balance += a;
	cout << "Date: " << d << " \tID: " << id << " \tAmount: " << a << " \tBalance: " << balance << endl;
	total += a;
}


SavingAccount::SavingAccount(int d, int i, double r):
	lastDate(d), id(i), rate(r)
{
	balance = 0;
	accumulation = 0;
}

void SavingAccount::deposit(int d, double a)
{
	record(d, a);
}

void SavingAccount::withdraw(int d, double a)
{
	if (balance >= a)
	{
		record(d, -a);
	}
	else
	{
		cout << "Your account does't have so much money!\n";
	}
}

void SavingAccount::settle(int d)
{
	accumulation = accumulate(d);
	double interest = accumulation * rate / 365;
	//这里重复记accumulation并没有影响（record里也会又一次accumulate()），因为下面马上就把accumulation给归零了。
	record(d, interest);
	accumulation = 0;	
}

double SavingAccount::getTotal()
{
	return total;
}

const int SavingAccount::getId()
{
	return id;
}

const double SavingAccount::getBalance()
{
	return balance;
}

const double SavingAccount::getRate()
{
	return rate;
}

const void SavingAccount::show()
{
	cout << "ID: " << id << " \tBalance: " << balance << endl;
}