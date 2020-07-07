// 10_Homework_10-9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
    int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    cout << "Original array: ";
    copy(a, a + 10, ostream_iterator<int>(cout, " "));
    cout << endl;

    swap(a[5], a[6]);
    cout << "After swap: ";
    copy(a, a + 10, ostream_iterator<int>(cout, " "));
    cout << endl;

    //似乎swap()和iter_swpa()的区别就是，swap()是直接交换容器内的元素，而iter_swap()是通过迭代器来实现交换。
    iter_swap(&a[1], &a[4]);
    cout << "After iter_swap: ";
    copy(a, a + 10, ostream_iterator<int>(cout, " "));
    cout << endl;

    swap_ranges(a, a + 5, a + 5);
    cout << "After swap_ranges: ";
    copy(a, a + 10, ostream_iterator<int>(cout, " "));
    cout << endl;
}