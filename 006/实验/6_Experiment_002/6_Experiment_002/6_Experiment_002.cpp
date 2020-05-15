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
        Employee("null", "null", "null", "000000")
    {}
    ~Employee()
    {
        cout << "Destructor" << endl;
    }
    void display() const
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
    //这部分不重要。
    Employee detective("John Watson", "221B_Baker_Street", "London", "221221");
    detective.display();
    detective.change_name("Sherlock Holmes");
    detective.display();

    Employee childDetectiveParty[5] = {
        Employee("江户川柯南", "帝丹小学1年A班", "米花市", "000001"),
        Employee("灰原哀", "帝丹小学1年A班", "米花市", "000002"),
        Employee("吉田步美", "帝丹小学1年A班", "米花市", "000003"),
        Employee("圆谷光彦", "帝丹小学1年A班", "米花市", "000004"),
        Employee("小岛元太", "帝丹小学1年A班", "米花市", "000005")
    };
    for (Employee const &e: childDetectiveParty)
    {
        e.display();
    }    
    
    //另一种创建Employee数组的方式。
    //此时用类的指针数组的方式对动态对象的地址进行储存，然后在最后用循环逐一对动态对象进行删除。
    Employee *eply, *childDetectiveParty2[5];

    eply = new Employee("江户川柯南", "帝丹小学1年A班", "米花市", "000001");
    childDetectiveParty2[0] = eply;

    eply = new Employee("灰原哀", "帝丹小学1年A班", "米花市", "000002");
    childDetectiveParty2[1] = eply;

    eply = new Employee("吉田步美", "帝丹小学1年A班", "米花市", "000003");
    childDetectiveParty2[2] = eply;

    eply = new Employee("圆谷光彦", "帝丹小学1年A班", "米花市", "000004");
    childDetectiveParty2[3] = eply;

    eply = new Employee("小岛元太", "帝丹小学1年A班", "米花市", "000005");
    childDetectiveParty2[4] = eply;
    //注意，此时进行删除的方式必须用循环遍历整个数组，然后逐一删除。
    for (int i = 0; i < 5; i++)
    {
        delete childDetectiveParty2[i];
    }
    
    //另一种创建Employee数组的方式。
    //此时用类的数组来储存动态对象经过复制构造函数创建的副本，然后在完成复制后立刻删除动态对象。
    Employee *eply, childDetectiveParty3[5];

    eply = new Employee("江户川柯南", "帝丹小学1年A班", "米花市", "000001");
    childDetectiveParty3[0] = *eply;
    delete eply;

    eply = new Employee("灰原哀", "帝丹小学1年A班", "米花市", "000002");
    childDetectiveParty3[1] = *eply;
    delete eply;

    eply = new Employee("吉田步美", "帝丹小学1年A班", "米花市", "000003");
    childDetectiveParty3[2] = *eply;
    delete eply;

    eply = new Employee("圆谷光彦", "帝丹小学1年A班", "米花市", "000004");
    childDetectiveParty3[3] = *eply;
    delete eply;

    eply = new Employee("小岛元太", "帝丹小学1年A班", "米花市", "000005");
    childDetectiveParty3[4] = *eply;
    delete eply;
}
