// 8.5_Supplement_001_IntegralAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

class Function
{
    public:
    virtual double operator()(double) const = 0;
};

class MyFunction: public Function
{
    public:
    double operator()(double x) const;
};
double MyFunction::operator()(double x) const
{
    return log(1 + x) / (1 + x * x);
}

class Integration
{
    public:
    virtual double operator()(double a, double b, double eps) const = 0;    
};

class Trapz: public Integration
{
    public:
    Trapz(Function const & f);
    double operator()(double a, double b, double eps) const;

    private:    
    const Function &pf;
};
Trapz::Trapz(Function const & f):
    pf(f)
{}

double Trapz::operator()(double a, double b, double eps) const
{
    int n = 1;
    double lastIntegral;
    double thisIntegral = 0;
    double h = (b - a) / n;

    if(n == 1)
    {
        lastIntegral = (pf(a) + pf(b)) * (b - a) / 2;
    }
    
    n = n * 2;
    h = h / 2;
    //用循环的方式解决问题。
    do
    {
        for(int i = 0; i < n; i++)
        {
            if(i % 2 != 0)
            {
                double x = a + (b - a) / n * i;
                thisIntegral += pf(x) * h;
            }
        }

        thisIntegral += lastIntegral * 0.5;

        if(fabs(lastIntegral - thisIntegral) < eps)
        {
            break;
        }
        else
        {
            n *= 2;
            h /= 2;
            lastIntegral = thisIntegral;
            thisIntegral = 0;
        }
    } while(true);

    return thisIntegral;
}


int main()
{
    MyFunction f;
    Trapz trapz(f);
    cout << setprecision(7) << trapz(0, 2, 1e-7) << endl;
}

