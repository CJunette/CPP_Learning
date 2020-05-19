// 6_Homework_6-26.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int row, column;
    cout << "Please input row: ";
    cin >> row;
    cout << "Please input column: ";
    cin >> column;      

    int **matrix = new int *[row];

    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[column];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << "Please input element in row " << i << ", column " << j << ": ";
            cin >> matrix[i][j];
        }
    }
    cout << "The current matrix is" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    int **transpos = new int *[column];
    for (int i = 0; i < column; i++)
    {
        transpos[i] = new int[row];
    }
    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            transpos[i][j] = matrix[j][i];
        }
    }
    cout << "The matrix after transposition is" << endl;
    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << transpos[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    for (int i = 0; i < column; i++)
    {
        delete[] transpos[i];
    }
    delete[] transpos;

}
