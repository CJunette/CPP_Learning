// 6_Experiment_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int **a;
    a = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        a[i] = new int[3];
    }

    cout << "Please input 9 numbers: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "The origin matrix is " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << '\t';
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            swap(a[i][j], a[j][i]);
        }
    }
    cout << "The matrix after transposition " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << '\t';
        }
        cout << endl;
    }
}
