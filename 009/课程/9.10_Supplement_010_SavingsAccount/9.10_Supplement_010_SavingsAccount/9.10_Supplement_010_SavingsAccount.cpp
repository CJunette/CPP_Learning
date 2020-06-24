// 9.10_Supplement_010_SavingsAccount.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Array.h"
#include "Date.h"
#include "Account.h"
using namespace std;

int main()
{
    /*
    //注释为测试代码。
    Array<Account *>accounts(0);
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

    for(int i = 0; i < accounts.getSize(); i++)
    {
        accounts[i]->settle(Date(2009, 1, 1));
    }

    for(int i = 0; i < accounts.getSize(); i++)
    {
        accounts[i]->show();
        cout << endl;
    }
    Date(2009, 1, 1).show();
    cout << "\tTotal: " << Account::getTotal() << endl;
    */
    
    Date date(2008, 11, 1);
    Array<Account *>accounts(0);
    cout << "(a)add account (d)deposit (w)withdraw (s)show (c)change day (n)next month e(exit)" << endl;
    char cmd;
    date.show();
    cout << "\tTotal: " << Account::getTotal() << "\tcommand>";

    //这里把string单独拿出来是因为如果放在switch里面，会出现错误。
    //好像如果把string放入swtich，则每一个case都必须对其进行初始化。
    string id;
    string desc;
    //后来我把其他的一些标识符也拿出来了，因为在switch中定义会出现重复定义的问题。
    //case 'a'
    char type;
    Account *account;
    //case 'd' and case 'w'
    int index;
    double amount;
    //case 'd' and case 'w'
    double credit, rate, fee;
    //case 'c'
    int day;

    while(cin >> cmd, cmd != 'e')
    {
        switch(cmd)
        {
            //新增了命令a，用于添加新账户。
            case 'a':

                cin >> type >> id;
                if(type == 's')
                {
                    cin >> rate;
                    account = new SavingsAccount(date, id, rate);
                }
                else
                {
                    cin >> credit >> rate >> fee;
                    account = new CreditAccount(date, id, credit, rate, fee);
                }
                accounts.resize(accounts.getSize() + 1);
                accounts[accounts.getSize() - 1] = account;
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
                for(int i = 0; i < accounts.getSize(); i++)
                {
                    cout << "[" << i << "] ";
                    accounts[i]->show();
                    cout << endl;
                }
                break;
                
            case 'c':
                cin >> day;                
                if(day < 0 || day > date.getMonthDays())
                {
                    cout << "Invalid day" << endl;                    
                }
                else if(day < date.getDay())
                {
                    cout << "You can't go to previous day." << endl;                    
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
                for(int i = 0; i < accounts.getSize(); i++)
                {
                    accounts[i]->settle(date);
                }
                break;

            default:
                cout << "Unknown command" << endl;                
                break;
        }
        date.show();
        cout << "\tTotal: " << Account::getTotal() << "\tcommand>";
    }
    //由于这次所有的账户都是动态添加的，因此要记得在最后进行delete操作。
    for(int i = 0; i < accounts.getSize(); i++)
    {
        delete accounts[i];
    }
    
}
