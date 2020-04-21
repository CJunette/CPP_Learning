// 3.8_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{    
    //C++中的Lambda表达式
    auto add = [](int a, int b) -> int {return a + b; };
    
    cout << add(1, 2) << endl;
}

