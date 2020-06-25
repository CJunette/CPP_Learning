// 9_Homework_9-18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template<class T, size_t N>
bool binaSearch(T(&a)[N], T key)
{
    int min = 0, max = N - 1;
    int mid;
    int count = 1;
    while(true)
    {
        mid = (min + max) / 2;
        if(a[mid] == key)
        {
            cout << "Found! [" << mid << "]" << " = " << a[mid] << endl;
            return true;
        }
        if(a[mid] > key)
        {
            max = mid;
        }
        else
        {
            min = mid;
        }
        if(max == min + 1)
        {
            if(a[max] == key)
            {
                cout << "Found! [" << max << "]" << " = " << a[max] << endl;
                return true;
            }
            else if(a[min] == key)
            {
                cout << "Found! [" << min << "]" << " = " << a[min] << endl;
                return true;
            }
            else
            {
                return false;
            }
        }        
        cout << "Step: " << count << " : \t";
        for(int k = 0; k < min; k++)
        {
            cout << "\t";

        }
        for(int k = min; k <= max; k++)
        {
            cout << a[k] << "\t";
        }
        for(int k = max + 1; k < N; k++)
        {
            cout << "\t";

        }
        cout << endl;
        count++;
    }
}

int main()
{
    int data1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    cout << "Origin array:   ";
    for(int k = 0; k < sizeof(data1) / sizeof(int); k++)
    {
        cout << data1[k] << "\t";
    }
    cout << endl << endl;

    cout << binaSearch(data1, 1) << endl;
    cout << endl;
    cout << binaSearch(data1, 20) << endl;
    cout << endl;
    cout << binaSearch(data1, 11) << endl;
}