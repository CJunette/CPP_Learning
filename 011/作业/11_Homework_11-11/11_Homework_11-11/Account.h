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
	//���������Serialization��������ʱ����Ҫ����Ĭ�϶�������Account���������˶���Ҫ��Ĭ�Ϲ��캯����
	Account(const Date &date = Date(1, 1, 1), std::string id = "default account");
	void record(const Date &date, double amount, std::string id);
	void error(std::string msg) const;
};

template<class Archive>
void Account::serialize(Archive &ar, unsigned int version)
{
	//����û���Ѷ���ӳ��accountrecordҲ�Ž�������Ϊִ��serialization��Ҫ����AccountRecord��Ĭ�Ϻ�������AccountRecord��Ĺ��캯���Ĳ�������һ�������Account��ָ������������޷�������������޷�ָ��Ĭ��ֵ��ָ��ΪNULL�ᵼ�µ���ʱ��ʧ�ܣ���
	//�����뵽�Ľ������Ӧ���ǽ�AccountRecord���Ĭ�Ϲ��캯�������޸ģ�ȥ�����е�Account*���ڹ�����ɺ�ͨ�����һ����Ա�����ֶ���ΪAccount*������ݳ�Ա��ֵ��
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
	//���ǳ���Ҫ�����ƺ�������ȷ�����л�ʱ�ļ̳й�ϵ�ġ�
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
	//�ٴ�ǿ�������ǳ���Ҫ����
	ar &boost::serialization::base_object<Account>(*this);
	ar &credit &rate &fee &acc;
}

