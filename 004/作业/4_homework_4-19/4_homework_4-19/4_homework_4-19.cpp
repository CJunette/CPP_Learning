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
    //注意，这里在不写unsigned的情况下，必须要13位才能保证3000能被包含在其中。范围是-(2^12)~(2^12)-1
    int clockFrequency : 13;
    //对于enum类型，有几种情况这里的数字就写几。这里和书上的说法不同，可能是C++版本不同造成的，也可能是编译环境不同造成的。
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

