// 10.8_Algorithm_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//书上p450-451的示例。

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    int iarray0[] = { 0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8 };
    int iarray1[] = { 6, 6 };
    int iarray2[] = { 5, 6 };
    int iarray3[] = { 0, 1, 2, 3, 4, 5, 7, 7, 7, 9, 7 };
    vector<int> ivector0{ iarray0, iarray0 + sizeof(iarray0) / sizeof(int) };
    vector<int> ivector1{ iarray1, iarray1 + sizeof(iarray1) / sizeof(int) };
    vector<int> ivector2{ iarray2, iarray2 + sizeof(iarray2) / sizeof(int) };
    vector<int> ivector3{ iarray3, iarray3 + sizeof(iarray3) / sizeof(int) };

    //找出ivector0之中相邻元素值相等的第一个元素。
    //输出6。
    cout << *adjacent_find(ivector0.begin(), ivector0.end()) << endl;

    //找出ivector0中小于7的元素个数。
    //输出9。
    cout << count_if(ivector0.begin(), ivector0.end(), bind2nd(less<int>(), 7)) << endl;

    //找出ivector0中大于2的第一个元素。
    //输出3。
    cout << *find_if(ivector0.begin(), ivector0.end(), bind2nd(greater<int>(), 2)) << endl;

    //子序列ivector2在ivector0中出现的起点位置元素。
    //输出5。
    cout << *search(ivector0.begin(), ivector0.end(), ivector2.begin(), ivector2.end()) << endl;

    //查找连续出现3个6的起点位置元素。
    //输出6。
    cout << *search_n(ivector0.begin(), ivector0.end(), 3, 6, equal_to<int>()) << endl;

    //判断两个区间ivector0和ivector3是否相等。
    //输出0。
    cout << equal(ivector0.begin(), ivector0.end(), ivector3.begin()) << endl;

    //查找区间ivector3在ivector0中不匹配点的位置。
    //输出6。
    pair<vector<int>::iterator, vector<int>::iterator> result1 = mismatch(ivector0.begin(), ivector0.end(), ivector3.begin());
    //注意，这里可以用两个迭代器相减的方式求得迭代器的距离。
    cout << result1.first - ivector0.begin() << endl;

    //查找区间ivector2在ivector1中不匹配点的位置。
    //输出0。
    pair<vector<int>::iterator, vector<int>::iterator> result2 = mismatch(ivector1.begin(), ivector1.end(), ivector2.begin());
    cout << result2.first - ivector1.begin() << endl;
}