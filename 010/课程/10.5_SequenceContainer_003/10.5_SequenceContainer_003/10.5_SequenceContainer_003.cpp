// 10.5_SequenceContainer_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//列表的拼接操作。

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

//这里我补充了两个函数，便于对list的输出。
template<class Iterator>
void output(Iterator begin, Iterator end)
{
    copy(begin, end, ostream_iterator<Iterator::value_type>(cout, " "));
    cout << endl;
}

template<class T>
void coutput(T t1, T t2)
{
    cout << "s1: ";
    output(t1.begin(), t1.end());
    cout << "s2: ";
    output(t2.begin(), t2.end());
    cout << endl;
}

int main()
{
    string names1[] = { "Alice", "Helen", "Lucy", "Susan" };
    string names2[] = { "Bob", "David", "Levin", "Mike" };
    list<string> s1(names1, names1 + 4);
    list<string> s2(names2, names2 + 4);
    cout << "original: " << endl;;
    coutput(s1, s2);

    s2.splice(s2.end(), s1, s1.begin());
    cout << "after first splice: " << endl;
    coutput(s1, s2);

    list<string>::iterator iter1 = s1.begin();
    //iter1指向s1的第三个元素。
    advance(iter1, 2);
    list<string>::iterator iter2 = s2.begin();
    //iter2指向s2的第二个元素。
    ++iter2;
    list<string>::iterator iter3 = iter2;
    //iter3指向s2的第四个元素。
    advance(iter3, 2);
    //这里实际上splice的元素时s2中的iter2（s2的第二个元素）到iter3 - 1（s2的第三个元素）的2个元素。后面的区间iter3（s2的第四个元素）是开区间。
    s1.splice(iter1, s2, iter2, iter3);
    cout << "after second splice: " << endl;
    coutput(s1, s2);
}