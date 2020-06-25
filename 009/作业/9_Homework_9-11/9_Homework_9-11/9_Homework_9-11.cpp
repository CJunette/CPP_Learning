// 9_Homework_9-11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template<class T, size_t N>
void selectSort(T (&a)[N])
{
	for(int i = 0; i < N; i++)
	{
		int min = i;
		for(int j = i; j < N; j++)
		{
			//逆序就把这里的大于号改成小于号。
			if(a[j] < a[min])
			{
				min = j;
			}
		}
		T temp;
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
		
		cout << "Step: " << i + 1 << " : \t";
		for(int k = 0; k < N; k++)
		{
			cout << a[k] << "\t";
		}
		cout << endl;
	}	
}

int main()
{
    int data1[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
	cout << "Origin array:   ";
	for(int k = 0; k < sizeof(data1) / sizeof(int); k++)
	{
		cout << data1[k] << "\t";
	}
	cout << endl << endl;
	selectSort(data1);
}