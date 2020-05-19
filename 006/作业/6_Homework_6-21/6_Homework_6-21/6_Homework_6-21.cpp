// 6_Homework_6-21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Please input a sentence:" << endl;
    string s;
    getline(cin, s);
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            count++;
        }
    }
    cout << "There are " << count << " English letters." << endl;
}
