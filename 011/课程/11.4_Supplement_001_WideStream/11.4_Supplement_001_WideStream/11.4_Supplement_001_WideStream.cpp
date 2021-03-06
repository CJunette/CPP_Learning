﻿// 11.4_Supplement_001_WideStream.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale>

using namespace std;

int main()
{    
    string s = "这是一个中文字符串";
    //1.注意，由于s本身容器的大小和s中存储的数据数量并不相同，因此不能用sizeof(s)，那样会显示capacity；必须要用s.size()才能正常显示数据大小。
    //1.每个中文字符其实都是有两个char字符组成的。
    //1.因此s.size()输出的大小应该是字数9乘以2,18。
    cout << s.size() << endl;
    //2.substr()用于获取某字符串的子串。从第一个参数开始，取第二个参数的长度。
    //2.这里输出的结果是汉字“且”。因为汉字是由两个char组成的，下面的取子串实际上是从字符串的第四个字符开始，取两个字符。也就是说，取的是“是”的第二个字符和“一”的第一个字符。
    //2.这两个字符组合起来，就得到了汉字“且”。
    cout << s.substr(3, 2) << endl;
    //3.这样的简单拼合两个char组成汉字的做法就造成了问题，当我想在字符串中寻找“且”时，从我们的视角看明明没有“且”字，但由于字符串的检索以char为单位，所以就找到了我们之前看到的拼合而成的“且”。
    //3.这并不是我们希望的搜索结果。
    cout << s.find("且") << endl;
    cout << endl;

    //4.因此，宽字符、宽字符串、宽流就被引入了。
    //4.定义宽字符或宽字符串时，同样使用单引号或双引号，但要在前面加大写的“L”。
    wchar_t c = L'人';
    wstring ws = L"这是一个中文字符串";
    //4.此时，字符串的长度不再是字数乘以二，而就是字数本身。
    cout << ws.size() << endl;

    //5.宽字符的输出不能依靠cout，结果会与预期不符。
    cout << c << endl;
    //5.如果试图用cout去输出string，则会直接报错。原因在于，宽字符和宽字符串需要用宽流对象来处理。
    /*
    cout << ws << endl;
    */
    //6.在使用宽流对象wcout前，必须先确定输出文件上的字节与宽字符之间的映射关系，这个关系是靠编码方案来确定的。因此必须先用imbue()进行编码方案设置。imbue()需要一个locale类型的对象。
    //6.构造locale类型的对象需要提供一个字符串表示所需的本地化配置方案，最简单的表示方法是一个“.”，加上一个表示字符编码方案的编号（又叫代码页）。
    //6.汉字编码方案GDK的代码也是936，因此下面构造locale对象时就是写“.936”。
    locale loc(".936");
    wcout.imbue(loc);
    //6.设置完编码方案后，就可以像“cout”一样正常的用插入运算符进行输出了。
    //6.宽流和普通流的类的名称是通过对相同模板的不同参数下的实例定义别名得到的。
    //6.因此宽流和普通流在功能上是完全相似的。
    wcout << c << endl;
    wcout << ws << endl;
}