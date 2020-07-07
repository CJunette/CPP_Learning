// 10_Homework_10-17-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/unordered_map.hpp>
using namespace std;
using namespace boost;

int main()
{
    unordered_map<string, int> course;
    course.insert(make_pair("CSAPP", 3));
    course.insert(make_pair("C++", 2));
    course.insert(make_pair("CSARCH", 4));
    course.insert(make_pair("COMPILER", 4));
    course.insert(make_pair("OS", 4));

    int n = 3;
    int sum = 0;

    while(n != 0)
    {
        string str;
        cin >> str;
        typename unordered_map<string, int>::iterator iter = course.find(str);
        if(iter != course.end())
        {
            sum += iter->second;
            n -= 1;
        }
        else
        {
            cout << "Invalid course name!" << endl;
        }
    }
    cout << "Credit sum: " << sum << endl;
}