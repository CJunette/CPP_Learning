// 12_Homework_12-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Exception
{
    Exception() {}
    ~Exception() {}
    void virtual printError() const = 0;
};

struct OutOfMemory: public Exception
{
    OutOfMemory() {}
    ~OutOfMemory() {}
    void virtual printError() const override { cout << "Error: Out of memory!" << endl; }
};

struct RangeError: public Exception
{
    RangeError(unsigned int num):badNum(num) {}
    ~RangeError() {}
    void virtual printError() const override { cout << "Error: Range error! You used " << badNum  << endl; }
    unsigned int badNum;
};

void f1();
unsigned int *f2();
void f3(unsigned int *);

int main()
{    
    try
    {
        f1();
    }
    catch(const Exception &e)
    {
        e.printError();
    }
}

unsigned int *f2()
{
    unsigned int *p = new unsigned int;
    if(p == 0)
    {
        throw OutOfMemory();
    }
    return p;
}

void f1()
{
    unsigned int *p = f2();
    f3(p);
    cout << "The number is " << *p << endl;
    delete p;
}

void f3(unsigned int *p)
{
    int n;
    cout << "Enter an integer(0~1000): ";
    cin >> n;
    if(n < 0 || n > 1000)
    {
        throw RangeError(n);
    }
    *p = n;
}