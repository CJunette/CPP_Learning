// 10.7_FunctionObject_005.cpp : This file contains the 'main' function. Program execution begins and ends there.
//找到数组中第一个大于40的数。
//这里主要的操作时用bind2nd()将函数对象的第二个参数绑定，使二元函数对象变为一元函数对象。

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main()
{
    int arr[] = { 30, 90, 10, 40, 70, 50, 20, 80 };
    int N = sizeof(arr) / sizeof(int);
    //int[]的迭代器就是int *。但由于这个迭代器找到它的.end()，所以还是创建一个vector，方便迭代器的使用。
    vector<int> v(arr, arr + N);
    //由于是找数组中第一个大于40的数，并没有强调是排序的序列上第一个大于40的数，因此不需要用sort。
    /*
    sort(v.begin(), v.end());
    */

    //直接利用函数适配器的构造函数来构建binder2nd。
    /*
    find(v.begin(), v.end(), binder2nd<greater<int>>(greater<int>(), 40));
    */
    //用函数bind2nd()函数辅助构造binder2nd类。   
    //在这里，算法find_if所做的事是，从头到尾遍历迭代器，将迭代器所指向的元素放入函数对象进行求值，若取值为真则返回该迭代器，否则移向下一个迭代器继续进行。
    //但由于find_if的第三个参数要求一个一元谓词的函数对象。
    //因此需要用bind2nd将二元谓词函数对象greater()的第二个参数固定为40，变为一个一元谓词函数对象，作为算法find_if的参数。    
    vector<int>::iterator iter = find_if(v.begin(), v.end(), bind2nd(greater<int>(), 40));

    if(iter != v.end())
    {
        cout << "First element greater than 40 is " << *iter << endl;
    }
    else
    {
        cout << "No element greater than 40." << endl;
    }
}