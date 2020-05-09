// 6_Experiment_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Employee
{
    public:
    Employee(string name, string street, string city, string code):
        name(name), street(street), city(city), code(code)
    {}
    Employee():
        Employee("null", "null", "null", 000000)
    {}
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Street: " << street << endl;
        cout << "City: " << city << endl;
        cout << "Code: " << code << endl;
        cout << endl;
    }
    void change_name(string newName)
    {
        name = newName;
    }

    private:
    string name, street, city, code;    
};



int main()
{
    Employee detective("John Watson", "221B_Baker_Street", "London", "221221");
    detective.display();
    detective.change_name("Sherlock Holmes");
    detective.display();

    Employee childDetectiveParty[5] = {
        Employee("江户川柯南", "帝丹小学1年A班", "米花市", "000001"),
        Employee("灰原哀", "帝丹小学1年A班", "米花市", "000002"),
        Employee("吉田步美", "帝丹小学1年A班", "米花市", "000003"),
        Employee("圆谷光彦", "帝丹小学1年A班", "米花市", "000004"),
        Employee("小岛元太", "帝丹小学1年A班", "米花市", "000005"),
    };
    for (Employee e: childDetectiveParty)
    {
        e.display();
    }
}
