#pragma once
#include "Date.h"
#include <iostream>
using namespace std;

class SavingsAccount
{
	public:
	//涉及Date的用const引用。
	SavingsAccount(const Date &d, string i, double r):
		lastDate(d), id(i), rate(r), balance(0), accumulation(0)
	{
		lastDate.show();
		cout << "#" << id << " created" << endl;
	}

	//涉及string的用const引用的形式。
	void deposit(const Date &date, double amount, const string &desc);
	void withdraw(const Date &date, double amount, const string &desc);
	void settle(const Date &date);
	string getID() const;
	double getRate() const;
	double getBalance() const;
	void show() const;

	static double getTotal();

	private:
	Date lastDate;
	double rate, accumulation, balance;
	string id;	

	void record(const Date &date, double amount,const string &desc);	
	double accumulate(const Date &date) const;
	void error(const string &msg) const;

	static double total;
};