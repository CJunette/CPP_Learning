// 10.9_Supplement_003_SavingsAccount.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Account.h"
#include "Date.h"
using namespace std;

//定义deleter类并重载“()”，便于在算法for_each中使用。
struct deleter
{
    //这里相比将类本身作为模板，将类中的成员函数作为模板是更方便的选择。
    //因为这样一来，在调用时就不需要明确指出模板参数类型了。
    template<class T>
    void operator () (T *t) { delete t; }
};

int main()
{
    /*
    //注释为测试代码。
    vector<Account *>accounts(0);
    Date date(2008, 11, 1);
    accounts.resize(1);
    accounts[0] = new SavingsAccount(date, "S3755217", 0.015);
    accounts.resize(2);
    accounts[1] = new SavingsAccount(date, "02342342", 0.015);
    accounts.resize(3);
    accounts[2] = new CreditAccount(date, "C5392394", 10000, 0.0005, 50);

    accounts[0]->deposit(Date(2008, 11, 5), 5000, "salary");
    accounts[2]->withdraw(Date(2008, 11, 15), 2000, "buy a cell");
    accounts[1]->deposit(Date(2008, 11, 25), 10000, "sell stock 0323");
    accounts[2]->settle(Date(2008, 12, 1));
    accounts[2]->deposit(Date(2008, 12, 1), 2016, "repay the credit");
    accounts[0]->deposit(Date(2008, 12, 5), 5500, "salary");

    for(int i = 0; i < accounts.size(); i++)
    {
        accounts[i]->settle(Date(2009, 1, 1));
        cout << endl;
    }

    for(int i = 0; i < accounts.size(); i++)
    {
        accounts[i]->show();
        cout << endl;
    }
    Date(2009, 1, 1).show();
    cout << "\tTotal: " << Account::getTotal() << endl << endl;

    Account::query(Date(2008, 11, 1), Date(2008, 11, 30));
    Account::query(Date(2008, 12, 1), Date(2008, 12, 30));
    */

    vector<Account *> accounts(0);
    Date date(2008, 11, 1);
    cout << "(a)add account (d)deposit (w)withdraw (s)show (c)change day (n)next month e(exit)" << endl;
    char cmd;
    date.show();
    cout << "\tTotal: " << Account::getTotal() << "\tcommand>";

    char type;
    string id, desc;
    double amount, credit, rate, fee;
    int index, day;
    Date begin, end;

    while(cin >> cmd, cmd != 'e')
    {
        switch(cmd)
        {
            case 'a':
                cin >> type >> id;
                if(type == 's')
                {
                    cin >> rate;
                    accounts.push_back(new SavingsAccount(date, id, rate));
                }
                else if(type == 'c')
                {
                    cin >> credit >> rate >> fee;
                    accounts.push_back(new CreditAccount(date, id, credit, rate, fee));
                }
                else
                {
                    cout << "unknown account type" << endl;
                    continue;
                }                
                break;

            case 'd':
                cin >> index >> amount;
                getline(cin, desc);
                accounts[index]->deposit(date, amount, desc);
                break;

            case 'w':
                cin >> index >> amount;
                getline(cin, desc);
                accounts[index]->withdraw(date, amount, desc);
                break;

            case 's':
                for(int i = 0; i < accounts.size(); i++)
                {
                    cout << "[" << i << "]";
                    accounts[i]->show();
                    cout << endl;
                }
                break;

            case 'c':
                cin >> day;
                if(day > date.getMonthDays())
                {
                    cout << "Error! Invalid day!" << endl;
                    continue;
                }
                else if(day <= date.getDay())
                {
                    cout << "Error! Can't go back to the past" << endl;
                    continue;
                }
                else
                {
                    date = Date(date.getYear(), date.getMonth(), day);
                }
                break;

            case 'n':
                if(date.getMonth() == 12)
                {
                    date = Date(date.getYear() + 1, 1, 1);
                }
                else
                {
                    date = Date(date.getYear(), date.getMonth() + 1, 1);
                }
                for(vector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); iter++)
                {
                    (*iter)->settle(date);
                }
                break;

            case 'q':
                begin = Date::read();
                end = Date::read();
                //如果输入的日期大于现在的日期，则报错。
                if(date < begin)
                {
                    cout << "That day is too far away!" << endl;
                    continue;
                }
                Account::query(begin, end);
                break;

            default:
                cout << "Unknow command!" << endl;
                break;
        }
        date.show();
        cout << "\t Total: " << Account::getTotal();
        cout << "\t command>";
    }
    for_each(accounts.begin(), accounts.end(), deleter());
}