// 8_Experiment_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Vehicle
{
    public:
    virtual void run() { cout << "Vehicle runs..." << endl; }
    virtual void stop() { cout << "Vehicle stops..." << endl; }
};

class Bicycle: virtual public Vehicle
{
    public:
    virtual void run() { cout << "Bicycle runs..." << endl; }
    virtual void stop() { cout << "Bicycle stops..." << endl; }
};

class Motocar: virtual public Vehicle
{
    public:
    virtual void run() { cout << "Motorcar runs..." << endl; }
    virtual void stop() { cout << "Motorcar stops..." << endl; }
};

class Motorcycle: public Bicycle, public Motocar
{
    public:
    virtual void run() { cout << "Motorcycle runs..." << endl; }
    virtual void stop() { cout << "Motorcycle stops..." << endl; }
};

int main()
{
    Vehicle v;
    v.run();
    v.stop();
    Bicycle b;
    b.run();
    b.stop();
    Motocar m;
    m.run();
    m.stop();
    Motorcycle mc;
    mc.run();
    mc.stop();
    cout << endl;

    Vehicle *pv = &v;
    pv->run();
    pv->stop();
    pv = &b;
    pv->run();
    pv->stop();
    pv = &m;
    pv->run();
    pv->stop();
    pv = &mc;
    pv->run();
    pv->stop();
}
