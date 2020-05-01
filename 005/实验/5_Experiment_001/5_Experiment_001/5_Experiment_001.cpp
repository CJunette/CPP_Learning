// 5_Experiment_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int x = 1, y = 2;

//2.对于没有形参的全局函数，如果函数内涉及全局变量的话，只要这个全局函数的作用域内没有创建与全局变量同名的变量，就不会发生全局变量不可见的情况。
void fun1()
{
    int y = 100;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

int main()
{
    cout << "Begin..." << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    cout << "Evaluate x and y in main()..." << endl;
    int x = 10, y = 20;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    cout << "Step into fun1()..." << endl;
    //1.注意，在这里，虽然主函数中已经定义了一个新的变量x，但是fun1()调用的仍然是全局变量x。
    fun1();

    cout << "Back in main()..." << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    
    cout << "Scope in main()..." << endl;
    {
        //3.此时，由于不是依靠全局函数调用全局变量，因此调用的变量再次变成了外层修改过的局部变量。
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }

    return 0;
}
