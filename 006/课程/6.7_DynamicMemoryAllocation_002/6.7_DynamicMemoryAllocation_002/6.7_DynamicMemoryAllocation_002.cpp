// 6.7_DynamicMemoryAllocation_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//这是根据老师上课讲到的关于用一个变量创建一个数组的尝试。
//程序所做的是将一组输入的数据放进字符串，然后将字符串中的数据传入一组大小不确定的数组，最后将数组输出。
//这个程序只是展示了能创建一个大小由变量决定的可能性。但由于这个长度说白了还是由字符串提供的，所以目前为止这个程序没有太大的实际意义。

#include <iostream>
using namespace std;

int main()
{
	//这个程序实际上就是希望说明下面这几行代码。
	/*
	int a = 5;
	int *b = new int[a];
	delete[] b;
	*/

	//实际上我觉得string这个变量本身可能就是一个动态内存分配的产物。
	string s;
	cin >> s;
	int size = s.size();
	int *ptr = new int[size];
	int index = 0;
	for (char e : s)
	{
		ptr[index] = (int)e - 48;
		index++;
	}

	for (index = size - 1; index >= 0; index--)
	{
		cout << ptr[index] << endl;
	}
	//如果删除对象是数组，则需要在delete后面加上[]。如果没有[]，那释放的仅仅是数组首元素的地址。
	delete[] ptr;
}
