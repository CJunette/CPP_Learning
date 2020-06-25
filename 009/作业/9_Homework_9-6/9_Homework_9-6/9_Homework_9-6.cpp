// 9_Homework_9-6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "OrderList.h"

int main()
{
    OrderList<int> list1;
    list1.insert(1);
    list1.insert(5);
    list1.insert(4);
    list1.insert(2);
    list1.insert(3);
    list1.reset();
    for(int i = 0; i < 5; i++)
    {
        cout << list1.data() << " ";
        list1.next();
    }
    cout << endl;

    list1.insert(list1);
    list1.reset();
    for(int i = 0; i < 10; i++)
    {
        cout << list1.data() << " ";
        list1.next();
    }
    cout << endl;

    OrderList<int> list2;
    list2.insert(6);
    list2.insert(7);
    list2.insert(8);
    list2.insert(0);
    list2.insert(9);
    list2.reset();
    for(int i = 0; i < 5; i++)
    {
        cout << list2.data() << " ";
        list1.next();
    }
    cout << endl;

    list1.insert(list2);
    list1.reset();
    for(int i = 0; i < 15; i++)
    {
        cout << list1.data() << " ";
        list1.next();
    }
    cout << endl;
}
