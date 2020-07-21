//c++友元函数
//类成员函数作为友元函数
//类的顺序不能改变，否则会出现无法访问私有变量
//此处代码会出现波浪线，但是不会报错
//xiaolei 2020/7/21

#include <iostream>

using namespace std;

class Point;

class ManagerPoint
{
public:
	ManagerPoint() {}
	~ManagerPoint() {}
	double distance(Point &a);
};

class Point
{
public:
	Point():x(1.5),y(2.5)
	{
	}
	friend double ManagerPoint::distance(Point &a);
private:
	double x, y;
};

double ManagerPoint::distance(Point &a)
{
	double sum = a.x + a.y;
	return sum;
}

int main()
{
	Point p;
	ManagerPoint mp;
	float d = mp.distance(p);
	cout << "d: " << d << endl;
	system("pause");
	return 0;
}