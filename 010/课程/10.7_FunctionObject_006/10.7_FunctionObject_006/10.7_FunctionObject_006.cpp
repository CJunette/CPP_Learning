// 10.7_FunctionObject_006.cpp : This file contains the 'main' function. Program execution begins and ends there.
//使用ptr_fun、not1、not2产生函数适配器。
//这里主要的操作时用ptr_fun将一般函数变为函数对象，以及用not1或not2生成逻辑反函数。

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

template<class T>
bool myGreater(T x, T y)
{
    return x > y;
}

int main()
{
    int arr[] = { 30, 90, 10, 40, 70, 50, 20, 80 };
    int N = sizeof(arr) / sizeof(int);    
    vector<int> v(arr, arr + N);

    //1.与之前相同，find_if()的第三个函数要求是一元函数谓词，所以必须对现有的函数指针myGreater进行修改。
    //1.首先，用ptr_fun(myGreater<int>)，将普通函数指针myGreater<int>转化为一个函数对象（二元函数谓词）。
    //1.然后，用bind2nd()绑定上述二元函数谓词的第二个参数，使其成为一个一元函数谓词。
    vector<int>::iterator iter = find_if(v.begin(), v.end(), bind2nd(ptr_fun(myGreater<int>), 40));
    if(iter == v.end())
    {
        cout << "No element is greater than 40." << endl;
    }
    else
    {
        cout << "First element greater than 40: " << *iter << endl;
    }
    cout << endl;
    
    //2.这里除了与上面1.相同的操作外，还用not1将之前生成了之前函数对象的逻辑反函数（其实就是对返回值求“!”）。
    iter = find_if(v.begin(), v.end(), not1(bind2nd(ptr_fun(myGreater<int>), 15)));
    if(iter == v.end())
    {
        cout << "No element is not greater than 15." << endl;
    }
    else
    {
        cout << "First element not greater than 15: " << *iter << endl;
    }
    cout << endl;

    //3.这里展示了与2.达到相同目的的不同做法。2.中是先将myGreater<int>转化为函数对象，再固定参数将二元变为一元，最后取反；
    //3.这里是先将myGreater<int>转化为函数对象，再对结果取反，最后固定参数将二元变为一元。
    iter = find_if(v.begin(), v.end(), bind2nd(not2(ptr_fun(myGreater<int>)), 15));
    if(iter == v.end())
    {
        cout << "No element is not greater than 15." << endl;
    }
    else
    {
        cout << "First element not greater than 15: " << *iter << endl;
    }
    cout << endl;
}
