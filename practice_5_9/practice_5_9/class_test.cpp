#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"Circle.h"
#include"Point.h"
using namespace std;




void isIncircle(Circle &c, Point &p)
{
	//计算两点之间距离的平方
	int distance =
		(c.get_Center().get_x() - p.get_x())*(c.get_Center().get_x() - p.get_x()) +
		(c.get_Center().get_y() - p.get_y())*(c.get_Center().get_y() - p.get_y());
	//计算半径的平方
	int r_distance = c.get_m_R()*c.get_m_R();
	if (distance == r_distance)
	{
		cout << "点在圆上！" << endl;
	}
	else if (distance > r_distance)
	{
		cout << "点在圆外！" << endl;
	}
	else
	{
		cout << "点在圆内！" << endl;
	}

}

int main()
{
	//设计一个圆类 和一个点类 计算⚪和点的关系
	//创建一个圆
	Circle c1;
	c1.set_m_R(10);
	Point center;
	center.set_x(10);
	center.set_y(0);
	c1.set_m_Center(center);

	//创建一个点
	Point p2;
	p2.set_x(20);
	p2.set_y(1);
	isIncircle(c1 ,p2);



}
