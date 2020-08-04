//本代码用于说明C++继承关系中的同名函数调用问题
//1、纯基类对象只能调用基类自己的成员函数（非虚函数和虚函数）
//2、纯派生类对象可以调用派生类自己的成员函数（非虚函数和虚函数）
//也可以调用基类的成员函数（非虚函数和虚函数），不过得用作用域运算符::限定
//3、父类指针指向子类对象，通过虚函数表调用派生类的虚函数，调用基类的非虚函数
//因此，基类指针要调用派生类函数就必须要有虚函数重写，这可能就是虚函数存在的意义

//添加功能：搞清楚继承中类的内存关系
//不继承虚函数，基类和派生类各执一表，毫无关联
#include <iostream>

using namespace std;

class Empty{

};

class Test {
public:
	void hello()
	{
	}
private:
	int i;
};

class Test2 {
public:
	virtual void hello()
	{
	}
};

class Test3 {
public:
	virtual void hello()
	{
	}

	virtual void world()
	{
	}
};

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

private:
	int i;
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
private:
	//int j;
};

int main()
{
	//空类占用1个字节
	cout << "sizeof(Empty): " << sizeof(Empty) << endl;
	//非虚函数不占内存
	cout << "sizeof(Test): " << sizeof(Test) << endl;
	//64位机器虚函数占用8个字节，返回一个void*
	cout << "sizeof(Test2): " << sizeof(Test2) << endl;
	//64位机器多个虚函数占用8个字节，返回一个void*
	cout << "sizeof(Test3): " << sizeof(Test3) << endl;
	//4个字节
	cout << "sizeof(int): " << sizeof(int) << endl;
	//没搞清楚为什么是16个字节???虚函数表+int，还有啥？
	cout << "sizeof(Base): " << sizeof(Base) << endl;
	//不继承虚函数，各执一表，毫无关联
	cout << "sizeof(Derived): " << sizeof(Derived) << endl;
	cout << endl;

	/*Base *base = new Base();
	base->setName();
	base->setValue();
	delete base;
	cout << endl;

	Base base2;
	base2.setName();
	base2.setValue();
	cout << endl;

	Derived *derived = new Derived();
	derived->setName();
	derived->setValue();
	delete derived;
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
	delete base3;
	cout << endl;*/

	system("pause");
	return 0;
}