// 5.7_MultiFilesAndPrecompileCommand_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "point.h"
using namespace std;

int main()
{
    Point a(4, 5);
    cout << "Point A: " << a.getX() << "," << a.getY() << endl;
    Point::showCount();

    Point b(a);
    cout << "Point B: " << b.getX() << "," << b.getY() << endl;
    Point::showCount();
    
    countChange();
}
