// 10.8_Algorithm_004.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;

int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

    //元素的累积。
    cout << accumulate(v.begin(), v.end(), 0) << endl << endl;

    //向量的内积。
    //返回值是两个数组元素逐各相乘后相加，再加上第四个参数后得到的值。
    cout << inner_product(v.begin(), v.end(), v.begin(), 10) << endl << endl;

    //向量容器中元素局部求和。求和并不改变原容器中的数值。
    partial_sum(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;    

    //向量容器中相邻元素差值。就是取当前迭代器和其之前邻迭代器的差（首位则返回自己）。
    adjacent_difference(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;
}