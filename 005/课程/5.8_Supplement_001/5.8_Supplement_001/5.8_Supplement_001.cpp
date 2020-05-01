// 5.8_Supplement_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "account.h"
using namespace std;

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

    cout << "Total: " << SavingAccount::getTotal() << endl;

    //sa0.settle(90)那里的10527.64在输出的时候变成了10527.6，似乎是由于浮点数误差造成的。
    double a = 10527.6399999999999999999;
    cout << a << endl;
}

