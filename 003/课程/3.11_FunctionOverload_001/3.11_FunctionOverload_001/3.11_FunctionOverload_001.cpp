// 3.11_FunctionOverload_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//An example of function overload.
#include <iostream>
using namespace std;

int sumOfSquare(int a, int b)
{
    return a * a + b * b;
}

//虽然返回值类型不是函数重载的区分条件，但是如果返回值类型与输入的参数及想要达到的功能所需的值类型不符的话，很有可能会带来很难排查出错误源的bug。
//因此这里一定要注意！！
double sumOfSquare(double a, double b)
{
    return a * a + b * b;
}

int main()
{
    int a, b;
    cout << "Please input 2 integer number:\n";
    cin >> a >> b;
    cout << "The sum of square is " << sumOfSquare(a, b) << ".\n" << endl;

    double  c, d;
    cout << "Please input 2 real number:\n";
    cin >> c >> d;
    cout << "The sum of square is " << sumOfSquare(c, d) << ".\n" << endl;

    //下列程序编译器会报错，错误是没有对应的函数重载。
    //当函数本身限定了形参的数据类型时，传入的实参如果类型与要求不符就会直接报错，而不是进行强制类型转换。
    /*
    int e;
    double f;    
    sumOfSquare(e, f);
    */
}
