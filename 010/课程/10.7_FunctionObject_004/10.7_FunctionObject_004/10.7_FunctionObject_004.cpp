// 10.7_FunctionObject_004.cpp : This file contains the 'main' function. Program execution begins and ends there.
//利用STL中的二元谓词函数对象，实现数组从大到小排序的功能。

#include <iostream>
#include <vector>
#include <algorithm>;
#include <functional>
#include <iterator>
using namespace std;

int main()
{
	int arr[] = { 30, 90, 10, 40, 70, 50, 20, 80 };
	int N = sizeof(arr) / sizeof(int);
	vector<int> v(arr, arr + N);
	cout << "Before sorting: " << endl;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	cout << "After sorting: " << endl;
	//greater()的返回值是布尔类型的。回想一下，上一章中自己写排序算法的时候，如果希望序列的升序降序发生改变，通常的做法就是将某个判断语句中的大于号改为小于号。
	sort(v.begin(), v.end(), greater<int>());
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
}