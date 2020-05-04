#include "head.h"
using namespace Ns;

//注意，在定义这里，即是using了对应的namespace，也必须加“Ns::”，不然会被视为是重新定义了一个叫SayHello()的函数。
void Ns::SayHello()
{
	cout << "Hello" << endl;
}