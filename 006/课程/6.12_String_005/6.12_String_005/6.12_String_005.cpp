// 6.12_String_005.cpp : This file contains the 'main' function. Program execution begins and ends there.
//getline()的一个具体例子。

#include <iostream>
#include <string>
using namespace std;

int main()
{
    for (int i = 0; i < 2; i++)
    {
        cout << "Please input: City Name, Country Name" << endl;
        string city, country;
        getline(cin, city, ',');
        getline(cin, country);
        cout << "City: " << city << "\tCountry: " << country << endl;
    }
}
