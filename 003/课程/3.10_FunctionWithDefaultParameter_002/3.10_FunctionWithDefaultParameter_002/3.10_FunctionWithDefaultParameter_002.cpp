// 3.10_FunctionWithDefaultParameter_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//An example of function with default parameter.
#include <iostream>
#include <iomanip>
using namespace std;

int getVolume(int length, int width = 2, int height = 3);
int setwidth = 4;

int main()
{
    int x = 10, y = 12, z = 15;
    cout << "Box 1:\n";
    cout << setw(setwidth) << getVolume(x, y, z) << ".\n" << endl;
    cout << "Box 2:\n";
    cout << setw(setwidth) << getVolume(x, y) << ".\n" << endl;
    cout << "Box 3:\n";
    cout << setw(setwidth) << getVolume(x) << ".\n" << endl;

}

int getVolume(int length, int width, int height)
{
    cout << "Length: " << setw(setwidth) << length << ", Width: " << setw(setwidth) << width << ", Height: " << setw(setwidth) << height << ".\n";
    cout << "Volume: ";
    return length * width * height;
}