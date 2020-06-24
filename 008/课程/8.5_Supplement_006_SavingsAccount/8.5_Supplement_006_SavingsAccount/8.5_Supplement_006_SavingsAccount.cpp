// 8.5_Supplement_006_SavingsAccount.cpp : This file contains the 'main' function. Program execution begins and ends there.
//8.6的综合实例。

#include <iostream>
#include <string>
#include "Account.h"
#include "Accumulator.h"
#include "Date.h"
using namespace std;

bool checkIndex(int index, int n)
{
    if(index >= n || index < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    Date date(2008, 11, 1);
    SavingsAccount sa1(date, "S3755217", 0.015);
    SavingsAccount sa2(date, "02342342", 0.015);
    CreditAccount ca(date, "C5392394", 10000, 0.0005, 50);
    Account *accounts[] = { &sa1, &sa2, &ca };
    const int n = sizeof(accounts) / sizeof(Account *);
    

    cout << "(d)deposit (w)withdraw (s)show (c)change day (n)next month (e)exit" << endl;
    char cmd;

    do
    {
        date.show();
        cout << "\t Total: " << Account::getTotal() << "\tcommand>";
        int index, day;
        double amount;
        string desc;
        cin >> cmd;
        
        switch(cmd)
        {
            case 'd':
                cin >> index >> amount;
                if(checkIndex(index, n))
                {
                    getline(cin, desc);
                    accounts[index]->deposit(date, amount, desc);
                    break;
                }
                else
                {
                    cout << "Wrong input for account." << endl;
                    break;
                }
            case 'w':
                cin >> index >> amount;
                if(checkIndex(index, n))
                {
                    getline(cin, desc);
                    accounts[index]->withdraw(date, amount, desc);
                    break;
                }
                else
                {
                    cout << "Wrong input for account." << endl;
                    break;
                }                
            case 's':
                for(int i = 0; i < n; i++)
                {
                    cout << "[" << i << "]";
                    accounts[i]->show();
                    cout << endl;
                }
                break;
            case 'c':
                cin >> day;
                if(day < date.getDay())
                {
                    cout << "You can't specify a previous day.";
                }
                else if(day > date.getMonthDays())
                {
                    cout << "Invalid day";
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
                for(int i = 0; i < n; i++)
                {
                    accounts[i]->settle(date);
                }
                break;
            default:
                break;
        }

    } while(cmd != 'e');
    

    //下面是用来调试的代码。
    /*
    cout << Date(2008, 12, 31) - Date(2008, 12, 5) << endl;
    cout << Date(2009, 1, 1) - Date(2008, 12, 5) << endl;
    cout << Date(2009, 1, 1) - Date(2008, 12, 31) << endl;
    cout << Date(2008, 12, 31) - Date(2008, 1, 1) << endl;
    cout << Date(2008, 3, 1) - Date(2008, 2, 29) << endl;

    accounts[0]->deposit(Date(2008, 11, 5), 5000, "salary");
    accounts[2]->withdraw(Date(2008, 11, 15), 2000, "buy a cell");
    accounts[1]->deposit(Date(2008, 11, 25), 10000, "sell stock 0323");
    accounts[2]->settle(Date(2008, 12, 1));
    accounts[2]->deposit(Date(2008, 12, 1), 2016, "repay the credit");
    accounts[0]->deposit(Date(2008, 12, 5), 5500, "salary");

    for(int i = 0; i < n; i++)
    {
        accounts[i]->settle(Date(2009, 1, 1));
    }

    for(int i = 0; i < n; i++)
    {
        accounts[i]->show();
        cout << endl;
    }
    */

    return 0;
}
