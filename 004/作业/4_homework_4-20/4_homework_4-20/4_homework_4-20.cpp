// 4_homework_4-20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Complex
{
    public:
    Complex(double r = 0, double i = 0)
    {
        real = r;
        imaginary = i;
    }

    void add(Complex c)
    {
        real += c.real;
        imaginary += c.imaginary;
    }

    void show()
    {
        cout << real << " + " << imaginary << "i" << endl;
    }

    private:
    double real, imaginary;
};

int main()
{
    Complex c1(3, 5);
    Complex c2 = 4.5;
    c1.add(c2);
    c1.show();
}
