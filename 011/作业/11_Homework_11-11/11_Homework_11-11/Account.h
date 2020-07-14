#pragma once

#include "Date.h"
#include "Accumulator.h"
#include <iostream>
#include <map>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/export.hpp>

class Account;

class AccountRecord
{
	public:
	AccountRecord(const Date &date, Account *account , double amount, std::string des);
	void show() const;
	
	template<class Archive>
	void serialize(Archive &ar, unsigned int version);
	
	private:
	Date date;
	Account *account;
	double amount, balance;
	std::string desc;
};

template<class Archive>
void AccountRecord::serialize(Archive &ar, unsigned int version)
{
	ar &date &account &amount &balance &desc;
}

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

	template<class Archive>
	void serialize(Archive &ar, unsigned int version);

	private:
	std::string id;
	double balance;

	static double total;
	static RecordMap recordmap;
	
	protected:
	//这边由于用Serialization进行输入时，需要创建默认对象，所以Account和其派生了都需要有默认构造函数。
	Account(const Date &date = Date(1, 1, 1), std::string id = "default account");
	void record(const Date &date, double amount, std::string id);
	void error(std::string msg) const;
};

template<class Archive>
void Account::serialize(Archive &ar, unsigned int version)
{
	//这里没法把多重映射accountrecord也放进来，因为执行serialization需要构造AccountRecord的默认函数，而AccountRecord类的构造函数的参数中有一个虚基类Account的指针由于虚基类无法创建对象，因而无法指定默认值（指定为NULL会导致导入时候失败）。
	//我能想到的解决方法应该是将AccountRecord类的默认构造函数进行修改，去掉其中的Account*；在构造完成后，通过添加一个成员函数手动地为Account*这个数据成员赋值。
	ar &id &balance &total;
}


class SavingsAccount: public Account
{
	public:
	SavingsAccount(const Date &date = Date(1, 1, 1), std::string id = "default saving", double rate = 0.015);
	double getRate() const;
	virtual void deposit(const Date &date, double amount, std::string desc) override;
	virtual void withdraw(const Date &date, double amount, std::string desc) override;
	virtual void settle(const Date &date) override;
	
	template<class Archive>
	void serialize(Archive &ar, unsigned int version);
	
	private:
	double rate;
	Accumulator acc;
};

template<class Archive>
void SavingsAccount::serialize(Archive &ar, unsigned int version)
{
	//这句非常重要！！似乎是用来确定串行化时的继承关系的。
	ar &boost::serialization::base_object<Account>(*this);
	ar &rate &acc;
}


class CreditAccount: public Account
{
	public:
	CreditAccount(const Date &date = Date(1, 1, 1), std::string id = "default credit", double credit = 10000, double rate = 0.0005, double fee = 50);
	double getCredit() const;
	double getFee() const;
	double getRate() const;
	double getAvailableCredit() const;

	virtual void deposit(const Date &date, double amount, std::string desc) override;
	virtual void withdraw(const Date &date, double amount, std::string desc) override;
	virtual void settle(const Date &date) override;
	virtual void show(std::ostream &out) const override;
	
	template<class Archive>
	void serialize(Archive &ar, unsigned int version);
	
	private:
	double credit, rate, fee;
	Accumulator acc;
	double getDebt() const;
};

template<class Archive>
void CreditAccount::serialize(Archive &ar, unsigned int version)
{
	//再次强调！！非常重要！！
	ar &boost::serialization::base_object<Account>(*this);
	ar &credit &rate &fee &acc;
}

