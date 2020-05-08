#pragma once

#include <iostream>
#include "Point.h"
using namespace std;

Point::Point() :
	x(0), y(0)
{
	cout << "Calling Default Constructor." << endl;
}

Point::Point(int x, int y) :
	x(x), y(y)
{
	cout << "Calling Constructor." << endl;
}

Point::~Point()
{
	cout << "Calling Destructor." << endl;
}

void Point::move(int newX, int newY)
{
	cout << "Moveing point to (" << newX << ", " << newY << ")" << endl;
	x = newX;
	y = newY;
}