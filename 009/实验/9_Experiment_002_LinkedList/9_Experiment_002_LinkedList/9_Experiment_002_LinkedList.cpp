// 9_Experiment_002_LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;

int main()
{
    //注释为测试代码。
    /*
    LinkedList<int> l1;
    //输出1。
    l1.insertRear(1);
    //输出21。
    l1.insertFront(2);
    //输出321。
    l1.insertBefore(3);
    //输出3421。
    l1.insertAfter(4);
    l1.reset();

    cout << l1.data() << endl;
    l1.next();
    cout << l1.data() << endl;
    l1.next();
    cout << l1.data() << endl;
    l1.next();
    cout << l1.data() << endl;
    l1.next();
    cout << endl;

    //输出421。
    l1.deleteFront();
    cout << l1.data() << endl;
    l1.next();
    cout << l1.data() << endl;
    l1.next();
    cout << l1.data() << endl;
    cout << endl;

    //输出42。
    l1.deleteCurrent();
    l1.reset();
    cout << l1.data() << endl;
    l1.next();
    cout << l1.data() << endl;
    cout << endl;

    LinkedList<int> l2;
    l2.insertRear(1);
    l2.insertRear(3);
    l2.reset();
    l1 = l1 + l2;
    while(!l1.endOfList())
    {
        cout << l1.data() << " ";
        l1.next();
    }
    cout << endl;
    */
    LinkedList<int> l1;
    LinkedList<int> l2;
    for(int i = 0; i < 5; i++)
    {
        l1.insertRear(i);
    }
    for(int i = 5; i < 10; i++)
    {
        l2.insertRear(i);
    }
    l1.reset();
    l2.reset();

    while(!l1.endOfList())
    {
        cout << l1.data() << " ";
        l1.next();
    }
    cout << endl;
    while(!l2.endOfList())
    {
        cout << l2.data() << " ";
        l2.next();
    }
    l1.reset();
    l2.reset();
    cout << endl;

    l1 = l1 + l2;
    while(!l1.endOfList())
    {
        cout << l1.data() << " ";
        l1.next();
    }
    cout << endl;
}