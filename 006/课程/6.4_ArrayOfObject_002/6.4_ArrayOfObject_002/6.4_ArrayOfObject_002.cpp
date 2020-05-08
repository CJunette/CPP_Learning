// 6.4_ArrayOfObject_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//课上的例子。

#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
    cout << "Entering main..." << endl;
	//对象数组里有多少个成员，就要调用多少次构造函数。同理，也要调用同样次数的析构函数。
    Point a[2];
	for (int i = 0; i < 2; i++)
	{
		a[i].move(i + 10, i + 20);
	}
	cout << "Exiting main..." << endl;
	
}

