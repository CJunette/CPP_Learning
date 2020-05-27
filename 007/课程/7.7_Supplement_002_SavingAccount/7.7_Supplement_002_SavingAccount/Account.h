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
	//��ΪAccountֻ������ʹ�ã������ᴴ��������˰ѹ��캯����Ϊprotected��
	Account(Date const &date, std::string id);
	void record(Date const &date, double amount, std::string desc);
	void error(std::string msg) const;

	std::string id;
	double balance;
};