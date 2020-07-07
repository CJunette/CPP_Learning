// 10_Homework_10-14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
    int a1[] = { 1, 2, 3, 4, 5 };
    int a2[] = { 6, 7, 8, 9, 10 };
    Array<int> arr1, arr2;
    arr1 = a1;
    arr2 = a2;

    cout << "Original arr1: ";
    for(int i = 0; i < arr1.getSize(); i++)
    {
        cout << arr1[i] << "\t";
    }
    cout << endl;
    cout << "Original arr2: ";
    for(int i = 0; i < arr2.getSize(); i++)
    {
        cout << arr2[i] << "\t";
    }
    cout << endl;

    arr1.swap(arr2);

    cout << "arr1 after swap: ";
    for(int i = 0; i < arr1.getSize(); i++)
    {
        cout << arr1[i] << "\t";
    }
    cout << endl;
    cout << "arr2 after swap: ";
    for(int i = 0; i < arr2.getSize(); i++)
    {
        cout << arr2[i] << "\t";
    }
    cout << endl;
}