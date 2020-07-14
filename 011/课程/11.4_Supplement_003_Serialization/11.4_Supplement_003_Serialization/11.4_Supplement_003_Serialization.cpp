// 11.4_Supplement_003_Serialization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//这边简单按照书本p507-509的提示，尝试一下使用bosst中的Serialization库对一般类进行序列化。

#include <iostream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <fstream>
using namespace std;

struct TaxInfo
{
    TaxInfo(double tax = 200):
        totalTax(tax)
    {}
    double totalTax;
    void save(ostream &out);
    void load(istream &in);

    template<class Archive>
    void serialize(Archive &ar, unsigned int version);
};
//2.2.由于这里我把TaxInfo类构造的比较简单，因此这里的save()和load()函数也就比较简单了。
void TaxInfo::save(ostream &out)
{
    out << totalTax;
}
void TaxInfo::load(istream &in)
{
    in >> totalTax;
}
template<class Archive>
void TaxInfo::serialize(Archive &ar, unsigned int version)
{
    ar &totalTax;
}

//1.将对象写入文件的操作叫做串行化。
//1.通常情况下，当一个类体中存在指针作为成员时，直接用write()进行串行化是会造成错误的。因为存储到文件中的只是指针中的地址，而非指针所指向的对象。因此想要读取文件时，那部分对象是无法恢复的。
struct SalaryInfo
{
    SalaryInfo(string n = "Jack", double  s = 10000, double t = 200):
        name(n), salary(s)
    {
        tax = new TaxInfo(t);
    }
    ~SalaryInfo()
    {
        delete tax;
    }
    string name;
    double salary;
    TaxInfo *tax;
    //2.1.此时会在类体中创建save()和load()函数，自定义向外输出和向内读取的过程。
    void save(ostream &out);
    void load(istream &in);

    //3.然而2.中提到的做法要在save()和load()两个函数中重复类似的算法，显得太过繁琐。
    //3.1.因此，另一种更方便的做法是利用Boost中的Serialization，来实现快捷的读取。
    //3.1.这个做法要求在需要被存取的类中（及其中的类成员对应的类中）定义一个名为serialize的类模板函数。
    //3.1.serialize()函数会在串行化或恢复时被Serialization库自行调用。
    template<class Archive>
    void serialize(Archive &ar, unsigned int version);
};
void SalaryInfo::save(ostream &out)
{
    out << salary << ' ';
    //2.2.这里存入一个用于确定tax是否指向空的布尔值。只有当tax不指向空时，才将tax存入。
    out << (tax != 0);
    if(tax)
    {
        //2.2.由于tax本身也是一个类，因此在tax再定义一个save()，用于确定tax的存储。
        tax->save(out);
    }
    //2.3.因为name中可能存在空格，所以读取时可能会用到getline()，因此将name放到最后在存入，同时在存入完成后再加一个“endl”。
    out << name << endl;
}
void SalaryInfo::load(istream &in)
{
    bool iftax;
    in >> salary >> iftax;
    //2.2.根据之前存入的布尔值判断读取时是否有tax的对象需要读取。
    if(iftax)
    {
        if(tax == 0)
        {
            tax = new TaxInfo();
        }
        tax->load(in);
    }
    else
    {
        delete tax;
        tax = 0;
    }
    getline(in, name);
}
template<class Archive>
void SalaryInfo::serialize(Archive &ar, unsigned int version)
{
    //3.2.“&”操作符是在Serialization库中定义的操作符，用于指定输出和输入时的顺序。
    //3.3.在Serialization库中，对指针的串行化会保存指针所指向的对象的内容。在恢复时，会创建新对象，恢复对象内容，并将指针指向这个对象。
    ar &salary &tax &name;
}


int main()
{    
    //2.4.在类内自定义save()和load()函数的具体使用。
    {
        SalaryInfo s1;
        ofstream os("Salary1.txt");
        s1.save(os);
        SalaryInfo s2;
        os.close();
        ifstream is("Salary1.txt");
        s2.load(is);
        cout << s2.name << " " << s2.salary << " " << s2.tax->totalTax << endl << endl;
        is.close();
    }
    
    {
        SalaryInfo s1;
        ofstream os("Salary2.txt");
        //3.4.串行化时，实际执行的是Serialization库中定义的文档类（具体可以参考书上p509）。
        //3.4.这里使用的是text_oarchive和text_iarchive，也就是以普通字符文本的形式进行保存。
        //3.4.构造串行化对象时，需要以一个打开了文档的fstream对象为参数。
        boost::archive::text_oarchive oa(os);
        //3.4.输出和读取时，还是可以用插入“<<”和提取“>>”运算符进行实现。
        oa << s1;
        os.close();
        SalaryInfo s2;
        ifstream is("Salary2.txt");
        boost::archive::text_iarchive ia(is);
        ia >> s2;
        cout << s2.name << " " << s2.salary << " " << s2.tax->totalTax << endl << endl;
        is.close();
    }
}
