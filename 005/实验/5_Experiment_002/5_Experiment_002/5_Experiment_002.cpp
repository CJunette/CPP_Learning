// 5_Experiment_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "client.h"
using namespace std;

//这里把类的静态数据成员的初始化放到了主函数。
std::string Client::ServerName = "Server_0";
int Client::ClientNum = 0;


int main()
{
    Client c1;
    c1.changeServerName("Server_1");
    cout << "Server name: " << c1.getServerName() << "\t Client number: " << c1.getClientNumber() << endl;
    Client c2;
    c2.changeServerName("Server_2");
    cout << "Server name: " << c2.getServerName() << "\t Client number: " << c2.getClientNumber() << endl;

}

