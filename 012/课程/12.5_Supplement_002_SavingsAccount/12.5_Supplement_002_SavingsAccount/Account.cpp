#include "Account.h"
#include <algorithm>
#include <functional>
using namespace std;

AccountRecord::AccountRecord(const Date &d, Account &acc, double a, std::string des):
	date(d), account(&acc), amount(a), balance(acc.getBalance()), desc(des)
{}

void AccountRecord::show() const
{
	cout << date << "\t#" << account->getID() << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

/*----------------------------------------------------------------*/

AccountException::AccountException(const Account *acc, const string &str):
	runtime_error(str), account(acc)
{}

const Account *AccountException::getAccount() const
{
	return account;
}

/*----------------------------------------------------------------*/

string Account::getID() const
{
	return id;
}

double Account::getBalance() const
{
	return balance;
}

void Account::show(ostream &out) const
{
	out << id << "\t Balance: " << balance;
}

double Account::getTotal()
{
	return total;
}

void Account::query(const Date &date1, const Date &date2)
{
	if(date1 < date2)
	{
		typename RecordMap::iterator begin, end;
		begin = recordmap.lower_bound(date1);
		end = recordmap.upper_bound(date2);
		//这里似乎没法用for_each，因为for_each接受的是一元函数对象，而由于show(ostream &out)作为成员函数，既有自身作为参数，又有输出流对象作为参数。
		//这里也许会考虑使用bind2nd将第二个参数绑定，但由于第二个参数是输出流对象，在输出时会时刻发生改变，不为常对象，因此无法绑定。
		for(; begin != end; begin++)
		{
			begin->second.show();
		}
		cout << endl;
	}
	else
	{
		cout << "Begin date could not be after end date!" << endl;
	}
}

double Account::total = 0;
RecordMap Account::recordmap;

Account::Account(const Date &d, string i):
	id(i), balance(0)
{
	cout << d << "\t#" << id << " created" << endl;
}

void Account::record(const Date &date, double amount, string desc)
{
	amount = (amount > 0) ? floor(amount * 100 + 0.5) / 100 : ceil(amount * 100 - 0.5) / 100;
	balance += amount;
	total += amount;
	cout << date << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
	recordmap.insert(make_pair(date, AccountRecord(date, *this, amount, desc)));
}

void Account::error(string msg) const
{
	throw AccountException(this, msg);
}

/*----------------------------------------------------------------*/

SavingsAccount::SavingsAccount(const Date &d, string i, double r):
	Account(d, i), rate(r), acc(d)
{}

double SavingsAccount::getRate() const
{
	return rate;
}

void SavingsAccount::deposit(const Date &date, double amount, std::string desc)
{
	if(amount < 0)
	{
		error("You can't deposit minus money!");		
	}
	else
	{
		record(date, amount, desc);
		acc.change(date, getBalance());
	}
}

void SavingsAccount::withdraw(const Date &date, double amount, string desc)
{
	if(amount > getBalance())
	{
		error("Not enough minerals!");
	}
	else
	{
		if(amount < 0)
		{
			error("You can't withdraw minus money!");
		}
		else
		{
			record(date, -amount, desc);
			acc.change(date, getBalance());
		}
	}
}

void SavingsAccount::settle(const Date &date)
{
	if(date.getMonth() == 1)
	{
		double accumulation = acc.getAccumulation(date);
		int days = Date(date.getYear() - 1, 1, 1).isLeap ? 366 : 365;
		double interest = accumulation * rate / days;
		record(date, interest, "Interest");
		acc.reset(date, getBalance());
	}
}

/*----------------------------------------------------------------*/

CreditAccount::CreditAccount(const Date &d, string i, double c, double r, double f):
	Account(d, i), credit(c), rate(r), fee(f), acc(d)
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
	if(credit + getBalance() <= 0)
	{
		return 0;
	}
	else
	{
		return credit + getBalance();
	}
}

void CreditAccount::deposit(const Date &date, double amount, string desc)
{
	if(amount < 0)
	{
		error("You can't deposit minus money!");
	}
	else
	{
		record(date, amount, desc);
		acc.change(date, getDebt());
	}
}

void CreditAccount::withdraw(const Date &date, double amount, string desc)
{
	if(getAvailableCredit() <= 0)
	{
		error("Not enough minerals!");
	}
	else
	{
		record(date, -amount, desc);
		acc.change(date, getDebt());
	}
}

void CreditAccount::settle(const Date &date)
{
	if(date.getDay() == 1)
	{
		if(date.getMonth() == 1)
		{
			record(date, -fee, "Annual fee");
		}
		double accumulation = acc.getAccumulation(date);
		double interest = accumulation * rate;
		if(interest < 0)
		{
			record(date, interest, "Interest");
		}
		acc.reset(date, getDebt());
	}
}

void CreditAccount::show(ostream &out) const
{
	out << getID() << "\t Balance: " << getBalance() << "\t Available Credit: " << getAvailableCredit() << endl;
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