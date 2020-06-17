// 9.8_Sort_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//选择排序。
//要求定义一个函数，当输入一个数组时，对数组内的元素进行从小到大的排序。

#include <iostream>
using namespace std;

template<class T, size_t N>
void selectionSort(T(&a)[N])
{
	//1.如果这里循坏条件写N，由于j = i + 1；因此i的最后一次循环中，是j的循环是不会被执行的。
	//1.所以这里循环条件写N - 1就行。
	for(int i = 0; i < N - 1; i++)
	{
		int min = a[i];
		int index = i;
		for(int j = i + 1; j < N; j++)
		{
			if(a[j] < min)
			{
				min = a[j];
				index = j;
			}
			//1.这里，课上的示范代码会更简单一些。
			/*
			if(a[j] < a[index])
			{
				index = j;
			}
			*/
		}
		if(index != i)
		{
			T temp = a[i];
			a[i] = a[index];
			a[index] = temp;
		}
	}
}

int main()
{
	int a1[5] = { 4, 2, 5, 3, 1 };
	for(int i = 0; i < 5; i++)
	{
		cout << a1[i] << "\t";
	}
	cout << endl;
	selectionSort(a1);
	for(int i = 0; i < 5; i++)
	{
		cout << a1[i] << "\t";
	}
	cout << endl;
}
