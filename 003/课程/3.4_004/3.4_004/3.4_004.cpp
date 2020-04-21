// 3.4_004.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int Step = -1;
enum Stick{A, B, C};

class Plate
{
    public: int num;
    public: Stick current;
};

int Hanoi(int n);
int Count(int n);
void Paint(int n, Plate* plate);
void HanoiMove(int n, int paintIndex,  Plate* plate, Stick target);

int main()
{
    cout << "Please input a number: ";
    int n;
    cin >> n;   
    cout << "It takes " << Hanoi(n) << " steps.\n";
}


int Hanoi(int n)
{
    Plate *plate = new Plate[n];
    for ( int i = 0; i < n; i++ )
    {
        plate[i].current = A;
        plate[i].num = i;
    }
    Paint(n, plate);
    HanoiMove(n-1, n, plate, C);

    cout << endl;
    return Count(n);
}

int Count(int n)
{
    if ( n == 1 )
    {
        return 1;
    }
    else
    {
        return Count(n - 1) * 2 + 1;
    }
}

void Paint(int n, Plate *plate)
{
    int a = 0, b = 0, c = 0;
    for ( int i = 0; i < n; i++ )
    {
        switch ( plate[i].current )
        {
            case A:
                a++;
                break;
            case B:
                b++;
                break;
            case C:
                c++;
                break;
        }
    }
    
    int a_record = 0, b_record = 0, c_record = 0;

    for ( int i = 0; i < n; i++ )
    {
        if ( a < n )
        {
            //输出前n-a行空行
            a++;
            cout << "___\t";
        }
        else
        {
            for ( int j = a_record; j < n; j++ )
            {
                if ( plate[j].current == A )
                {
                    cout << '_' << plate[j].num << '_' << "\t";
                    a_record = j + 1;
                    break;
                }
            }
        }

        if ( b < n )
        {
            b++;
            cout << "___\t";
        }
        else
        {
            for ( int j = b_record; j < n; j++ )
            {
                if ( plate[j].current == B )
                {
                    cout << '_' << plate[j].num << '_' << "\t";
                    b_record = j + 1;
                    break;
                }
            }
        }

        if ( c < n )
        {
            c++;
            cout << "___\t";
        }
        else
        {
            for ( int j = c_record; j < n; j++ )
            {
                if ( plate[j].current == C )
                {
                    cout << '_' << plate[j].num << '_' << "\t";
                    c_record = j + 1;
                    break;
                }
            }
        }
        cout << endl;

    }
        
    cout << "*******STEP " << ++Step << "*******" << endl;
}

void HanoiMove(int n, int paintIndex, Plate* plate, Stick target)
{
    if ( n < 0 )
    {
    }
    else if ( n == 0 )
    {
        plate[n].current = target;
        Paint(paintIndex, plate);
    }
    else
    {
        Stick formertarget;
        //根据现在的n所在位置与下一步要去的位置，确定0~n-1应该的上一步移动到的位置。
        switch ( plate[n].current )
        {
            case A:
                target == C ? formertarget = B : formertarget = C;
                break;
            case B:
                target == A ? formertarget = C : formertarget = A;
                break;
            case C:
                target == B ? formertarget = A : formertarget = B;
                break;
        }
        
        HanoiMove(n - 1, paintIndex, plate, formertarget);
        plate[n].current = target;
        Paint(paintIndex, plate);
        HanoiMove(n - 1, paintIndex, plate, target);        
    }    
}