// 3.3_005.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

double Sin(double x);
double Power(double a, int n);
double Factorial(int x);


int main()
{    
    double r, s;
    cout << "Please input a number for r.\n";
    cin >> r;
    cout << "Please input a number for s.\n";
    cin >> s;

    if ( r*r <= s*s )
    {
        cout << "k = " << sqrt(Sin(r) * Sin(r) + Sin(s) * Sin(s)) << endl;
    }
    else
    {
        cout << "k = " << 0.5 * sin(r * s) << endl;
    }
}

double Power(double a, int n)
{
    double result = 1;
    for ( int i = 1; i <= n; i++ )
    {
        result *= a;
    }
    return result;
}

double Sin(double x)
{
    /*
	double item;
    double sum = 0;
    int minusPower = 0;
    int n = 1;
	do
	{        
        item = Power(x, n) / Factorial(n);
        //注意这边不能把-1写到item里，不然会因为item变成负数而提前退出循环。
        sum += Power(-1, minusPower) * item;
        n += 2;
        minusPower += 1;
	} while ( item >= 1e-10 );
    */

    //这里有另一种基于通项公式的写法。
    double sum = 0;
    double item = x;
    double n = 2;
    do
    {
        sum = sum + item;
        item = -1 * item * x * x / (2 * n - 2) / (2 * n - 1);
        n++;
    //fabs()是取绝对值。
    } while ( fabs(item) >= 1e-10 );

    return sum;
}

double Factorial(int x)
{
    double result = 1;
    for ( int i = 1; i <= x; i++ )
    {
        result *= i;
    }
    return result;
}