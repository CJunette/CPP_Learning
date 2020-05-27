#pragma once
#include <iostream>
#include "Date.h"

class Account
{
	public:
	int getID() const;
	double getBalance() const;
	static double getTotal();
	void show() const;

	private:
	static double total;

	protected:
	//因为Account只做基类使用，自身不会创建对象，因此把构造函数设为protected。
	Account(Date const &date, std::string id);
	void record(Date const &date, double amount, std::string desc);
	void error(std::string msg) const;

	std::string id;
	double balance;
};