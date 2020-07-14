// 11.3_InputStream_005.cpp : This file contains the 'main' function. Program execution begins and ends there.
//例11-11，读一个文件并显示出其中0元素的位置。

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int values[] = { 3, 7, 0, 5, 4 };
	ofstream os("integers", ios_base::binary);
	os.write(reinterpret_cast<char *>(values), sizeof(values));
	os.close();

    ifstream file("integers", ios_base::in | ios_base::binary);
	if(file)
	{
		//1.当读到文件尾时，file会返回0。
		while(file)
		{
			//2.利用tellg()确定当前文件指针的位置。
			streampos here = file.tellg();
			int v;
			//3.在完成读取后，似乎tellg()对应的文件指针会自动向后移动。
			file.read(reinterpret_cast<char *>(&v), sizeof(int));
			//4.这里之所以还要对file进行过一次判断，似乎是因为最后一个元素（4）后面的元素并不是文件终止符，再向后一个元素才是文件终止符。
			//4.也就是说，如果此处要寻找的是数字4（4在第16个字节），且条件仅为“if(v == 4)”，则在经历过5次循环后，指针会指向第20个字节所在的位置，由于此时file的值不为0，因此满足条件，会进行一次输出，然后再进入一次循环。
			//4.在下一次循环中，指针第24个字节，也就是文件结束位置，此时file为0。但由于第20个字节所在的位置为空，且给标识符v分配的内存每次都相同，上一次的4尚未被覆盖。
			//4.此时，虽然file的值为0，但如果判断条件仅为“if(v == 4)”，则还会再进行一次输出。
			//4.因此，必须保证判断条件为“if(file && v == 0)”，才能避免当寻找最后一个元素时，出现重复的输出。
			if(file && v == 0)
			{
				//5.这里here是会直接输出当前的文件指针所在的字节位置。由于每个元素的长度为4字节，因此要确定具体的元素位置，还要把here除以sizeof(int)。
				cout << "Position " << here / sizeof(int) << " is 0." << endl;
			}
		}
	}
	else
	{
		cout << "Error: can't open file" << endl;
	}
	file.close();
}