// 6.3_ArrayAsParameter_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//课上的例子。

#include <iostream>
using namespace std;

//这里我对二维数组作为函数形参时，实参不能提供第二维度与形参不同的数组这个现象产生了疑问。
//6.3_ArrayAsParameter_003是针对这个而写的。
void rowSum(int a[][4], int nRow)
{
	for (int i = 0; i < nRow; i++)
	{
		int sum = 0;
		for (int j = 0; j < 4; j++)
		{
			sum += a[i][j];
		}
		a[i][0] = sum;
	}
}

int main()
{
    int a[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << a[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
	rowSum(a, 3);
	for (int i = 0; i < 3; i++)
	{
		cout << "Sum of row " << i << " is " << a[i][0] << endl;
	}
}

