// 9_Homework_9-22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//练习册答案给出的思路是，将冒泡函数中涉及到数组元素的运算都写到专门的函数中，然后通过给那些函数写重载，来实现代码的复用。

#include <iostream>
using namespace std;

template<class T>
struct BinaSearch
{
    template<size_t N>
    static bool binaSearch(T(&a)[N], T key);

    //由于这里涉及了偏特化，因此需要用类模板。
    template<size_t N>
    static bool binaSearch(T *(&a)[N], T key);
};

//主要的函数就是这一个，其他的函数都是用各种方式调用这个函数的函数体。
template<class T>
template<size_t N>
bool BinaSearch<T>::binaSearch(T(&a)[N], T key)
{
    int min = 0, max = N - 1;
    int mid;
    int count = 1;
    while(true)
    {
        mid = (min + max) / 2;
        if(a[mid] == key)
        {
            cout << "Found! [" << mid << "]" << " = " << a[mid] << endl;
            return true;
        }
        if(a[mid] > key)
        {
            max = mid;
        }
        else
        {
            min = mid;
        }
        if(max == min + 1)
        {
            if(a[max] == key)
            {
                cout << "Found! [" << max << "]" << " = " << a[max] << endl;
                return true;
            }
            else if(a[min] == key)
            {
                cout << "Found! [" << min << "]" << " = " << a[min] << endl;
                return true;
            }
            else
            {
                return false;
            }
        }
        cout << "Step: " << count << " : \t";
        for(int k = 0; k < min; k++)
        {
            cout << "\t";

        }
        for(int k = min; k <= max; k++)
        {
            cout << a[k] << "\t";
        }
        for(int k = max + 1; k < N; k++)
        {
            cout << "\t";

        }
        cout << endl;
        count++;
    }
}

template<class T>
template<size_t N>
bool BinaSearch<T>::binaSearch(T *(&a)[N], T key)
{
    //这里模板参数N是个编译期常量，因此可以用于给数组长度赋值。
    //这里由于我希望循环利用之前的代码，所以必须创建一个新的数组（而非指针+动态数组）作为调用原函数的参数。
    T arr[N];
    for(int i = 0; i < N; i++)
    {
        arr[i] = *a[i];
    }
    return BinaSearch<T>::binaSearch(arr, key);
}

//用全局函数重载，使调用更加方便，不需要每次调用都添加类名。
template<class T, size_t N>
bool binaSearch(T(&a)[N], T key)
{
    return BinaSearch<T>::binaSearch(a, key);
}

template<class T, size_t N>
bool binaSearch(T*(&a)[N], T key)
{
    return BinaSearch<T>::binaSearch(a, key);
}


int main()
{
    int data1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    cout << "Origin array:   ";
    for(int k = 0; k < sizeof(data1) / sizeof(int); k++)
    {
        cout << data1[k] << "\t";
    }
    cout << endl << endl;
    cout << binaSearch(data1, 1) << endl;
    cout << endl;

    int a[20];
    int *data2[20];
    for(int i = 0; i < 20; i++)
    {
        a[i] = i + 1;
        data2[i] = &a[i];
    }
    for(int k = 0; k < sizeof(data2) / sizeof(int*); k++)
    {
        cout << *data2[k] << "\t";
    }
    cout << endl << endl;
    cout << binaSearch(data2, 1) << endl;
    cout << endl;
}
