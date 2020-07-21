//c++友元函数
//类成员函数作为友元函数
//类的顺序不能改变，否则会出现无法访问私有变量
//此处代码会出现波浪线，但是不会报错
//xiaolei 2020/7/21

#include <iostream>

using namespace std;

class Point
{
public:
	Point(float xx,float yy)
	{
		x = xx;
		y = yy;
	}

private:
	float x, y;
	friend class Rectangle;
};

class Rectangle
{
public:
	Rectangle() {}
	~Rectangle() {}
	
	float getWidth(Point &a, Point &b)
	{
		float width = a.x - b.x;
		return width;
	}

	float getHeight(Point &a, Point &b)
	{
		float height = a.y - b.y;
		return height;
	}
	
private:
	float width;
	float height;
};

int main()
{
	Rectangle rectangle;

	Point p1(2.5,1.5), p2(3,6);
	float width = rectangle.getWidth(p1, p2);
	float height = rectangle.getHeight(p1, p2);
	cout << "width: " << width << endl;
	cout << "height: " << height << endl;

	system("pause");
	return 0;
}