// 2.4_005.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Please input an integer: \n";
    cin >> n;
    cout << "Number " << n << " factor: \n";

    for ( int i = 1; i < n; i++ )
    {
        if ( n % i == 0 )
        {
            cout << i << " ";
        }
    }

    cout << endl;
    
}
