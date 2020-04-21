// 2.4_007.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void Odd(int n);
void Even(int n);

int main()
{
    while ( true )
    {
        int n;
        cout << "Please input an integer: ";
        cin >> n;

        if ( n % 2 == 1 )
        {
            Odd(n);
        }
        else
        {
            Even(n);
        }
    }    
}

void Odd(int n)
{
    for ( int i = 1; i <= n; i += 2 )
    {
        for ( int j = 0; j < n-i; j++ )
        {
            cout << ' ';
        }
        for ( int j = 0; j < i; j++ )
        {
            cout << '*';
        }

        cout << endl;
    }
    for ( int i = n - 2; i > 0 ; i -= 2 )
    {
        for ( int j = 0; j < i; j++ )
        {
            cout << '*';
        }
        for ( int j = 0; j < n - i; j++ )
        {
            cout << ' ';
        }
        cout << endl;
    }
}

void Even(int n)
{
    for ( int i = 2; i <= n; i += 2 )
    {
        for ( int j = 0; j < n - i; j++ )
        {
            cout << ' ';
        }
        for ( int j = 0; j < i; j++ )
        {
            cout << '*';
        }

        cout << endl;
    }
    for ( int i = n - 2; i > 0; i -= 2 )
    {
        for ( int j = 0; j < i; j++ )
        {
            cout << '*';
        }
        for ( int j = 0; j < n - i; j++ )
        {
            cout << ' ';
        }
        cout << endl;
    }
}
