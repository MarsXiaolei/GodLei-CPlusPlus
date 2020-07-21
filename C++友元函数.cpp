//C++友元函数的使用（全局函数）
//1、一个友元函数对应一个类
//2、一个友元函数对应多个类，需要类前置声明
//3、友元函数可以通过对象访问类的所有成员变量
//4、类内声明，类外定义，不属于类，就是一普通函数
//5、声明时需要在函数名称前加上关键字friend
//6、好处：提高了程序的运行效率（减少了类型检查和安全性检查的时间开销）
//7、缺点：破坏了类的封装性和隐藏性（访问私有成员）


#include <iostream>

using namespace std;

class Circle;//类前置声明

class Rectangle
{
public:
	Rectangle():width(2.0), height(5.5)
	{
	}
	~Rectangle()
	{
	}
	friend float getArea(Rectangle &r);
	friend float getSumArea(Rectangle &r,Circle &c);
	
private:
	float width;
	float height;
};

class Circle
{
public:
	Circle() :center_x(2.0), center_y(5.5), radius(3)
	{
	}
	~Circle()
	{
	}
	friend float getArea(Circle &r);
	friend float getSumArea(Rectangle &r, Circle &c);

private:
	float center_x;
	float center_y;
	float radius;
};

//获取矩形的面积
float getArea(Rectangle &r)
{
	double area=r.width*r.height; 
	return area;
}

//获取圆的面积
float getArea(Circle &c)
{
	double area = 3.14*c.radius*c.radius;
	return area;
}

//获取矩形和圆的面积和
float getSumArea(Rectangle &r, Circle &c)
{
	float sum = r.width*r.height + c.radius*c.radius*3.14;
	return sum;
}

int main()
{
	Rectangle rectangle;
	Circle circle;
	float rectangle_area = getArea(rectangle);
	float circle_area = getArea(circle);
	cout << "rectangle_area: " << rectangle_area << endl;
	cout << "circle_area: " << circle_area << endl;
	float sum = getSumArea(rectangle, circle);
	cout << "sum: " << sum << endl;
	system("pause");
	return 0;
}