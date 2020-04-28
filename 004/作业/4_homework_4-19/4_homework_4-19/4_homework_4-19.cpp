// 4_homework_4-19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

enum ByteLength { Bit32, Bit64 };
enum Core {Un, Doux, Quatre};
enum HyperThreading { Support, NotSupport };

class CPU
{
    public:
    CPU(int cf = 3000, ByteLength bl = Bit64, Core c = Quatre, HyperThreading ht = Support)
    {
        clockFrequency = cf;
        byteLength = bl;
        core = c;
        hyperThreading = ht;
    }
    int getClockFrequency() { return clockFrequency; }
    ByteLength getByteLength() { return byteLength; }
    Core getCore() { return core; }
    HyperThreading getHyperThreading() { return hyperThreading; }
    void show()
    {
        cout << "ClockFrequency: " << clockFrequency << endl;
        
        cout << "ByteLength: ";
        switch (byteLength)
        {
            case Bit32:
                cout << "Bit32" << endl;
                break;
            case Bit64:
                cout << "Bit64" << endl;
                break;
            default:
                break;
        }

        cout << "Core: ";
        switch (core)
        {
            case Un:
                cout << "1" << endl;
                break;
            case Doux:
                cout << "2" << endl;
                break;
            case Quatre:
                cout << "4" << endl;
                break;
            default:
                break;
        }

        cout << "HyperThreading: ";
        switch (hyperThreading)
        {
            case Support:
                cout << "Support" << endl;
                break;
            case NotSupport:
                cout << "NotSupport" << endl;
                break;
            default:
                break;
        }
    }

    private:
    //这里可能是编译器的原因，必须把位数设置成正常值+1，才能正常容纳所需的样本。
    //如clockFrequency，实际能表示的整数是-(2^12)~(2^12)-1。ByteLength实际能表示的状态是2^1种。
    int clockFrequency : 13;
    ByteLength byteLength : 2;
    Core core : 3;
    HyperThreading hyperThreading : 2;
};

int main()
{
    CPU c(4095, Bit64, Quatre, NotSupport);
    cout << sizeof(c) << endl;
    c.show();
}

