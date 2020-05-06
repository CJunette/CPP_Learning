// 5_Homework_5-14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Car;

class Boat
{
    public:
    Boat(double w)
    {
        weight = w;
    }

    private:
    double weight;
    friend double getTotalWeight(Boat b, Car c);
};

class Car
{
    public:
    Car(double w)
    {
        weight = w;
    }

    private:
    double weight;
    friend double getTotalWeight(Boat b, Car c);
};

double getTotalWeight(Boat b, Car c)
{
    return b.weight + c.weight;
}

int main()
{
    cout << getTotalWeight(Boat(3), Car(1.5)) << endl;
}

