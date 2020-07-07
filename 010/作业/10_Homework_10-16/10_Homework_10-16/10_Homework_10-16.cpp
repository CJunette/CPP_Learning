// 10_Homework_10-16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

template<class InputIterator, class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result, output_iterator_tag)
{
    vector<typename iterator_traits<InputIterator>::value_type> s(first, last);
    sort(s.begin(), s.end());
    copy(s.begin(), s.end(), result);
}

template<class InputIterator, class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result, random_access_iterator_tag)
{
    OutputIterator resultLast = copy(first, last, result);
    sort(result, resultLast);
}

template<class InputIterator, class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result)
{
    //注意，这里iterator_category()需要括号。
    mySort(first, last, result, typename iterator_traits<OutputIterator>::iterator_category());
}

int main()
{
    double a[] = { 1.2, 2.4, 0.8, 3.3, 3.2 };
    double b[5];
    
    mySort(a, a + 5, b);
    copy(b, b + 5, ostream_iterator<double>(cout, " "));
    cout << endl;

    mySort(a, a + 5, ostream_iterator<double>(cout, " "));
    cout << endl;
}