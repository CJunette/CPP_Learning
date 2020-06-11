// 8_Homework_8-9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Base
{
    public:
    Base()
    {
        cout << "Base Constructor" << endl;
    }
    virtual ~Base() = 0;
};
Base::~Base()
{
    cout << "Base Destructor" << endl;
}

class Derived: public Base
{
    public:
    Derived()
    {
        cout << "Derived Constructor" << endl;
    }
    virtual ~Derived()
    {
        cout << "Derived Destructor" << endl;
    }
};

int main()
{
    Base *pb = new Derived;
    cout << endl;
    delete pb;
}
