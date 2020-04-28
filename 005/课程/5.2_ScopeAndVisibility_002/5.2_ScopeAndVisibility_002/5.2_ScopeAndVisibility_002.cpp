// 5.2_ScopeAndVisibility_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int i;

int main()
{
    i = 5;
    {
        //作用域在最靠近的大括号所构成的范围中。
        //在外层有变量i的情况下，内层再次声明变量，导致外层的变量可见性变为“不可见”。
        int i = 7;
        cout << "i = " << i << endl;
    }
    //当内层作用域结束后，内层变量i消失。而本层也没有在声明新的变量i。因此外层变量i的可见性是“可见”。
    cout << "i = " << i << endl;
}

