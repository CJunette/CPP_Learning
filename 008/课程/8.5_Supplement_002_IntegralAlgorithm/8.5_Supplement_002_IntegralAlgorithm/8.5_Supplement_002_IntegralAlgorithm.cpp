// 8.5_Supplement_002_IntegralAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//重写一下变步长梯形积分算法求解定积分的程序。

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Function
{
    public:
    virtual double operator()(double x) const = 0;
};

class MyFunction: public Function
{
    public:
    virtual double operator()(double x) const;
};
double MyFunction::operator()(double x) const
{
    return log(1 + x) / (1 + x * x);
}

class Integration
{
    public:
    virtual double operator()(double a, double b, double eps) = 0;
};

class Trapz: public Integration
{
    public:
    Trapz(Function const &f);
    double operator()(double a, double b, double eps);
    Function const &pf;
    int n;
    private:
    double lastIntegral, thisIntegral;    
    double calcIntegral(double a, double b, double h, double eps);
};
Trapz::Trapz(Function const &f):
    pf(f), n(1), lastIntegral(0), thisIntegral(0)
{}
double Trapz::operator()(double a, double b, double eps)
{
    double h = b - a;
    lastIntegral = (pf(a) + pf(b)) * h / 2;
    return calcIntegral(a, b, h, eps);
}
double Trapz::calcIntegral(double a, double b, double h, double eps)
{
    thisIntegral = 0;
    for(int i = 0; i < n; i++)
    {
        double x = a + h * (i + 0.5);
        thisIntegral += pf(x) * h / 2;
    }
    thisIntegral += lastIntegral / 2;
    if(fabs(thisIntegral - lastIntegral) < eps)
    {
        return thisIntegral;
    }
    else
    {
        lastIntegral = thisIntegral;
        n *= 2;
        //用递归的方法解决这个问题。
        thisIntegral = calcIntegral(a, b, h / 2, eps);
        return thisIntegral;
    }
}


int main()
{
    MyFunction f;
    Trapz trapz(f);
    cout << setprecision(7) << trapz(0, 2, 1e-7) << endl;
    //因为我暂时找不到自定义底数的log，所以用了换底公式求log(2, n)。
    cout << "it takes " << log(trapz.n)/log(2) << " step(s)." << endl;

}