// 9.7_Queue_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//简化的队列类。

#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    Queue<int> que;
    que.insert(1);
    que.insert(2);
    que.insert(3);
    cout << que.remove() << endl;
    cout << que.remove() << endl;
    cout << que.remove() << endl;    
}