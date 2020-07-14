// 11_Homework_11-8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "Please input a number: ";
    int a;
    cin >> a;
    cout << "Dec: " << a << endl;
    cout << "Oct: " << resetiosflags(ios_base::dec) << setiosflags(ios_base::oct | ios_base::uppercase) << a << endl;
    cout << "Hex: " << resetiosflags(ios_base::oct) << setiosflags(ios_base::hex | ios_base::uppercase) << a << endl;
}