// 9_Homework_9-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
    cout << "Please input students number" << endl;
    int n;
    cin >> n;
    cout << "Please input " << n << " score(s)" << endl;
    Array<double> a(n);
    double sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    double average = sum / n;
    cout << "The average score is " << average << endl;
}