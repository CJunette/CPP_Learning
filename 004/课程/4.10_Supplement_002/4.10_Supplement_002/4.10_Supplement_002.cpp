// 4.10_Supplement_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

class SavingAccount
{
    private:
    double balance, accumulation, rate;
    int id, lastDate;
    void record(double amount, int date)
    {
        accumulation += accumulate(date);
        //保留两位小数。
        amount = (amount >= 0) ? floor(amount * 100 + 0.5) / 100 : ceil(amount * 100 - 0.5) / 100;
        balance += amount;
        lastDate = date;
        cout << "Date: " << date << "\t, id: " << id << "\t, amount:" << amount << "\t, balance: " << balance << endl;
    }
    const double accumulate(int date)
    {
        return accumulation + balance * (date - lastDate);
    }

    public:
    SavingAccount(int i, int date, double r);
    double getRate() { return rate; }
    double getBalance() { return balance; }
    //这里我本来想写“void settle(int date, double newrate = rate);”这样的形式，因为结息很有可能是因为有利率调整所以才需要进行。
    //但似乎类成员不能成为类函数成员的默认参数。只有静态成员可以作为类函数成员的默认参数。
    void settle(int date);
    void deposit(int date, double amount);
    void withdraw(int date, double amount);
    void show();
};

SavingAccount::SavingAccount(int date, int i, double r) :
    id(i), lastDate(date), rate(r)
{
    balance = 0;
    accumulation = 0;
}

void SavingAccount::settle(int date)
{
    double interest = accumulate(date) * rate / 365;    
    record(interest, date);
    accumulation = 0;
}

void SavingAccount::deposit(int date, double amount)
{
    record(amount, date);
}

void SavingAccount::withdraw(int date, double amount)
{
    //下面这行代码的原本目的是先计息，看迄今为止的本息够不够。
    //但这么做似乎会出现一些利息上的小问题。如第一期计息0.007，第二期计息0.007，四舍五入以后就是第一期0.01，第二期0.01，合计0.02.
    //而如果说是单期计息的话，就是一共0.014，四舍五入以后合计0.01。
    /*
    accumulate(date);
    settle(date);
    */

    if (amount > balance)
    {
        cout << "Warning! You don't have enough money!!\n";
    }
    else
    {
        //注意这里是负值！
        record(-amount, date);
    }
}

void SavingAccount::show()
{
    cout << "id: " << id << "\t, balance: " << balance << endl;
}


int main()
{
    SavingAccount sa0(1, 21325302, 0.015);
    SavingAccount sa1(1, 58320212, 0.015);

    sa0.deposit(5, 5000);
    sa1.deposit(25, 10000);
    sa0.deposit(45, 5500);    
    sa1.withdraw(60, 4000);

    sa0.settle(90);
    sa1.settle(90);

    sa0.show();
    sa1.show();

}

