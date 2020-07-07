#pragma once

#include <iostream>
#include <map>
#include "Date.h"
#include "Accumulator.h"
using namespace std;

class Account;

class AccountRecord
{
	public:
	AccountRecord(Date d, Account *a, double am, double b, string des);		
	void show();

	private:
	Date date;
	Account *account;
	double amount, balance;
	string desc;
};

typedef multimap<Date, AccountRecord> RecordMap;

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

	static void query(const Date &date1, const Date &date2);

	private:
	std::string id;
	double balance;
	static double total;

	//�����recordmap�У��ڶ���AccountRecordҲ��һ������Date�����һ���Date���ظ��ġ�
	//֮���Զ����������ظ��ṹ����Ϊ����ֱ���ڵڶ����ж���������������á����������ʱ�ô�����ڸ��ӡ�
	static RecordMap recordmap;

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
	double getFee() const;
	double getRate() const;
	double getAvailableCredit() const;

	virtual void deposit(Date date, double amount, std::string desc) override;
	virtual void withdraw(Date date, double amount, std::string desc) override;
	virtual void settle(Date date) override;
	virtual void show() const override;

	private:
	double rate, credit, fee;
	Accumulator acc;
	double getDebt() const;
};