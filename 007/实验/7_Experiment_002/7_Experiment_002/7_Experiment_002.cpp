// 7_Experiment_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class BaseClass
{
    public:
    BaseClass()
    {
        cout << "BaseClass Constructor." << endl;
    }
    ~BaseClass()
    {
        cout << "BaseClass Destructor." << endl;
    }
    int Number;
    int getNumber() { return Number; }    
};

class DerivedClass: public BaseClass
{
    public:
    DerivedClass()
    {
        Number = 0;
        Number++;
        cout << "DerivedClass Constructor. Number = " << getNumber() << endl;
    }
    ~DerivedClass()
    {
        Number--;
        cout << "DerivedClass Destructor. Number = " << getNumber() << endl;
    }

    private:

};

int main()
{
    DerivedClass d;
}

