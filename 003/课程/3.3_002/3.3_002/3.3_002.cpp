// 3.3_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int Power(int a, int n)
{
    int result = 1;
    for ( int i = 1; i <= n; i++ )
    {
        result *= a;
    }
    return result;
}

int main()
{
    //Do loop after input.
    /*
    int binNumber;
    cout << "Please input a binary number: ";
    cin >> binNumber;

    int decNumber = 0;
    int digit = 0;

    while ( binNumber != 0 )
    {
        if ( binNumber % 10 > 1 )
        {
            cout << "Wrong input!";
            goto end;
        }
        decNumber += binNumber % 10 * Power(2, digit);
        binNumber /= 10;
        digit += 1;
    }

    cout << decNumber << endl;
end:
    return 0;
    */

    //Do loop while inputing.

    cout << "Please input an 8-digits binary number: ";
    int decNumber = 0;
    
    //输入从左侧开始，即从高位开始。
    for ( int i = 7; i >= 0; i-- )
    {
        char ch;
        cin >> ch;
        int c = static_cast<int>(ch) - 48;
        decNumber += c * Power(2, i);
    }
    cout << "The corresponding decimal number is " << decNumber;
    

}
