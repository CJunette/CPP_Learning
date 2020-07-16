#pragma once

#include "Date.h"
#include "Accumulator.h"
#include <iostream>
#include <map>

class Account;

class AccountRecord
{
	public:
	AccountRecord(const Date &date, Account &account, double amount, std::string des);
	void show() const;

	private:
	Date date;
	Account *account;
	double amount, balance;
	std::string desc;
};

class AccountException: public std::runtime_error
{
	private:
	const Account *account;
	public:
	AccountException(const Account *acc, const std::string &str);
	const Account *getAccount() const;
};

typedef std::multimap<Date, AccountRecord> RecordMap;

class Account
{
	public:
	std::string getID() const;
	double getBalance() const;

	virtual void deposit(const Date &date, double amount, std::string desc) = 0;
	virtual void withdraw(const Date &date, double amount, std::string desc) = 0;
	virtual void settle(const Date &date) = 0;
	virtual void show(std::ostream &out) const;

	static double getTotal();

	static void query(const Date &date1, const Date &date2);

	private:
	std::string id;
	double balance;

	static double total;
	static RecordMap recordmap;

	protected:
	Account(const Date &date, std::string id);
	void record(const Date &date, double amount, std::string id);
	void error(std::string msg) const;
};

class SavingsAccount: public Account
{
	public:
	SavingsAccount(const Date &date, std::string id, double rate);
	double getRate() const;
	virtual void deposit(const Date &date, double amount, std::string desc) override;
	virtual void withdraw(const Date &date, double amount, std::string desc) override;
	virtual void settle(const Date &date) override;

	private:
	double rate;
	Accumulator acc;
};

class CreditAccount: public Account
{
	public:
	CreditAccount(const Date &date, std::string id, double credit, double rate, double fee);
	double getCredit() const;
	double getFee() const;
	double getRate() const;
	double getAvailableCredit() const;

	virtual void deposit(const Date &date, double amount, std::string desc) override;
	virtual void withdraw(const Date &date, double amount, std::string desc) override;
	virtual void settle(const Date &date) override;
	virtual void show(std::ostream &out) const override;

	private:
	double credit, rate, fee;
	Accumulator acc;
	double getDebt() const;
};