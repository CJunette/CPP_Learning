#include "Account.h"
#include <iostream>

double Account::total = 0;

Account::Account(Date const &d, std::string i):
	id(i), balance(0)
{
	d.show();
	std::cout << "#" << id << " \t created" << std::endl;
}

void Account::record(Date const &d, double a, std::string desc)
{
	//修改accumulator
	//修改lastDate
	//以上功能在Accumulator类中完成。

	//小数点两位精确
	a = a >= 0 ? floor(a * 100 + 0.5) / 100 : ceil(a * 100 - 0.5) / 100;
	//修改balance
	balance += a;
	//修改total
	total += a;
	//输出
	d.show();
	std::cout << "\t" << "#" << id << "\t" << a << "\t" << balance << "\t" << desc << std::endl;
}

void Account::error(std::string msg) const
{
	std::cout << msg << std::endl;
}

int Account::getID() const
{
	return atoi(id.c_str());
}

double Account::getBalance() const
{
	return balance;
}

double Account::getTotal()
{
	return total;
}

void Account::show() const
{
	std::cout << "#" << id << "\t Balance: " << balance << std::endl;
}