//本代码用于说明C++继承关系中的同名函数调用问题
//1、纯基类对象只能调用基类自己的成员函数（非虚函数和虚函数）
//2、纯派生类对象可以调用派生类自己的成员函数（非虚函数和虚函数）
//也可以调用基类的成员函数（非虚函数和虚函数），不过得用作用域运算符::限定
//3、父类指针指向子类对象，通过虚函数表调用派生类的虚函数，调用基类的非虚函数
#include <iostream>

using namespace std;

class Base 
{
public:
	virtual void setName()
	{
		cout << "调用Base setName" << endl;
	}

	void setValue()
	{
		cout << "调用Base setValue" << endl;
	}
};

class Derived:public Base
{
public:
	virtual void setName()
	{
		cout << "调用Derived setName" << endl;
	}

	void setValue()
	{
		cout << "调用Derived setValue" << endl;
	}
};

int main()
{
	Base *base = new Base();
	base->setName();
	base->setValue();
	cout << endl;

	Base base2;
	base2.setName();
	base2.setValue();
	cout << endl;

	Derived *derived = new Derived();
	derived->setName();
	derived->setValue();
	cout << endl;

	Derived derived2;
	derived2.setName();
	derived2.setValue();
	cout << endl;

	Derived derived3;
	derived3.Base::setName();
	derived3.Base::setValue();
	cout << endl;

	Base *base3 = nullptr;
	base3 = new Derived();
	base3->setName();
	base3->setValue();
	cout << endl;

	system("pause");
	return 0;
}