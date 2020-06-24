// 9_Experiment_005_ArrayWithSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
    int a[5] = { 3, 6, 1, 8, 2 };
    double b[4] = { 4.1, 3.2, 5.6, 1.9 };
    char c[3] = { 'g', 'c', 'A' };
    Array<int> arr1(a);
    Array<double> arr2(b);
    Array<char> arr3(c);
    
    for(int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "after sort" << endl;
    arr1.insertSort();
    for(int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < 4; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << "after sort" << endl;
    arr2.insertSort();
    for(int i = 0; i < 4; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < 3; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;
    cout << "after sort" << endl;
    arr3.insertSort();
    for(int i = 0; i < 3; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;
}
