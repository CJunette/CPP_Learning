#pragma once

#include "Account.h"
#include "Accumulator.h"
#include <iostream>

class CreditAccount: public Account
{
	public:
	CreditAccount(Date const &date, std::string id, double credit, double rate, double fee);
	
	double getCredit() const;
	double getRate() const;
	double getFee() const;
	
	double getAvailableCredit() const;
	//��������˻���������⣬��ϣ��������ÿ����ö�ȣ������д��show()������
	void show() const;

	void deposit(Date const &date, double amount, std::string desc);
	void withdraw(Date const &date, double amount, std::string desc);
	void settle(Date const &date);

	private:
	double credit, rate, fee;
	//�����acc��SavingsAccount�е�acc�ǲ��Ƕ�����д�������
	Accumulator acc;

	double getDebt() const;

	protected:

};