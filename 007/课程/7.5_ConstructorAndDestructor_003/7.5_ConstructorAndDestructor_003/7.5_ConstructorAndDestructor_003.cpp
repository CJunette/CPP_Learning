// 7.5_ConstructorAndDestructor_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//派生类的析构函数

#include <iostream>
using namespace std;

class Base1
{
    public:
    Base1(int b1 = 0):base1(b1) { cout << "Calling Base1 constructor..." << endl; }
    Base1(const Base1 &b1): base1(b1.base1) { cout << "Calling Base1 copy constructor..." << endl; }
    ~Base1() { cout << "Calling Base1 destructor..." << endl; }
    private:
    int base1;
};

class Base2
{
    public:
    Base2(int b2 = 2):base2(b2) { cout << "Calling Base2 constructor..." << endl; }
    Base2(const Base2 &b2): base2(b2.base2) { cout << "Calling Base2 copy constructor..." << endl; }
    ~Base2() { cout << "Calling Base2 destructor..." << endl; }
    private:
    int base2;
};

class Member1
{
    public:
    Member1(int m1 = 3):member1(m1) { cout << "Calling Member1 constructor..." << endl; }
    Member1(const Member1 &m1): member1(m1.member1) { cout << "Calling Member1 copy constructor..." << endl; }
    ~Member1() { cout << "Calling Member1 destructor..." << endl; }
    private:
    int member1;
};

class Member2
{
    public:
    Member2(int m2 = 4):member2(m2) { cout << "Calling Member2 constructor..." << endl; }
    Member2(const Member2 &m2): member2(m2.member2) { cout << "Calling Member2 copy constructor..." << endl; }
    ~Member2() { cout << "Calling Member2 destructor..." << endl; }
    private:
    int member2;
};

class Derived: public Base1, public Base2
{
    public:
    Derived(int b1 = 1, int b2 = 2, int m1 = 3, int m2 = 4, int d = 5):
        derived(d), Base1(b1), Base2(b2), member1(Member1(m1)), member2(Member2(m2))
    {
        cout << "Calling Derived constructor..." << endl;
    }
    Derived(const Derived &drv): derived(drv.derived), member1(drv.member1), member2(drv.member2) , Base1(drv), Base2(drv)
    { 
        cout << "Calling Derived copy constructor..." << endl; 
    }
    ~Derived() { cout << "Calling Derived destructor..." << endl; }
    private:
    int derived;
    Member1 member1;
    Member2 member2;
};

int main()
{
    Derived d1(1, 2, 3, 4, 5);
    cout << endl;
    Derived d2(d1);
    cout << endl;
}