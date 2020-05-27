#pragma once
#include "Account.h"
#include "Accumulator.h"
#include <iostream>

class SavingsAccount: public Account
{
	public:
	SavingsAccount(Date const &date, std::string id, double rate);
	double getRate() const;
	void deposit(Date const &date, double amount, std::string desc);
	void withdraw(Date const &date, double amount, std::string desc);
	void settle(Date const &date);

	private:
	//�����acc��CreditAccount�е�acc�ǲ��Ƕ�����д�������
	Accumulator acc;
	double rate;

	protected:

};