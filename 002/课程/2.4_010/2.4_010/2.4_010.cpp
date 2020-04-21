// 2.4_010.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<bitset>
using namespace std;

int main()
{
    short a = -1;
    unsigned short b = 65535;
    cout << bitset<16>(a) << endl;
    cout << bitset<16>(b) << endl;

    //一般情况的符号位扩展。
    int c, d;
    c = a;
    d = b;
    cout << bitset<32>(c) << endl;
    cout << bitset<32>(d) << endl;

    //“unsigned”类型数据的零扩展。
    unsigned int e, f;
    e = a;
    f = b;
    cout << bitset<32>(e) << endl;    
    cout << bitset<32>(f) << endl;

    cout << endl;

    unsigned int i = 4294967295;
    int j = -1;
    cout << bitset<32>(i) << endl;
    cout << bitset<32>(j) << endl;
    long long  k, l;
    k = i;
    l = j;
    cout << k << endl;
    cout << l << endl;

    cout << bitset<64>(k) << endl;
    cout << bitset<64>(l) << endl;

}

