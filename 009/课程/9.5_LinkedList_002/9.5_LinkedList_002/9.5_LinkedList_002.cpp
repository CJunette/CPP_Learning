// 9.5_LinkedList_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//链表类模板。

#include <iostream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;

//0.Node的定义与9.5_LinkedList_001中的完全一致，因此直接引用头文件。

int main()
{
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
}