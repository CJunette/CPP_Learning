#include "Account.h"
using namespace std;

string Account::getID() const
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

double Account::total = 0;

Account::Account(Date d, string i):
	id(i), balance(0)
{
	d.show();
	cout << "\t#" << id << " created" << endl;
}

void Account::record(Date d, double amount, string desc)
{
	double a = (amount >= 0) ? floor(amount * 100 + 0.5) / 100 : ceil(amount * 100 - 0.5) / 100;
	balance += a;
	//自己写的时候又忘了total了！！！
	total += a;
	d.show();
	cout << "\t#" << id << "\t" << a << "\t" << balance << "\t" << desc << endl;
}

void Account::error(string msg) const
{
	cout << msg << endl;
}


SavingsAccount::SavingsAccount(Date d, string i, double r):
	Account(d, i), rate(r), acc(d)
{};

double SavingsAccount::getRate() const
{
	return rate;
}

void SavingsAccount::deposit(Date d, double a, string desc)
{
	if(a < 0)
	{
		cout << "You can't deposit minus money." << endl;
		return;
	}
	record(d, a, desc);
	acc.change(d, getBalance());
}

void SavingsAccount::withdraw(Date d, double a, string desc)
{
	if(a > getBalance())
	{
		cout << "Not enough mineral." << endl;
		return;
	}
	record(d, -a, desc);
	acc.change(d, getBalance());
}

void SavingsAccount::settle(Date d)
{
	if(d.getMonth()!= 1)
	{		
		return;
	};
	double accumulation = acc.getAccumulation(d);
	int days = Date(d.getYear() - 1, d.getMonth(), d.getDay()).isLeap ? 366 : 365;
	double interest = accumulation * rate / days;
	record(d, interest, "interest");
	acc.reset(d, getBalance());
}


CreditAccount::CreditAccount(Date d, string i, double c, double r, double f):
	Account(d, i), acc(d), rate(r), credit(c), fee(f)
{}

double CreditAccount::getCredit() const
{
	return credit;
}

double CreditAccount::getFee() const
{
	return fee;
}

double CreditAccount::getRate() const
{
	return rate;
}

double CreditAccount::getAvailableCredit() const
{
	return credit + getBalance();
}

void CreditAccount::deposit(Date d, double a, string desc)
{
	if(a < 0)
	{
		cout << "You can't deposit minus money." << endl;
		return;
	}
	record(d, a, desc);
	acc.change(d, getDebt());
}

void CreditAccount::withdraw(Date d, double a, string desc)
{
	if(a > getAvailableCredit())
	{
		cout << "Not enough mineral." << endl;
		return;
	}
	record(d, -a, desc);
	acc.change(d, getDebt());
}

void CreditAccount::settle(Date d)
{
	if(d.getDay() != 1)
	{
		cout << "Settles for credit accounts only happen on the first day of each month." << endl;
		return;
	}
	if(d.getMonth() == 1)
	{
		record(d, -fee, "annual fee");		
	}
	double accumulation = acc.getAccumulation(d);
	double interest = accumulation * rate;
	if(interest < 0)
	{
		record(d, interest, "interest");
	}
	acc.reset(d, getDebt());
}

void CreditAccount::show() const
{
	cout << getID() << "\t Balance: " << getBalance() << "\t Available Credit: " << getAvailableCredit() << endl;
}

double CreditAccount::getDebt() const
{
	if(getBalance() >= 0)
	{
		return 0;
	}
	else
	{
		return getBalance();
	}
}