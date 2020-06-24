// 9_Experiment_001_Node.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"
using namespace std;

int main()
{
    Node<int> n[10];
	for(int i = 0; i < 9; i++)
	{
		n[i].data = i % 3;
		//注意，如果这里循环结束条件写i < 10，insertAfter()语句是会越界的。
		n[i].insertAfter(&n[i + 1]);
	}
	//最后一个元素要单独定义。
	n[9] = 9;
	
	Node<int> *ptr = &n[0];
	Node<int> *front = &n[0];
	while(ptr != NULL)
	{
		cout << ptr->data << "  ";
		ptr = ptr->nextNode();
	}
	cout << endl;

	cout << "input the number to delete: ";
	int num;
	cin >> num;

	if(front->data == num)
	{
		front = front->nextNode();
	}
	ptr = front;
	while(ptr->nextNode() != NULL)
	{
		if(ptr->nextNode()->data == num)
		{
			ptr->deleteAfter();
		}
		ptr = ptr->nextNode();
	}

	ptr = front;
	cout << "chain after delete" << endl;
	while(ptr != NULL)
	{
		cout << ptr->data << "  ";
		ptr = ptr->nextNode();
	}
	cout << endl;

	ptr = front;
	while(ptr->nextNode() != NULL)
	{
		ptr->deleteAfter();
		//这里由于不停删除后方元素，因此不需要在主动去到下一个节点。
	}	
	ptr = front = NULL;
}
