#include <iostream>

using namespace std;

int num = 10;

void test()
{
	int num = 20;
	cout << "局部num值：" << num << endl;
	cout << "全局num值：" << ::num << endl;
}

int main()
{
	test();
	cin.get();
	return 0;
}