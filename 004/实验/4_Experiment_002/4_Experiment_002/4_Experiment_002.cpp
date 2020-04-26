// 4_Experiment_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

enum class RAMType{DDR2 = 2, DDR3, DDR4};
enum class CDROMInterfaceType { SATA, USB };
enum class CDROMBuildType { external, built_in };
enum class CPURank { P1 = 1, P2, P3, P4, P5, P6, P7 };

class CPU
{
    public:
    CPU(CPURank rk, double fre, double vol) :
        rank(rk), frequency(fre), voltage(vol)
    {
        cout << "Create a CPU.\n";
    }
    CPU(CPU &cpu) :
        rank(cpu.rank), frequency(cpu.frequency), voltage(cpu.voltage)
    {
        cout << "Copy a CPU.\n";
    }
    ~CPU()
    {
        cout << "Destroy a CPU.\n";
    }

    const CPURank getRank() { return rank; }
    const double getFrequency() { return frequency; }
    const double getVoltage() { return voltage; }
    void setRank(CPURank r) { rank = r; }
    void setFrequency(double f) { frequency = f; }
    void setVoltage(double v) { voltage = v; }

    void run()
    {
        cout << "CPU starts running.\n";
    }
    void stop()
    {
        cout << "CPU stops running.\n";
    }

    private:
    CPURank rank;
    double frequency, voltage;
};

class RAM
{
    public:
    RAM(RAMType tp, double frq, double sz) :
        size(sz), frequency(frq), type(tp)
    {
        cout << "Create a RAM.\n";
    }
    RAM(RAM &rm) :
        size(rm.size), frequency(rm.frequency), type(rm.type)
    {
        cout << "Copy a RAM.\n";
    }
    ~RAM()
    {
        cout << "Destroy a RAM.\n";
    }

    const double getSize() { return size; }
    const double getFrequency() { return frequency; }
    const RAMType getType() { return type; }
    void setSize(double s) { size = s; }
    void setFrequency(double f) { frequency = f; }
    void setType(RAMType t) { type = t; }

    void run()
    {
        cout << "RAM starts running.\n";
    }
    void stop()
    {
        cout << "RAM stops running.\n";
    }

    private:
    double size, frequency;
    RAMType type;
};

class CDROM
{
    public:
    CDROM(CDROMInterfaceType itfc, CDROMBuildType bt):
        interface(itfc), buildType(bt)
    {
        cout << "Create a CDROM.\n";
    }
    CDROM(CDROM &cdrm) :
        interface(cdrm.interface), buildType(cdrm.buildType), cacheSize(cdrm.cacheSize)
    {
        cout << "Copy a CDROM.\n";
    }
    ~CDROM()
    {
        cout << "Destroy a CDROM.\n";
    }

    const double getCacheSize() { return cacheSize; }
    const CDROMInterfaceType getInterface() { return interface; }
    const CDROMBuildType getBuildType() { return buildType; }
    void setCacheSize(double cs) { cacheSize = cs; }
    void setInterface(CDROMInterfaceType it) { interface = it; }
    void setCDROMBuildType(CDROMBuildType bt) { buildType = bt; }

    void run()
    {
        cout << "CDROM starts running.\n";
    }
    void stop()
    {
        cout << "CDROM stops running.\n";
    }

    private:
    double cacheSize = 2;
    CDROMInterfaceType interface;
    CDROMBuildType buildType;
};

class Computer
{
    public:
    Computer(CPU c, RAM r, CDROM cd, unsigned int ss, unsigned int bw):
       cpu(c), ram(r), cdrom(cd), storageSize(ss), bandwith(bw)
    {
        cout << "Create a Computer.\n";
    }
    Computer(Computer &cpt) :
        cpu(cpt.cpu), ram(cpt.ram), cdrom(cpt.cdrom), storageSize(cpt.storageSize), bandwith(cpt.bandwith)
    {
        cout << "Copy a Computer.\n";
    }
    ~Computer()
    {
        cout << "Destroy a Computer.\n";
    }

    void run()
    {
        cpu.run();
        ram.run();
        cdrom.run();
        cout << "Computer starts running.\n";
    }
    void stop()
    {
        cpu.stop();
        ram.stop();
        cdrom.stop();
        cout << "Computer stops running.\n";
    }

    private:
    CPU cpu;
    RAM ram;
    CDROM cdrom;
    unsigned int storageSize;//GB
    unsigned int bandwith;//MB
};

int main()
{
    CPU cpu(CPURank::P6, 300, 2.8);
    cpu.run();
    cpu.stop();
    cout << "******************" << endl;

    RAM ram(RAMType::DDR3, 1600, 8);
    ram.run();
    ram.stop();
    cout << "******************" << endl;

    CDROM cdrom(CDROMInterfaceType::SATA, CDROMBuildType::built_in);
    cdrom.run();
    cdrom.stop();
    cout << "******************" << endl;

    //注意，这里在创建computer时，会调用两次cpu、ram、cdrom的复制构造函数。
    //用于形实结合的复制构造函数的对象会在Computer的构造函数调用结束后就调用自身的析构函数。
    //而用于初始化的复制构造函数的对象之后就变成了computer对象中的一个子对象，在computer对象调用析构函数后再调用自身的析构函数。
    Computer computer(cpu, ram, cdrom, 128, 10);
    cout << "******************" << endl;

    computer.run();
    computer.stop();
    cout << "******************" << endl;

    return 0;
}

