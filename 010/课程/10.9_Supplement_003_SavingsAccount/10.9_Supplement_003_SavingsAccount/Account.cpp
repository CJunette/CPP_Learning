#include "Account.h"
#include <algorithm>
#include <utility>
using namespace std;

AccountRecord::AccountRecord(Date d, Account *a, double am, double b, string des):
date(d), account(a), amount(am), balance(b), desc(des)
{}

void AccountRecord::show()
{
	date.show();
	cout << "\t#" << account->getID() << "\t" << amount << "\t" << balance << "\t" << desc << endl;
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

void Account::show() const
{
	std::cout << id << "\t Balance: " << balance;
}

double Account::getTotal()
{
	return total;
}

double Account::total = 0;
RecordMap Account::recordmap;

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
	total += a;
	d.show();
	cout << "\t#" << id << "\t" << a << "\t" << balance << "\t" << desc << endl;
	//新增向recordmap中添加数据的部分。
	recordmap.insert(make_pair(d, AccountRecord(d, this, amount, this->getBalance(), desc)));
}

void Account::error(string msg) const
{
	cout << msg << endl;
}

void Account::query(const Date &begin, const Date &end)
{
	if(begin < end)
	{
		//这里有时会出现红线，但是代码没有问题。
		//这里lower_bound()按道理是需要重载“<=”操作符的，但根据书上p466，这个操作符实际是依赖“<”操作符的，所以即使没有特地的声明对“<=”的重载，只要重载了“<”就没有问题，<utility>头文件会通过一组函数模板对那些运算符进行自行重载。
		//另外，这里的<utility>中的函数模板在名称空间std::rel_ops中。
		using namespace std::rel_ops;
		//不过事实上，我在第一次写代码的时候既没有“#include <utility>”，也没有“using namespace std::rel_ops”，但程序并没有报错。
		//可能那部分引用已经被内置到lower_bound中了。
		typename RecordMap::iterator iter1 = recordmap.lower_bound(begin);
		typename RecordMap::iterator iter2 = recordmap.upper_bound(end);
		for(typename RecordMap::iterator iter = iter1; iter != iter2; iter++)
		{
			iter->second.show();
		}
		cout << endl;
	}	
	else
	{
		cout << "Begin date could not be after end date!" << endl;
	}
}

/*----------------------------------------------------------------*/

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
	if(d.getMonth() != 1)
	{
		return;
	};
	double accumulation = acc.getAccumulation(d);
	int days = Date(d.getYear() - 1, d.getMonth(), d.getDay()).isLeap ? 366 : 365;
	double interest = accumulation * rate / days;
	record(d, interest, "interest");
	acc.reset(d, getBalance());
}

/*----------------------------------------------------------------*/

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