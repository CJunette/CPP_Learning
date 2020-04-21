// 3.3_004.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iomanip>
using namespace std;

int Power(int a, int n)
{
    int result = 1;
    for ( int i = 1; i <= n; i++ )
    {
        result *= a;
    }
    return result;
}

bool Check(unsigned int x);

int main()
{
    //注意这里是<=！！！
    for ( int i = 11; i <= 999; i++ )
    {
        //这里直接写m，m*m，m*m*m就好，会更简洁。
        if ( Check(i) && Check(Power(i, 2)) && Check(Power(i, 3)) )
        {
            cout << i << " \t" << Power(i, 2) << " \t" << Power(i, 3) << "\t" << endl;
        }
    }
}

bool Check(unsigned int x)
{
    unsigned int store = x;
    unsigned int remainder = 0;
    unsigned int reverse = 0;

    while ( x != 0 )
    {
        remainder = x % 10;
        reverse = reverse * 10 + remainder;
        x /= 10;
    }

    /*
    if ( reverse == store )
    {
        return true;
    }
    else
    {
        return false;
    }
    */

    //老师提供的这个return思路更加简洁。
    return reverse == store;
}