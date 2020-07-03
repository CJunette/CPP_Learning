// 10.9_Supplement_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//书上p473关于iterator_traits传递迭代器指向元素的信息的相关例子。

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

template<class InputIterator, class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result)
{
    vector<typename iterator_traits<InputIterator>::value_type> s(first, last);
    sort(s.begin(), s.end());
    copy(s.begin(), s.end(), result);
}

int main()
{
    double a[] = { 1.2, 2.4, 0.8, 3.3, 3.2 };
    mySort(a, a + 5, ostream_iterator<double>(cout, " "));
    cout << endl;
    mySort(istream_iterator<double>(cin), istream_iterator<double>(), ostream_iterator<double>(cout, " "));
    cout << endl;
}