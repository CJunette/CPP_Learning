// 9_Homework_9-9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template<class T, size_t N>
void insertSort(T (&a)[N])
{
	for(int i = 1; i < N; i++)
	{
		T temp = a[i];
		int j = i;
		for(j; j > 0; j--)
		{
			//逆序就把这里的大于号改成小于号。
			if(a[j - 1] > temp)
			{
				a[j] = a[j - 1];
			}
			else
			{
				break;
			}
		}
		a[j] = temp;
		
		cout << "Step: " << i << " : \t";
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
	for(int k = 0; k < sizeof(data1)/sizeof(int); k++)
	{
		cout << data1[k] << "\t";
	}
	cout << endl << endl;
	insertSort(data1);
}
