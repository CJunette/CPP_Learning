// 6_Experiment_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//要求：输入3*3的数组，用函数进行转置。

#include <iostream>
using namespace std;

void transposition(int a[][3], int b[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			b[j][i] = a[i][j];
		}
	}
}

//课上提到用引用比用循环更安全。可能是因为引用不能修改指向。
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
    int a[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << endl;
	cout << "The input matrix: " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}

	int b[3][3];
	transposition(a, b);
	cout << "The matrix after transposition: " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << b[i][j] << "\t";
		}
		cout << endl;
	}

	int c[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			c[i][j] = a[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++)
		{
			swap(c[i][j], c[j][i]);
		}
	}

	cout << "The matrix after transposition with swap(): " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << c[i][j] << "\t";
		}
		cout << endl;
	}
}

