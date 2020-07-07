// 10_Experiment_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

int main()
{
	int a[8] = { 3, 2, 5, 6, 4, 1, 9, 8 };
	cout << "origin array: ";
	copy(a, a + 8, ostream_iterator<int>(cout, " "));
	cout << endl;

	//find()返回的是指针地址，因此要减去初始地址才能得到编号。
	cout << "index of \"9\" is " << find(a, a + 8, 9) - a << endl;

	cout << "ascend order: ";
	sort(a, a + 8);
	copy(a, a + 8, ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "descend order: ";
	//这里下面的greater<int>()如果写“greater<>()”也是可以的，会默认模板参数为void。F12可知STL中对greater<void>的情况进行了特化，其中以函数模板形式重载了“()”，可以根据函数参数确定模板参数。
	//但不能只写“greater()”，这样编译器会报错，错误是缺少模板参数。
	sort(a, a + 8, greater<int>());
	copy(a, a + 8, ostream_iterator<int>(cout, " "));
}