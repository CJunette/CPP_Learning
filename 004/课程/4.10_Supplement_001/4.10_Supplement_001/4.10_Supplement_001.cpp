// 4.10_Supplement_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

double PI = 3.141592635898;

class Circle
{
    public:
    Circle(double rad) :
        radius(rad)
    {
        perimeter = 2 * PI * radius;
        area = PI * radius * radius;
    }
    Circle() :
        Circle(0)
    {}    
    double getArea() { return area; }
    double getPerimeter() { return perimeter; }

    private:
    double radius;
    double perimeter;
    double area;
};


int main()
{
    double originRadius;
    cout << "Please input the origin radius of the pool: ";
    cin >> originRadius;
    Circle pool(originRadius);
    Circle newPool(originRadius + 3);

    double fencePrice = newPool.getPerimeter() * 35;
    double aislePrice = (newPool.getArea() - pool.getArea()) * 20;

    cout << "The price for fence is " << fencePrice << ".\n";
    cout << "The price for aisle is " << aislePrice << ".\n";
}

