// 7_Experiment_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Animal
{
    public:
    int age;
    private:
};

class Dog: public Animal
{
    public:
    void setAge(int n) { age = n; }
    private:
};

int main()
{
    Dog d;
    d.setAge(2);
}
