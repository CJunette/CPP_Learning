// 11.3_InputStream_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//例11-9，从文件读一个二进制记录到结构体中。

#include <iostream>
#include <fstream>
using namespace std;

struct SalaryInfo
{
    unsigned id;
    double salary;
};

int main()
{
    //写入的过程之前已经讲过。
    SalaryInfo employee1 = { 600001, 8000 };
    ofstream os("payroll", ios_base::out | ios_base::binary);
    os.write(reinterpret_cast<char *>(&employee1), sizeof(employee1));
    os.close();

    ifstream is("payroll", ios_base::out | ios_base::binary);
    //如果is不为空，则说明文件的打开成功。
    //根据书上p490，这里的“if(is)”实际上等价于“if(!is.fail())”，但意义上就是判断is是否成功打开了关联的文件。
    if(is)
    {
        SalaryInfo employee2;
        //用read()函数读取数据。read()第一个参数是char *类型的，指的是存储读取到的数据的位置，要求类型为char *；第二个参数为读取数据的大小。
        //这里我写的时候，错误的写成了“is.read(reinterpret_cast<char *>(&employee2), ios_base::binary);”，但也成功输出了。似乎ios_base::binary也有默认的数值。
        is.read(reinterpret_cast<char *>(&employee2), sizeof(employee2));
        cout << employee2.id << ": " << employee2.salary << endl;
    }
    else
    {
        cout << "Error: can't open file!" << endl;
    }    
}