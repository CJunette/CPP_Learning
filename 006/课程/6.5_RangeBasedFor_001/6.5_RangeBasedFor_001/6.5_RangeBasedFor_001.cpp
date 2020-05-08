// 6.5_RangeBasedFor_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int array_1[3] = { 1, 2, 3 };
    int *p;
    for (p = array_1; p < array_1 + sizeof(array_1)/sizeof(int); p++)
    {
        *p += 2;
        cout << *p << endl;
    }

    cout << endl;

    int array_2[3] = { 1, 2, 3 };
    for (int &e : array_2)
    {
        e += 2;
        cout << e << endl;
    }

    //上面的这种遍历循环只适用于for，不适用与while等其他循环。
    /*
    while (int &f : array_2)
    {
    }
    */
}
