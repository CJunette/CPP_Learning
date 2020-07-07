// 10_Homework_10-12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>
using namespace std;

int randNum()
{
    return rand() % 10;
}

int main()
{
    srand((int)time(0));
    vector<int> v(10);    
    generate(v.begin(), v.end(), randNum);
    ostream_iterator<int> out(cout, " ");
    copy(v.begin(), v.end(), out);
    cout << endl;
}