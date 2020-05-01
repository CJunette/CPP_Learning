#pragma once
#include <iostream>

class SavingAccount
{
	public:
	//��ʼ����������balance = 0�� accumulation = 0��
	SavingAccount(int date, int id, double rate);
	//����id��
	const int getId();
	//���ش�
	const double getBalance();
	//�������ʡ�
	const double getRate();
	//��ʾ�˻���Ϣ��
	const void show();
	//��������
	void deposit(int date, double amount);
	//ȡ�������
	void withdraw(int date, double amoumt);
	//��Ϣ������
	void settle(int date);
	//��ѯ�����ܴ�
	static double getTotal();

	private:
	int id, lastDate;
	double balance, rate, accumulation;
	//�����ܴ�
	static double total;
	//�����ʼ�¼��
	void record(int date, double amount);
	//���������档
	const double accumulate(int date);	
};