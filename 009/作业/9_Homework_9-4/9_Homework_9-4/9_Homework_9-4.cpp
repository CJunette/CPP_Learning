// 9_Homework_9-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DNode.h"
using namespace std;

int main()
{
	const int length = 10;
    DNode<int> dnode[length];
    DNode<int> *front = &dnode[0];
    DNode<int> *end= &dnode[9];

	for(int i = 0; i < length; i++)
	{
		dnode[i].data = i;
		if(i < 9)
		{
			dnode[i].insertRight(&dnode[i + 1]);
		}
	}
	
	for(int i = 0; i < length; i++)
	{
		DNode<int> *p = front;
		for(int j = 0; j < i; j++)
		{
			p = p->nextRightNode();
		}
		cout << p->data << " ";
	}
	cout << endl;

	for(int i = 0; i < length; i++)
	{
		DNode<int> *p = end;
		for(int j = 0; j < i; j++)
		{
			p = p->nextLeftNode();
		}
		cout << p->data << " ";
	}
	cout << endl;
}