// 10.6_AssociativeContainer_004.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main()
{
    multimap<string, string> courses;
    //1.由于“multimap<string, string>::iterator”在之后会多次用到，因此把它定义为mapiter，便于之后的使用。
    typedef multimap<string, string>::iterator mapiter;

    courses.insert(make_pair("C++", "2-6"));
    courses.insert(make_pair("COMPILER", "3-1"));
    courses.insert(make_pair("COMPILER", "5-2"));    
    courses.insert(make_pair("OS", "1-2"));
    courses.insert(make_pair("OS", "4-1"));
    courses.insert(make_pair("OS", "5-5"));
    
    string name;
    mapiter found;    
    cout << "Please input the course name: ";
    do
    {
        cin >> name;
        found = courses.find(name);
        if(found == courses.end())
        {
            cout << "can not find that course!" << endl;
        }
        else
        {
            //2.对于多重映射或多重集合而言，用.equal_range(k)可以返回一个由键k的起始位置迭代器和终止位置加一的迭代器构成的pair。
            pair<mapiter, mapiter> range = courses.equal_range(name);
            mapiter iter = range.first;
            //2.此时，iter->first就是筛选出的、存放在courses中的元素的课程名。
            cout << courses.count(name) << " lesson(s) found. " << iter->first << ": ";
            while(iter != range.second)
            {
                //2.iter->first就是课程的上课时间。由于同一课程名对应range内的多个不同时间，因此要用迭代器将其全部输出。
                cout << iter++->second << " ";                
            }
        }
    //0.如果映射中未找到输入的课程名，则程序一直循环。
    } while(found == courses.end());
}
