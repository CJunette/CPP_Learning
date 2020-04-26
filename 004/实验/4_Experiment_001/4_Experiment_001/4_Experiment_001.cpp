// 4_Experiment_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

enum CPU_Rank{ P1 = 1, P2, P3, P4, P5, P6, P7 };

class CPU
{
    public:
    CPU(CPU_Rank rk, double fre, double vol) :
        rank(rk), frequency(fre), voltage(vol)
    {
        cout << "Create a CPU.\n";
    }
    ~CPU()
    {
        cout << "Destroy a CPU.\n";
    }

    const CPU_Rank getRank() { return rank; }
    const double getFrequency() { return frequency; }
    const double getVoltage() { return voltage; }

    void run()
    {
        cout << "CPU starts running.\n";
    }
    void stop()
    {
        cout << "CPU stops running.\n";
    }

    private:
    CPU_Rank rank;
    double frequency, voltage;
};

int main()
{
    CPU a(P6, 300, 2.8);
    a.run();
    a.stop();

    //析构函数会在return语句执行之前被执行。
    return 0;
}

