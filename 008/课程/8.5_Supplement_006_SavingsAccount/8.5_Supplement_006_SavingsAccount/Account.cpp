#include "Account.h"
#include <iostream>

std::string Account::getID() const
{
	return id;
}

double Account::getBalance() const
{
	return balance;
}

void Account::show() const
{
	std::cout << id << "\t Balance: " << balance;
}

double Account::getTotal()
{
	return total;
}

Account::Account(Date d, std::string i):
	id(i), balance(0)
{
	d.show();
	std::cout << "\t#" << id << " created" << std::endl;
}

void Account::record(Date d, double a, std::string desc)
{
	a = (a >= 0) ? (floor(a * 100 + 0.5) / 100) : (ceil(a * 100 - 0.5) / 100);
	balance += a;
	//Don't forget to change "total"!
	total += a;
	d.show();
	std::cout << "\t#" << id << "\t" << a << "\t" << balance << "\t" << desc << std::endl;
}

void Account::error(std::string m) const
{
	std::cout << m << std::endl;
}

double Account::total = 0;

/*-------------------------------------------------------------------*/

SavingsAccount::SavingsAccount(Date d, std::string i, double r):
	Account(d, i), rate(r), acc(d)
{		
}

double SavingsAccount::getRate() const
{
	return rate;	
}

void SavingsAccount::deposit(Date d, double a, std::string desc)
{
	record(d, a, desc);
	acc.change(d, getBalance());
}

void SavingsAccount::withdraw(Date d, double a, std::string desc)
{
	if(a > getBalance())
	{
		std::cout << "Not enougn mineral! Withdraw failed..." << std::endl;
	}
	else
	{
		record(d, -a, desc);
		acc.change(d, getBalance());
	}
}

void SavingsAccount::settle(Date d)
{
	if(d.getMonth() == 1)
	{
		int days = (Date(d.getYear() - 1, 1, 1).isLeap) ? 366 : 365;
		double interest = acc.getSum(d) / days * rate;
		record(d, interest, "interest");
		acc.reset(d, getBalance());
	}
	else
	{
		std::cout << "SavingsAccount's settle only happens in January." << std::endl;
	}
}

/*-------------------------------------------------------------------*/

CreditAccount::CreditAccount(Date d, std::string i, double c, double r, double f):
	Account(d, i), credit(c), rate(r), fee(f), acc(d)
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

double CreditAccount::getAvailableCredit() const
{
	if(getBalance() < 0)
	{
		return credit + getBalance();
	}
	else
	{
		return getCredit();
	}
}

void CreditAccount::deposit(Date d, double a, std::string desc)
{
	record(d, a, desc);
	//注意，因为信用卡不计储息只计债息，因此这里要讲getDebt()传入。
	acc.change(d, getDebt());
}

void CreditAccount::withdraw(Date d, double a, std::string desc)
{
	if(a > credit + getBalance())
	{
		std::cout << "Not enougn mineral! Withdraw failed..." << std::endl;
	}
	else
	{
		record(d, -a, desc);
		//注意，因为信用卡不计储息只计债息，因此这里要讲getDebt()传入。
		acc.change(d, getDebt());
	}
}

void CreditAccount::settle(Date d)
{
	if(d.getDay() == 1)
	{
		double interest = acc.getSum(d) * rate;
		if(interest != 0)
		{
			record(d, interest, "interest");
		}
		if(d.getMonth() == 1)
		{
			record(d, -fee, "annual fee");
		}
		acc.reset(d, getDebt());
	}
	else
	{
		std::cout << "CreditAccount's settle only happens in the first day of each month." << std::endl;
	}
}

void CreditAccount::show() const
{
	std::cout << getID() << "\t Balance: " << getBalance() << "\t Available Credit: " << getAvailableCredit();
}

double CreditAccount::getDebt() const
{
	if(getBalance() < 0)
	{
		return getBalance();
	}
	else
	{
		return 0;
	}
}