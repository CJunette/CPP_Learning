// 10_Homework_10-11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
    vector<int> v{ 1, 1, 4, 4, 5 };
    //2.因此，需要用迭代器获得unique()的返回值。返回值的迭代器所在的位置开始向后到.end()为止，都是重复的元素。
    vector<int>::iterator del = unique(v.begin(), v.end());
    
    ostream_iterator<int> out(cout, " ");
    //1.输出为{1, 4, 5, 4, 5}。可以看到，直接输出并没有向我们想象的那样输出{1, 4, 5}。（不过为什么后面两个是{4, 5}而不是{1, 4}我也有点没搞懂。）
    //1.书上p453提到，这是因为迭代器无法实现对容器内元素的删除。
    copy(v.begin(), v.end(), out);
    cout << endl;

    v.erase(del, v.end());
    copy(v.begin(), v.end(), out);
    cout << endl;
    
    list<int> l{ 1, 1, 4, 4, 5 };
    //3.list由于容器内置了unique函数。因为是内置的函数，不必依赖迭代器，因此可以直接完成排序并实现删除。
    l.unique();
    copy(l.begin(), l.end(), out);
    cout << endl;
}