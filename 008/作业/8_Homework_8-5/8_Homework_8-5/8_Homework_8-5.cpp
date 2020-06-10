// 8_Homework_8-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Mammal
{
    public:
    virtual void speak() const { cout << "Mammal speaks" << endl; }
};

class Dog: public Mammal
{
    public:
    virtual void speak() const { cout << "Dog speaks" << endl; }
};

int main()
{
    Dog d;
    d.speak();
}
