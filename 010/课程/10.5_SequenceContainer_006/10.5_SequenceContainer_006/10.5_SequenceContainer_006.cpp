// 10.5_SequenceContainer_006.cpp : This file contains the 'main' function. Program execution begins and ends there.
//利用栈，实现单词的反向输出。

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> s;
    string str;
    cin >> str;
    for(string::iterator i = str.begin(); i != str.end(); i++)
    {
        s.push(*i);
    }
    while(!s.empty())
    {
        //注意，这里pop()是没有返回值的，因此需要先用top()查看栈顶元素，然后弹出。
        cout << s.top();        
        s.pop();
    }
    cout << endl;
}