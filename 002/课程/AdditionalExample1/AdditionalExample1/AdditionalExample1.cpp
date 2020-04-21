// AdditionalExample1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int radius(0);
    double const pi(3.141592689);
    cout << "Please input an int for radius!" << '\n';
    cin >> radius;
    cout << "Now the radius is " << radius << "\n";
    cout << "PI is " << 3.14 << endl;
    cout << "Accurate PI is " << pi << endl;
    cout << "Please input another int for radius!" << endl;
    cin >> radius;
    cout << "Now the radius is changed to " << radius << endl;        
}
