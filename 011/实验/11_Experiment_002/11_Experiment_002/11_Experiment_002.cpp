// 11_Experiment_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

//这个程序必须在命令行中用打开，并且在打开时声明第二个参数作为程序中被文件流打开的文件。
//下面的argc记录了程序执行时的输入参数个数，而argv则记录了输入参数的具体字符串。
//如果需要在程序运行时执行以notepad.exe打开example.txt的操作，就会在命令行中输入notepad.exe和example.txt。
//argv的第一个单元指向的字符串总是可执行程序的名字。因此上述操作对应的argv的第一个参数为notepad.exe，第二个参数为example.txt。
int main(int argc, char* argv[])
{
    ifstream in;
    in.open(argv[1], ios::binary);
	if(!in)
	{
		cout << "Error: Can not open file" << endl;
		return 1;
	}
	string line;
	//这里我本来想用vector<stringstream>作为存储容器的，但后来发现因为stringstream本身不具有复制构造函数，所以不能作为vector的成员。
	//而且stringsteam本身就可以算是有存储功能的，没有必要去使用vector。
	stringstream ss;
	int i = 1;
	while(in.tellg() != EOF)
	{
		getline(in, line);		
		ss << i++ << ". " << line << endl;
	}
	in.close();

	ofstream out;
	out.open(argv[1], ios::binary);	
	//下面这行代码用于将结果输出到文件。
	out << ss.str();
	//下面这行代码用于将结果输出到屏幕。
	cout << ss.str();
	out.close();
}