// 10_Homework_10-17-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/array.hpp>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

template<class InputIterator, class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result)
{
    vector<iterator_traits<InputIterator>::value_type> s;
    while(first != last)
    {
        s.push_back(*first);
        first++;
    }
    sort(s.begin(), s.end());
    copy(s.begin(), s.end(), result);
}

int main()
{
    ostream_iterator<double> out(cout, "\t");
    boost::array<double, 5> a = { 1.2, 2.4, 0.8, 3.3, 3.2 };
    mySort(a.begin(), a.end(), out);
}