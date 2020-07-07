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
	//������recordmap��������ݵĲ��֡�
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
		//������ʱ����ֺ��ߣ����Ǵ���û�����⡣
		//����lower_bound()����������Ҫ���ء�<=���������ģ�����������p466�����������ʵ����������<���������ģ����Լ�ʹû���صص������ԡ�<=�������أ�ֻҪ�����ˡ�<����û�����⣬<utility>ͷ�ļ���ͨ��һ�麯��ģ�����Щ����������������ء�
		//���⣬�����<utility>�еĺ���ģ�������ƿռ�std::rel_ops�С�
		using namespace std::rel_ops;
		//������ʵ�ϣ����ڵ�һ��д�����ʱ���û�С�#include <utility>����Ҳû�С�using namespace std::rel_ops����������û�б���
		//�����ǲ��������Ѿ������õ�lower_bound���ˡ�
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