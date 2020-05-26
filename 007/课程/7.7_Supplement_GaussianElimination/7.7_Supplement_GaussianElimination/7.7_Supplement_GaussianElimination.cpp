// 7.7_Supplement_GaussianElimination.cpp : This file contains the 'main' function. Program execution begins and ends there.
//书上p279的程序练习。
//稍作了一些调整，书上matrix类中的数组用的是一元数组，我用来指针数组来充当二元数组。
//因此程序也有些许不同。

#include <iostream>
#include "linearEqu.h"
#include "matrix.h"
using namespace std;

int main()
{
    //注释掉的代码是试验功能用的。
    /*
    LinearEqu le(2);

    double a[4] = { 1, 1, 2, 1 };
    double b[2] = { 3, 4 };
    
    le.setLinearEqu(a, b);
    le.printLinearEqu();
    le.printMatrix();

    LinearEqu le2(le);
    le2.printLinearEqu();

    cout << endl;
    le.swapColumn(0, 1);
    le.printLinearEqu();
    cout << endl;
    le.swapRow(0, 1);
    le.printLinearEqu();

    cout << endl;
    le.swapInLE(0, 1);
    le.printLinearEqu();
    */

    /*
    LinearEqu le(3);

    double a[9] = { 1, 1, 1, 2, 1, 1, 1, 3, 1 };
    double b[3] = { 6, 7, 10 };

    le.setLinearEqu(a, b);
    le.printLinearEqu();
    cout << endl;
    
    if(le.solve())
    {
        le.printSolution();
    }
    */

    LinearEqu le(4);
    double a[16] = {
        0.2368, 0.2471, 0.2568, 1.2671,
        0.1968, 0.2071, 1.2168, 0.2271,
        0.1581, 1.1675, 0.1768, 0.1871,
        1.1161, 0.1254, 0.1397, 0.149 };
    
    double b[4] = { 1.8471, 1.7471, 1.6471, 1.5471};

    le.setLinearEqu(a, b);
    le.printLinearEqu();    
    cout << endl;

    if(le.solve())
    {
        le.printSolution();
    }
    else
    {
        cout << "Unique solution does not exist." << endl;
    }
    
    //下面是一个方程组不存在唯一解的情况。
    /*
    LinearEqu le(3);
    double a[9] = { 1, 1, 1, 2, 2, 2, 3, 3, 3 };
    double b[3] = { 6, 12, 18 };
    
    le.setLinearEqu(a, b);
    le.printLinearEqu();
    cout << endl;
    
    if(le.solve())
    {
        le.printSolution();
    }
    else
    {
        cout << "Unique solution does not exist." << endl;
    }
    */
}

