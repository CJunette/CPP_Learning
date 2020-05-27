// 7_Experiment_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Vehicle
{
    public:
    void run() { cout << "Vehicle run" << endl; }
    void stop() { cout << "Vehicle stop" << endl; }
    double maxSpeed, weight;    
};

class Bicycle: virtual public Vehicle
{
    public:
    double height;    
};

class Motorcar: virtual public Vehicle
{
    public:
    int seatNum;    
};

class Motorcycle: public Bicycle, public Motorcar
{    
};

int main()
{
    Motorcycle m;
    m.height = 1;
    m.seatNum = 2;
    m.weight = 100;
    m.maxSpeed = 60;
    m.run();
    m.stop();
}
