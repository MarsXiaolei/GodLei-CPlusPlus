#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>

using namespace std;

/*
实现功能：
有5名选手ABCDE,10个评委分别对每一个选手打分，去除最高分，去除最低分，取平均分
使用vector和deque容器
*/

class Player 
{
public:
	Player(string nmae,int score)
	{
		this->m_Name= nmae;
		this->m_Score= score;
	}

	string m_Name;
	int m_Score;
};

void createPlayer(vector<Player> &vec)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5;i++)
	{
		string name = "选手";
		name += nameSeed[i]; 

		int score = 0;
		Player p(name,score); 
		vec.push_back(p);
	}
}

void setScore(vector<Player> &vec)
{
	for (vector<Player>::iterator it = vec.begin(); it != vec.end();it++)
	{
		deque<int> d;
		for (int i = 0; i < 10;i++)
		{
			int score = rand() % 41 + 60;//60-100
			d.push_back(score);
		}
		cout << "选手：" << it->m_Name << "的打分情况：" << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end();dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;
		//排序
		sort(d.begin(),d.end());

		//去除最高分和最低分
		d.pop_back();
		d.pop_front();

		//获取总分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}

		//获取平均分
		int average = static_cast<int>(sum / d.size());
		it->m_Score = average;
	}
}

void showScore(vector<Player> &vec)
{
	for (vector<Player>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << "姓名：" << it->m_Name << "平均分数：" << it->m_Score << endl;
	}
}

int main()
{
	//设置随机数种子
	srand((unsigned int)time(NULL));

	//1、存放选手容器
	vector<Player> player;

	//2、创建5名选手
	createPlayer(player);

	//3、打分
	setScore(player);

	//显示得分
	showScore(player);

	//测试
	for (vector<Player>::iterator it = player.begin(); it != player.end();it++)
	{
		cout << "姓名：" << it->m_Name
			<<"	"
			<< "分数：" << it->m_Score << endl;
	}

	system("pause");
	return 0;
}