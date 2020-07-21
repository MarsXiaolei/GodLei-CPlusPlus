//c++友元类
//Rectangle是Point的友元类
//Rectangle的所有成员函数是Point的友元函数
//Rectangle的成员函数可以访问Point的私有和保护成员
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
