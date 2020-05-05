// 5.8_Supplement_007_ProtectionOfSharedData.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class A
{
    public:
    void change() const
    {
        //常函数是可以改变静态成员的值的。
        i++;
    }

    static int i;
    int j = 0;
};

int A::i = 0;

int main()
{
    A a;
    cout << a.i << endl;
    cout << a.j << endl;
    a.change();
    cout << a.i << endl;
    cout << a.j << endl;
}