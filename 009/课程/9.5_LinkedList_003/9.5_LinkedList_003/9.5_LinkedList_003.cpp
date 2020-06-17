// 9.5_LinkedList_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "LinkedList.h"
using namespace std;

int main()
{
	const int width = 8;

    cout << "Please input 10 integers: " << endl;
	LinkedList<int> list;
	for(int i = 0; i < 10; i++)
	{
		int num;
		cin >> num;
		list.insertRear(num);
	}

	list.reset();	
	for(int i = 0; i < list.getSize(); i++)
	{
		cout << setw(width) << list.data();
		list.next();
	}
	cout << endl;
	cout << "Please input the number you want to find and delete: " << endl;
	int deleteNum;
	cin >> deleteNum;

	list.reset();
	for(int i = 0; i < list.getSize(); i++)
	{
		if(list.data() == deleteNum)
		{
			list.deleteCurrent();
		}
		list.next();
	}

	cout << "The list after delete: " << endl;
	list.reset();
	for(int i = 0; i < list.getSize(); i++)
	{
		cout << setw(width) << list.data();
		list.next();
	}
	list.clear();
}
