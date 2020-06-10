#pragma once
#include <iostream>
#include "Date.h"
#include "Accumulator.h"

class Account
{
	public:
	std::string getID() const;
	double getBalance() const;

	virtual void deposit(Date date, double amount, std::string desc) = 0;
	virtual void withdraw(Date date, double amount, std::string desc) = 0;
	virtual void settle(Date date) = 0;
	virtual void show() const;

	static double getTotal();

	private:
	std::string id;
	double balance;
	static double total;

	protected:
	Account(Date date, std::string id);
	void record(Date date, double amount, std::string desc);
	void error(std::string msg) const;	
};

class SavingsAccount: public Account
{
	public:
	SavingsAccount(Date date, std::string id, double rate);
	double getRate() const;
	virtual void deposit(Date date, double amount, std::string desc) override;
	virtual void withdraw(Date date, double amount, std::string desc) override;
	virtual void settle(Date date) override;

	private:
	double rate;
	Accumulator acc;
};

class CreditAccount: public Account
{
	public:
	CreditAccount(Date date, std::string id, double credit, double rate, double fee);
	double getCredit() const;
	double getRate() const;
	double getFee() const;
	double getAvailableCredit() const;

	virtual void deposit(Date date, double amount, std::string desc) override;
	virtual void withdraw(Date date, double amount, std::string desc) override;
	virtual void settle(Date date) override;
	virtual void show() const override;

	private:
	double rate, fee, credit;
	Accumulator acc;
	double getDebt() const;

};