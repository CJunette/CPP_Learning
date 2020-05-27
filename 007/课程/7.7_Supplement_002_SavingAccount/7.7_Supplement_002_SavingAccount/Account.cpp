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
	//�޸�accumulator
	//�޸�lastDate
	//���Ϲ�����Accumulator������ɡ�

	//С������λ��ȷ
	a = a >= 0 ? floor(a * 100 + 0.5) / 100 : ceil(a * 100 - 0.5) / 100;
	//�޸�balance
	balance += a;
	//�޸�total
	total += a;
	//���
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