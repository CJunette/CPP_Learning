// 11_Homework_11-7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    //保存现有的格式化参数设置，以便将来恢复这些设置。
    ios_base::fmtflags original_flags = cout.flags();
    cout << 812 << '|';
    cout.setf(ios_base::left, ios_base::adjustfield);
    cout.width(10);
    cout << 813 << 815 << '\n';
    cout.unsetf(ios_base::adjustfield);
    cout.precision(2);
    cout.setf(ios_base::uppercase | ios_base::scientific);
    cout << 831.0;
    //恢复原来的格式化参数设置。
    cout.flags(original_flags);
}