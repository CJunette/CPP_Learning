// 6.7_DynamicMemoryAllocation_004_ForArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const int a = 7;
const int b = 8;
const int c = 9;

int main()
{
	//动态创建多维数组时，必须在类型名后写上各个维的长度！这和一般数组初始化时不需要写第一维的做法不同。
	//另外，此时我们需要的是一个指向一个[b][c]数组的指针，因此必须写“(*ptr)”。如果去掉这里的括号，ptr就变成了一个b列c行的用来存放指针的数组。
	int(*ptr)[b][c] = new int[a][b][c];
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			for (int k = 0; k < c; k++)
			{
				//指向数组元素的指针，+1时是向后移动一个元素；
				//指向数组的指针，+1时是向后移动整个数组的长度。
				//在这里，ptr是指向[a][b][c]的指针，*ptr是指向[b][c]的指针，**ptr是指向[c]的指针，***ptr是[c]的首个元素。
				//+k是向后移动一个元素，+j是向后移动一维数组（向后移c个单位），+i是向后移动更高一维的数组（向后移c*b个单位）。
				//在第一次写这个程序的时候，我就因为搞错了i、j、k的位置和其移动的范围而造成了错误。
				*(*(*(ptr + i) + j) + k) = i * 100 + j * 10 + k;
			}
		}
	}
	
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			for (int k = 0; k < c; k++)
			{
				//由于以前说到的数组名和指针的可替换性，这里也可以用这种更为简单的表达方式。
				cout << ptr[i][j][k] << '\t';
			}
			cout << endl;
		}
		cout << endl;
	}
	//即使对于多维数组而言，delete的时候仍然也只需要一个[]就够了。
	delete[] ptr;
}
