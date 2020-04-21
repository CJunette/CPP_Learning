// 3.3_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

double Arctan(double x);
double Power(double a, int n);
double Pi();

int main()
{
    cout << "Pi is " << Pi();    
}

double Arctan(double x)
{
    double sum = 0;
    double n = 1;
    int minusOnePower = 0;
    double item;
    do
    {
        double p = Power(x, (int)n);
        item = p / n;
        n += 2;
        sum += item * Power(-1, minusOnePower);
        minusOnePower += 1;
    } while ( item > 10E-15 );

    return sum;
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

double Pi()
{
    //注意这里一定要用1.0/5，不然会被当成int类型做除法，用0去传入Arctan()。
    return 16 * Arctan(1.0 / 5) - 4 * Arctan(1.0 / 239);
}