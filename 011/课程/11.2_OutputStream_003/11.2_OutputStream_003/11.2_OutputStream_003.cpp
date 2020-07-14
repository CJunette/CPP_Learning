// 11.2_OutputStream_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//例11-5，向二进制文件输出。

#include <iostream>
#include <fstream>
using namespace std;

struct Date
{
    int mon, day, year;
};

int main()
{
    Date dt = { 6, 10, 92 };
    //直接写"date.dat"，表示这个文件（会被创建）在当前的文件目录下。如果加上了磁盘目录，则会去打开对应目录下的文件。
    //二进制输出除了可以提高输入和输出的效率（省去了进制转化的时间），还可以避免不必要的文本转换。
    //如书上p490提到的，如果以一般文本格式输出，dt中的10会被认为是换行符“\n”（Ascii第10个），由于windows下会给每个换行符在配置一个回车符“\r”（Ascii第13个），因此输出时会变成10 13。
    //而如果使用二进制进行输出，就不会对字符进行转换。
    ofstream file("date.dat", ios_base::binary);    
    //write()函数的第一个参数是一个char *（因为是以文本形式输出的），要求它指向需要输出的对象的首地址，由于需要输出的对象不是char类型的，因此要用reinterpret_cast()进行强制类型转换；
    //第二个参数是需要输出的对象的大小。
    file.write(reinterpret_cast<char *>(&dt), sizeof(dt));
    //这里我担心之前提到的reinterpret_cast()会导致数据读取方式出错的问题，所以还特地尝试用static_cast去进行类型的转换。
    //但是仔细想一想，在二进制模式下输出的都是二进制数据，也就不存在读取方式的问题了。
    /*
    file.write(static_cast<char *>(static_cast<void *>(&dt)), sizeof(dt));
    */ 
    //补充一句，在使用write()函数实现写入时，需要调用成员函数实现对流对象格式的设置（因为没有“<<”用来适配setiosflags()）。
    /*
    file.setf(ios_base::left);
    */    
    file.close();
}