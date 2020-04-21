// 3.12_SystemFunction_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//An example of system function.
#include <iostream>
#include <cmath>
using namespace std;

float const PI = 3.14159265358979;

int main()
{
    cout << "Please input an angle value: ";
    //输入角度值。
    float angle;
    cin >> angle;
    //sin()、cos()、tan()都是弧度制的，因此要将角度转换成弧度。
    float radian = angle / 180 * PI;
    cout << "sin(" << angle << ") = " << sin(radian) << endl;
    cout << "cos(" << angle << ") = " << cos(radian) << endl;
    cout << "tan(" << angle << ") = " << tan(radian) << endl;
}

