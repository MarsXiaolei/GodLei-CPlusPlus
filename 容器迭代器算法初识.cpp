#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void print(int val)
{
	cout << val << endl;
}

void test_1()
{
	int arr[5] = {1,2,3,4,5};
	int *p = arr;
	for (int i = 0; i < 5;i++)
	{
		cout << *(p++) << endl;
	}
}

void test_2()
{
	vector<int> v;
	//添加数据
	v.push_back(10);
	v.push_back(20);
	//通过迭代器遍历容器
	for (vector<int>::iterator it = v.begin(); it < v.end();it++)
	{
		cout <<*it << endl;
	}

	for_each(v.begin(), v.end(),print);
}

class Person
{
public:
	Person(string name,int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};

void test_3()
{
	vector<Person> person; 
	Person p1("张三",18);
	Person p2("李四", 23);
	person.push_back(p1);
	person.push_back(p2);
	for (vector<Person>::iterator it = person.begin(); it < person.end();it++)
	{
		//*it Person类型 it 指针
		cout << "m_name: " << (*it).m_name << " m_age: " << it->m_age << endl;
	}
}

void test_5()
{
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;

	for (int i = 1; i <=10;i++)
	{
		v1.push_back(i);
		v2.push_back(i+10);
	}

	//将小容器插入到大容器中
	v.push_back(v1);
	v.push_back(v2);

	for (vector<vector<int>>::iterator it=v.begin(); it < v.end(); it++)
	{
		//*it vector<int>
		for (vector<int>::iterator it2 = (*it).begin(); it2 < (*it).end();it2++)
		{
			//*it2 int
			cout <<*it2 << endl;
		}
	}

	for (int i = 0; i < v.size();i++)
	{
		for (int j = 0; j < v.at(i).size();j++)
		{
			cout << v.at(i).at(j) << endl;
		}
	}
}

void test_4()
{
	vector<Person *> person;
	Person p1("王二", 18);
	Person p2("龙五", 23);
	person.push_back(&p1);
	person.push_back(&p2);
	for (vector<Person *>::iterator it = person.begin(); it < person.end(); it++)
	{
		//*it Person*类型
		cout << "m_name: " << (*it)->m_name << " m_age: " << (*it)->m_age << endl;
	}
}

int main()
{
	test_1();
	test_2();
	test_3();
	test_4();
	test_5();
	cin.get();
	return 0;
}