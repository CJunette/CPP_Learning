// Experiment_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;

int main()
{
    //setw()是设置域宽。如果后面的输出值的字节长度小于设置值，则在输出值前输出差值数的空格；如果后面的输出值字节长度大于设置值，则不调整。
    cout << setw(5) << setprecision(3) << 3.141592689 << endl;    

    cout << endl;

    cout << "The size of an int is\t\t" << sizeof(int) << " bytes.\n";
    cout << "The size of an short is\t\t" << sizeof(short) << " bytes.\n";
    cout << "The size of an long is\t\t" << sizeof(long) << " bytes.\n";
    cout << "The size of an char is\t\t" << sizeof(char) << " bytes.\n";
    cout << "The size of an float is\t\t" << sizeof(float) << " bytes.\n";
    cout << "The size of an double is\t" << sizeof(double) << " bytes.\n";

    cout << endl;

    unsigned int x;
    unsigned int y = 100;
    unsigned int z = 50;
    x = y - z;
    cout << "The difference is \t" << x << endl;
    x = z - y;
    //差值为负但数据类型为“unsigned”，因此会出现输出错误。
    cout << "Now the difference is \t" << x << endl;
    cout << "x in binary is " << bitset<sizeof(x) * 8>(x) << "." << endl;
    
    cout << endl;

    int a, b, c;
    cout << "Please input the value of \"a\"." << endl;
    cin >> a;
    cout << "Please input the value of \"b\"." << endl;
    cin >> b;
    x = (a - b) > 0 ? a - b : b - a;
    cout << "The difference is " << x << endl;

}
