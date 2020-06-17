// 9.5_LinkedList_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//结点类模板。

#include <iostream>
#include "Node.h"
using namespace std;

int main()
{
    Node<int> c(3), b(2, &c), a(1, &b);
    cout << "a: " << a.data << endl;
    cout << "b: " << a.nextNode()->data << endl;
    cout << "c: " << a.nextNode()->nextNode()->data << endl;
}