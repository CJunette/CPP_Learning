// 10_Homework_10-6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//要求写一个函数模板，参数为两个容器l1、l2和两个对应的迭代器iter1、iter2。要求交换容器l1的[iter1, l1.end())和l2的[iter2, l2.end())的元素。

#include <iostream>
#include <list>
using namespace std;

template<class T>
void exchange(list<T> &l1, typename list<T>::iterator p1, list<T> &l2, typename list<T>::iterator p2)
{
    //交换思路和交换一般类型的数据一致。先将第一个容器的被交换内容取出，放到临时容器中；再将第二个容器的被交换内容放到第一个容器中；最后将临时容器中的内容放到第二个容器中。
    list<T> temp = l1;
    copy(p2, l2.end(), p1);
    typename list<T>::iterator iterTemp = temp.begin();
    typename list<T>::iterator iter1 = l1.begin();
    //由于list不能直接用迭代器相减确定位置，所以必须从头检索。
    while(iter1 != p1)
    {
        iterTemp++;
        iter1++;
    }
    copy(iterTemp, temp.end(), p2);

}

template<class T>
void beginAndOutput(T t, typename T::iterator i)
{
    i = t.begin();
    while(i != t.end())
    {
        cout << *i << "\t";
        i++;
    }
    cout << endl;
}

int main()
{
    list<int> l1, l2;
    int const N = 6;
    for(int i = 0; i < N; i++)
    {
        l1.push_back(i);
    }
    for(int i = N; i < 2 * N; i++)
    {
        l2.push_back(i);
    }

    list<int>::iterator iter1, iter2;
    beginAndOutput(l1, iter1);
    beginAndOutput(l2, iter2);
    cout << endl;

    iter1 = l1.begin();
    iter2 = l2.begin();
    for(int i = 0; i < 3; i++)
    {
        iter1++;
        iter2++;
    }
    exchange(l1, iter1, l2, iter2);
    cout << endl;

    beginAndOutput(l1, iter1);
    beginAndOutput(l2, iter2);
    cout << endl;
}